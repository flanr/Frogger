#include "constvar.h"
#include <stdio.h>
#include <cstring>
#include <string.h>
#define log printf
// Set the name of a cvarElement 
bool cvarElement::setName(char* newName, esize nameLength){
	if(name != NULL)delete[] name;
	name = new char[nameLength+1];
	memset(name, 0, nameLength+1);
	
	memcpy(name, newName, nameLength);
	
	nameSize = nameLength;
	return true;
}


//set the value of a cvarElement
bool cvarElement::setContent(char* content, esize contentSize){
	dataSize = contentSize;
	data.clearBuffers();
	data.add((int)contentSize, content);
	return true;
}


//add data to an existing cvarElement
bool cvarElement::appendData(char* content, esize contentSize){
	dataSize += contentSize;
	data.add(contentSize, content);
	data.optimize();
	return true;
}


//Initializer
cvarElement::cvarElement(uint32_t unID){
	//log("Initializing cvarElement.");
	ID = unID;
	nameSize = 0;
	name = NULL;
	
	dataSize = 0;
	data.clearBuffers();
	
	type = 0;
	
	save = false;
	return;
}


//De-initializer
cvarElement::~cvarElement(){
	//log("Uninitializing cvarElement.");
	ID = 0;
	nameSize = 0;
	
	if(name)delete[] name;
	name = NULL;
	
	dataSize = 0;
	data.clearBuffers();
	
	type = 0;
	
	save = false;
	return;
}


char* cvarElement::getData(){
	return data.genBuffer();
}











/*
	cvarList
*/


cvarList::cvarList(){
	log("Initializing cvarList");
	listName = NULL;
	status = 0;
	cID = 0;
}


cvarList::cvarList(char* fileName){
	printf("Initializing cvarList with filename: '%s'.", fileName);
	listName = new char[strlen(fileName)+1];
	memcpy(listName, fileName, strlen(fileName));
	listName[strlen(fileName)] = '\0'; // Trailing \0
	status = 0;
	cID = 0;
	
}


cvarList::~cvarList(){
	//log("De-Initializing cvarList");
	save();
	//Save
	if(listName)delete[] listName;
	listName = NULL;
	
	
	empty();
}


cvarElement* cvarList::get(char* name){
	lock();
	for(Iter = elements.begin(); Iter != elements.end(); Iter++){
		if(!strcmp(name, (*Iter)->name)){
			//log("Found element :)");
			unlock();
			return (*Iter);
		}
	}
	unlock();
	//log(3, "Element searched for: Not found(", navn, ")");
	return NULL;
}


cvarElement* cvarList::set(char* name, char* content, esize contentSize){
	cvarElement* temp = 0;
	
	if((temp = get(name)) == NULL){
		temp = new cvarElement(cID++);
		temp->setName(name, strlen(name));
		lock();
		elements.push_back(temp);
		unlock();
		//log("Element Added!");
	}
	lock();
	temp->setContent(content, contentSize);
	unlock();
	return temp;
}


cvarElement* cvarList::append(char* name, char* content, esize contentSize){
	cvarElement* temp = 0;
	
	
	if((temp = get(name)) == NULL){
		cvarElement* temp = new cvarElement(cID++);
		temp->setName(name, strlen(name)+1);
		lock();
		elements.push_back(temp);
		unlock();
	}
	lock();
	temp->appendData(content, contentSize);
	unlock();
	return temp;
}


void cvarList::lock(){
	//log("Locking...");
	//pthread_mutex_lock(&ownMutex);
	//log("Mutex Locked!");
}

void cvarList::unlock(){
	//log("Unlocking...");
	//pthread_mutex_unlock(&ownMutex);
	//log("Mutex Unlocked!");
}



bool cvarList::save(){
	//log("Saving...");
	lock();
	//First check if we have listName
	if(!listName){
		log("cvarList::save:Error No filename specified");
		unlock();
		return false;
	}
	
	//Rename current file to .backup
	char newname[256] = "";
	_snprintf(newname, 255, "%s.backup", listName);
	
	if(remove(newname) != 0){
		perror("cvarList::save:remove_old_backup:Warning ");
		log("cvarList::save(remove) failed. Trying to continue with saving process...");
	}
	
	if(rename(listName, newname) != 0){
		perror("cvarList::save:rename:Warning ");
		log("cvarList::save(rename) failed. Trying to continue with saving process...");
	}
	
	
	FILE* savefile = NULL;
	
	savefile = fopen(listName, "wb");
	
	if(!savefile){
		perror("cvarList::save:save:ERROR ");
		log("cvarList::save(fopen) failed. Maybe no access.");
		unlock();
		return false;
	}
	
	/*
		Protocol definition:
			1 Byte declaring version (0x01 is current)
			Elements:
				sizeof(esize) Bytes: size_of_name 
				name
				sizeof(esize) Bytes size_of_content
				content
	*/
	
	//Protocol version
	fputc(1, savefile);
	for(Iter = elements.begin(); Iter != elements.end(); Iter++){
		
		//Write size of name
		fwrite(&(*Iter)->nameSize, sizeof((*Iter)->nameSize), 1, savefile);
		
		//Write name
		fwrite((*Iter)->name, 1, (*Iter)->nameSize, savefile);
		
		//Write data size
		fwrite(&(*Iter)->dataSize, sizeof((*Iter)->dataSize), 1, savefile);
		
		//Write data
		fwrite((*Iter)->data.genBuffer(), 1, (*Iter)->dataSize, savefile);
	}
	fflush(savefile);
	fclose(savefile);
	
	unlock();
	return true;
}


bool cvarList::load(){
	empty();
	lock();
	if(!listName){
		log("cvarList::load:Error No filename specified");
		unlock();
		return false;
	}
	
	printf("Loading file: %s", listName);
	
	FILE* loadfile = NULL;
	loadfile = fopen(listName, "rb");
	
	if(!loadfile){
		perror("cvarList::load:load:ERROR ");
		log("cvarList::load(fopen) failed. Maybe no access.");
		unlock();
		return false;
	}
	
	
	int versionByte = 0;
	
	if((versionByte = fgetc(loadfile)) != 1){
		printf("VERSION_MISMATCH: 0x%x", versionByte);
		log("cvarList::load:Error Wrong protocol version!");
		fclose(loadfile);
		unlock();
		return false;
	}
	
	while(!feof(loadfile)){
		int retValue = 0;
		cvarElement* temp = new cvarElement(cID++);
		
		//Read and store namesize
		retValue = fread(&temp->nameSize, sizeof(temp->nameSize), 1, loadfile);
		
		if(retValue == 0 || feof(loadfile)){
			delete temp;
			unlock();
			fclose(loadfile);
			return true;
		}
		
		//Read and store name
		temp->name = new char[(temp->nameSize) +1];
		memset(temp->name, 0, (temp->nameSize) +1);
		fread(temp->name, 1, temp->nameSize, loadfile);
		
		//Read and store dataSize
		fread(&temp->dataSize, sizeof(temp->dataSize), 1, loadfile);
		
		//Read data
		char* tempBuffer = new char[(temp->dataSize)+1];
		fread(tempBuffer, 1, temp->dataSize, loadfile);
		
		//Store data
		temp->setContent(tempBuffer, temp->dataSize);
		
		
		elements.push_back(temp);
		
		//Clean up memory
		delete[] tempBuffer;
		
	}
	unlock();
	fclose(loadfile);
	return true;
}


void cvarList::empty(){
	Iter = elements.begin();
	cvarElement* temp;
	while(Iter != elements.end()){
		temp = *Iter;
		Iter++;
		delete temp;
		elements.remove(temp);
	}
}



