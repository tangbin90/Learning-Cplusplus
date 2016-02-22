// FindTheKthNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

double FindKth(vector<int>& A, int al, int aR, vector<int>& B, int bl, int bR, int k)
{
	if (al > aR) return B[bl + k - 1];
	if (bl > bR)	return A[al + k - 1];

	int mida = (al + aR) / 2;
	int midb = (bl + bR) / 2;
	if (A[mida] >= B[midb])
	{
		if (k <= (mida - al) + (midb - bl) + 1)
		{
			return FindKth(A, al, mida-1, B, bl, bR, k);
		}
		else
		{
			return FindKth(A, al, aR, B, midb+1, bR, k-(midb-bl)-1);
		}

	}
	else
	{
		if (k <= (mida - al) + (midb - bl) + 1)
		{
			return FindKth(A, al, aR, B, bl, midb-1, k);
		}
		else
		{
			return FindKth(A, mida+1, aR, B, bl, bR, k-(mida-al)-1);
		}

	}
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	if (nums1.size() > nums2.size())
		swap(nums1, nums2);
	if (nums1.empty()) {
		if (nums2.empty())
			return 0;
		double res = nums2[nums2.size() / 2] + nums2[(nums2.size() - 1) / 2];
		return res / 2.;
	}
	int Num1 = nums1.size();
	int Num2 = nums2.size();
	int r1 = FindKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, (Num1 + Num2+1) / 2);
	if (((Num1 + Num2) & 0x01) == 0)
	{
		double r2 = FindKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, (Num1 + Num2+1) / 2 + 1);
		double result = (r1 + r2) / 2;
		return result;
	}
	else
		return r1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 1};
	int B[] = { 1};
	string s;
	s.e()
	vector<int> Aarray(A, A + sizeof(A)/sizeof(int));
	vector<int> Barray(B, B + sizeof(B) / sizeof(int));
	cout << showpoint << findMedianSortedArrays(Aarray, Barray) << endl;
	system("pause");
	return 0;
}

