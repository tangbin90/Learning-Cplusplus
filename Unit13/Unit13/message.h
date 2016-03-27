#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <vector>
#include <set>
#include "folder.h"
#include <iostream>
using std::string;

class Message
{
	friend class Folder;
	friend void swap(Message& lhs, Message& rhs);
public:
	explicit  Message(const std::string &str = "") :contents(str)
	{}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&&) _NOEXCEPT;
	Message& operator=(Message&&) _NOEXCEPT;
	~Message();
	void save(Folder&);
	void remove(Folder&);

	void debugpring()
	{
		std::cout << contents << std::endl;
	}
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFolder(Folder*);
	void deleteFolder(Folder*);
};

#endif
