#ifndef PTRSTRBLOBPTR_H
#define PTRSTRBLOBPTR_H
#include "StrVec.h"
#include "Blob.h"

class PtrStrBlobPtr
{
public:
	PtrStrBlobPtr(StrBlobPtr* p) :ptr(p){}
	PtrStrBlobPtr() = default;
	StrBlobPtr& operator*();
	StrBlobPtr* operator->();
private:
	StrBlobPtr* ptr=nullptr;
};

inline StrBlobPtr& PtrStrBlobPtr::operator*()
{
	return *ptr;
}

inline StrBlobPtr* PtrStrBlobPtr::operator->()
{
	return &this->operator*();
}

#endif