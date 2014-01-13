
//bufferex.cpp

/*
	Implimentation of the bufferex class by Hellbinder aka Trippler
	If you use this library it would be nice if you give credit to me.
	
*/

#ifndef bufferex_cpp
#define bufferex_cpp

#include <string.h>
#include "bufferex.h"

bufferElement::bufferElement(int64_t setSize){
	buffer = new char[setSize];
	size = setSize;
	memset(buffer, 0, setSize);
	next = NULL;
}

bufferElement::~bufferElement(){
	bufferElement::size = 0;
	if(buffer != NULL)delete[] buffer;
	if(next){
		delete next;
	}
}



bufferex::bufferex(){
	size = 0;
	first = 0;
	last = 0;
	pszMainBuffer = 0;
}

void bufferex::add(int64_t contentSize, char* content){
	bufferElement* pNewBuffer = new bufferElement(contentSize);
	memcpy(pNewBuffer->buffer, content, contentSize);
	
	pNewBuffer->size = contentSize;
	size += contentSize;
	
	if(first == 0)first = pNewBuffer;
	if(last != 0)last->next = pNewBuffer;
	last = pNewBuffer;
}

char* bufferex::genBuffer(){
	if(pszMainBuffer != 0)delete[] pszMainBuffer;
	if(size <= 0)return 0;
	
	pszMainBuffer = new char[size+1];
	memset(pszMainBuffer, 0, size+1);
	
	char* currentPos = pszMainBuffer;
	bufferElement* current = first;
	if(!current)return 0;
	
	
	do{
		memcpy(currentPos, current->buffer, current->size);
		currentPos += current->size;
	}while((current = current->next) != NULL);
	
	return pszMainBuffer;
}


void bufferex::clearBuffers(){
	if(first != NULL){
		delete first;
	}
	first = NULL;
	last = NULL;
	if(pszMainBuffer != 0)delete[] pszMainBuffer;
	pszMainBuffer = 0;
	size = 0;
}

bufferex::~bufferex(){
	clearBuffers();
}

void bufferex::optimize(){
	
	int sizeHolder = size;
	char* optBuf = new char[sizeHolder];
	memset(optBuf, 0, sizeHolder);
	
	memcpy(optBuf, genBuffer(), sizeHolder);
	clearBuffers();
	
	add(sizeHolder, optBuf);
	delete[] optBuf;
	
	return;
	
}

#endif
