#include "stdafx.h"
#include "message.h"

void Message::save(Folder& folder)
{
	folders.insert(&folder);
	folder.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
	{
		f->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::addFolder(Folder* folder)
{
	folders.insert(folder);
}

void Message::deleteFolder(Folder* folder)
{
	folders.erase(folder);
}

void swap(Message& lhs, Message& rhs)
{
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
	
}