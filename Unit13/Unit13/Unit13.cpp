// Unit13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "ex13_31.h"
#include "message.h"
#include "folder.h"

using namespace std;
class Point
{
public:
	Point()
	{
		cout << "construct" << endl;
	}
	Point(Point&)
	{
		cout << "copy construct" << endl;
	}
};
void printvec(vector<int> vec)
{
	cout << *vec.begin() << endl;
}


struct X
{
	X(){ cout << "X()" << endl; }
	X(const X&){ cout << "X(const X&)" << endl; }
	X& operator=(X& little)
	{
		cout << "operator=(X& little)" << endl;
		return *this;
	}

	~X()
	{
		cout << "~X()" << endl;
	}
};
//13.28
class TreeNode
{
public:
	TreeNode():value(""),count(new int(0)),left(nullptr),right(nullptr){}
	TreeNode(TreeNode& trnode)
	{
		value = trnode.value;
		++*trnode.count;
		count = trnode.count;
		left = trnode.left;
		right = trnode.right;
	}

	TreeNode& operator=(const TreeNode& trnode)
	{
		++*trnode.count;
		if (--*trnode.count == 0)
		{
			if (left)
				delete left;
			if (right)
				delete right;
		}
		delete count;
		count = trnode.count;
		value = trnode.value;
		left = trnode.left;
		right = trnode.right;
		return *this;
	}

	~TreeNode()
	{
		if (--*count == 0)
		{
			if (left)
				delete left;
			if (right)
				delete right;
		}
		delete count;
	}
private:
	string value;
	int* count;
	TreeNode *left;
	TreeNode *right;

};
class BinStrTree
{
public:
	BinStrTree() :root(new TreeNode()){ }
	BinStrTree(BinStrTree& rhs) :root(new TreeNode(*rhs.root)){}
	BinStrTree& operator = (const BinStrTree& rhs)
	{
		TreeNode* temp = new TreeNode(*rhs.root);
		delete root;
		root = temp;
		return *this;
	}
	~BinStrTree()
	{
		delete root;
	}
private:
	TreeNode *root;
};
void func(const X& xk)
{
	X* xporint = new X();
	vector<X> xvector;
	xvector.reserve(2);
	//可能在pushback的时候容量不够
	xvector.push_back(xk);
	xvector.push_back(*xporint);
	delete xporint;
}
Point global;

class numbered
{
public:
	static int num;
	numbered(){ mysn = num++; }
	numbered(const numbered& numer){ cout << "copt construct!" << endl; mysn = num++; }
	int mysn;
};
void f(numbered& s){ cout << s.mysn << endl; }

int numbered::num = 0;

//13.18
class Employee
{
public:
	static int count;
	Employee():name(""),num(count++){ }
	Employee(string nm):name(nm),num(count++){ }
	Employee(const Employee& rh){ num = count++; name = rh.name; }
	Employee& operator=(const Employee& rh){ num = count++; name = rh.name;}
private:
	string name;
	int num;
};
int Employee::count = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	Message msg1("blue"),msg2("Yellow"),msg3("car"),msg4("bus");
	Folder color, traffic;
	msg1.save(color);
	msg2.save(color);
	msg3.save(traffic);
	msg4.save(traffic);

	color.printFolder();
	swap(color, traffic);
	color.printFolder();
	swap(msg1, msg3);
	color.printFolder();
	msg1.debugpring();

	system("pause");
	return 0;
}

