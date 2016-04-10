#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <set>

using namespace std;

template<typename T>
int compare(const T &t1, const T &t2)
{
	if(t1>t2) return 1;
	if(t1<t2) return -1;
	return 0;
}


template<typename T, typename value>
int find(T& val,value& i)
{
	for(value temp:val)
	{
		if(temp==i)
			return true;
	}
	return false;
}

int main(int num, char* argc[])
{
	std::vector<int> vecint={1,21,2,1,2,12,1,2};
	cout<<find(vecint,3)<<endl;
	return 0;

}