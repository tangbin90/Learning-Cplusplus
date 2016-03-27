#ifndef HASPTR_H
#define HASPTR_H
#include <string>

class HasPtr
{
friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0), use(new size_t(1)){}
	HasPtr(const HasPtr& hsptr)
	{
		this->i = hsptr.i;
		this->ps = hsptr.ps;
		++*hsptr.use;
		use = hsptr.use;
	}
	HasPtr(HasPtr &&p) _NOEXCEPT: ps(p.ps), i(p.i){p.ps = 0; }
	HasPtr& operator =(HasPtr&& rhs)_NOEXCEPT;
	HasPtr& operator = (HasPtr rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	size_t *use;

};

#endif