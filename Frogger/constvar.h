//constvar.h

#include "bufferex.h"
#include <list>
#pragma once
using std::list;

//Type used to hold sizes of elements. This needs to be able to contain more then max size of an element or a buffer overflow occurs
typedef int64_t esize;

class cvarElement{
	public:
		uint32_t ID; //element id (like 0, 1, 2, 3...)
		
		esize nameSize;	//Length of name
		char* name;			//name
		
		esize dataSize;	//size, using int64_t to support >4G of data (is size_t 64-bit?)
		bufferex data;
		char* getData();
		int32_t type;		//type, some enum to be added later
		
		bool save;		//Should this element be saved?
		
		
		cvarElement(uint32_t unID);		//init
		~cvarElement();		//deinit
		bool setName(char* name, esize nameLength);		//Set name for element
		bool setContent(char* content, esize contentSize);	//Set data for element
		bool appendData(char* content, esize contentSize);	//Add data to end of element
		
};


/*
	Saving asyncron
*/
class cvarList{
	public:																		//Temporarily make all public

		list <cvarElement*> elements;
		list <cvarElement*>::iterator Iter;
		
		char* listName; //Used to store variables
		int status; 	//Status of last command sent to class; 0 = no error
		int cID;
		
		cvarList();
		cvarList(char* fileName);
		~cvarList();
		
		//Mutexes to lock and unlock access
		void lock();
		void unlock();
		
		
		cvarElement* get(char* name);											//Search for a variable, if not found returns NULL
																				//+Locks
		cvarElement* set(char* name, char* content, esize contentSize);			//This will add a variable unless it allready exists
		cvarElement* append(char* name, char* content, esize contentSize);		//This will also add a variable unless exists; but will not empty content if it does exist.
		bool save();															//Save variables to file
		bool load();															//Re-load file (Note this will delete all variables and reload the ones in the file)
		
		void empty();
};


