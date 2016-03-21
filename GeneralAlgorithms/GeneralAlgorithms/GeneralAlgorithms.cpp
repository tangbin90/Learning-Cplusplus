// GeneralAlgorithms.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <forward_list>
#include <deque>
#include "Sales_item.h"
using namespace std;
using namespace std::placeholders;


int leftchild(int i)
{
	return i * 2 + 1;
}

int rightchild(int i)
{
	return i * 2 + 2;
}

int parent(int i)
{
	return (i - 1) / 2;
}

void heaplify(int array[], int i, int length)
{
	int tmp=i;
	int left = leftchild(i);
	int right = rightchild(i);
	if (left<length&&array[tmp] < array[left])
		tmp = left;

	if (right<length&&array[right] > array[tmp])
		tmp = right;
	if (tmp != i)
	{
		swap(array[tmp], array[i]);
		heaplify(array, tmp,length);
	}
}

void BuidMaxHeap(int array[], int begin, int end)
{
	int size = end - begin + 1;
	for (int i = begin + size / 2; i >= begin; i--)
	{
		heaplify(array, i,end-begin+1);
	}
}

void heapsort(int array[], int begin, int end)
{
	BuidMaxHeap(array, begin, end);
	for (int i = end; i > begin; i--)
	{
		swap(array[i], array[begin]);
		heaplify(array, begin,i-begin);
	}
}
int partition(int array[], int begin, int end)
{
	int key = array[end];
	int j = begin - 1;
	for (int i = begin; i < end; i++)
	{
		if (array[i] <= key)
		{
			j = j + 1;
			swap(array[i], array[j]);
		}
	}
	array[end]=array[j+1];
	array[j + 1] = key;
	return j + 1;
}

void quicksort(int array[], int start, int end)
{
	if (start < end)
	{
		int mid = partition(array, start, end);
		quicksort(array, start, mid - 1);
		quicksort(array, mid + 1, end);
	}
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}


void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());

}

bool isStringoverfive(string str)
{
	return str.size() >= 5;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() > sz;
}



void writetofile(istream &in, ofstream &out1, ofstream &out2)
{
	istream_iterator<int> input(in);
	istream_iterator<int> eof;
	ostream_iterator<int> output1(out1, " ");
	ostream_iterator<int> output2(out2, " ");
	
	for_each(input, eof, [&output1, &output2](int i)mutable{*(i & 0x01 ? output2 : output1)++ = i; });
}

int _tmain(int argc, _TCHAR* argv[])
{

	list<string> str = { "can", "you", "believe", "I", "have", "ten", "words", "without", "any", "repeat","repeat","can","you" };
	str.sort();
	str.unique();
	for_each(str.begin(), str.end(), [](string &val){cout << val<<" "; });
	system("pause");
}

