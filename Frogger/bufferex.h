//bufferex.h

#include <stdint.h>
#pragma once


/*
	Header of the bufferex class by Hellbinder aka Trippler
	You may use or change this library in any way, but may not change this comment.
	If you use this library it would be nice if you give credit to me.
//*/
//
//#ifndef bufferex_h
//#define bufferex_h

class bufferElement{
	public:
		char* buffer;
		int64_t size;
		bufferElement* next;
		bufferElement(int64_t);
		~bufferElement();
};

class bufferex{
	public:
		int64_t size;
		bufferElement* first;
		bufferElement* last;
		void add(int64_t, char*);
		bufferex();
		~bufferex();
		char* pszMainBuffer;
		char* genBuffer();
		void clearBuffers();
		void optimize();
};



//#endif 

