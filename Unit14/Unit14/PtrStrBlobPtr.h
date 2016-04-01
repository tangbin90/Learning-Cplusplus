#include "StrVec.h"
#include "Blob.h"

class PtrStrBlobPtr
{
public:
	PtrStrBlobPtr(StrBlobPtr* p) :ptr(p){}
	StrBlobPtr& operator*();
	StrBlobPtr* operator->();
private:
	StrBlobPtr* ptr;
};

inline StrBlobPtr& PtrStrBlobPtr::operator*()
{
	return *ptr;
}

inline StrBlobPtr* PtrStrBlobPtr::operator->()
{
	return &this->operator*();
}
