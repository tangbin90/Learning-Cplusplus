#include "stdafx.h"
#include "folder.h"

void Folder::addMsg(Message* msg)
{
	MessageFolder.insert(msg);
}
void Folder::remMsg(Message* msg)
{
	if (MessageFolder.count(msg) != 0)
		MessageFolder.erase(msg);
}

Folder& Folder::operator=(Folder& rhs)
{
	RemoveFolderToMsg();
	MessageFolder.clear();
	MessageFolder = rhs.MessageFolder;
	AddFolderToMsg();
	return *this;
}

Folder::Folder(const Folder& fd)
{
	this->MessageFolder = fd.MessageFolder;
	this->AddFolderToMsg();
}

Folder::~Folder()
{
	RemoveFolderToMsg();
	MessageFolder.clear();
}

void Folder::RemoveFolderToMsg()
{
	for (auto f : MessageFolder)
	{
		f->deleteFolder(this);
	}
}

void Folder::AddFolderToMsg()
{
	for (auto f : MessageFolder)
	{
		f->addFolder(this);
	}
}

void Folder::printFolder()
{
	for (auto f : MessageFolder)
	{
		f->debugpring();
	}
}

void swap(Folder& fd1, Folder& fd2)
{
	fd1.RemoveFolderToMsg();
	fd2.RemoveFolderToMsg();

	using std::swap;
	swap(fd1.MessageFolder, fd2.MessageFolder);

	fd1.AddFolderToMsg();
	fd2.AddFolderToMsg();
}
