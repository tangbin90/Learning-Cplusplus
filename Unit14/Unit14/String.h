#ifndef STRING_H
#define STRING_H

#include <memory>
#include <string>
#include <iostream>
class String
{
	friend std::ostream& operator<<(std::ostream& out, String& str);
	friend bool operator!=(String&, String&);
	friend bool operator==(String&, String&);
public:
	String() :String(""){}
	String(const char*);
	String(const String& str);//复制构造函数一定要声明const
	String(String&& str) _NOEXCEPT;
	String& operator=(String&);
	String& operator=(String&&)_NOEXCEPT;
	size_t size()const { return firstfree - elements; }
	size_t capacity()const { return cap - elements; }
	char* begin()const{ return elements; }
	char* end()const { return firstfree; }
	const char *c_str() const { return elements; }
	~String();
	void push_back(const char);
	
private:
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void reallocate();
	char *elements;
	char *firstfree;
	char *cap;
	std::allocator<char> alloc;

};
bool operator==(String&, String&);
bool operator!=(String&, String&);

#endif