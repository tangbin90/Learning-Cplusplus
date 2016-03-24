#ifndef FOLDER_H
#define FOLDER_H
#include <set>
#include "message.h"

class Folder
{
	friend class Message;
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;
	Folder& operator=(Folder&);
	Folder(const Folder& fd);
	void RemoveFolderToMsg();
	void AddFolderToMsg();
	void printFolder();

	~Folder();
private:
	std::set<Message*> MessageFolder;
	void addMsg(Message*);
	void remMsg(Message*);
};

#endif