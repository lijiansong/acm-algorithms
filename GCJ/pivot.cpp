#include<iostream>
#include<algorithm>
using namespace std;
int partition(int a[],int start,int end)
{
	int pivotIndex=start;
	int pivot=a[pivotIndex];
	swap(a[pivotIndex],a[end]);
	int storeIndex=start;
	for(int i=0;i<end;++i)
	{
		if(a[i]<pivot)
		{
			swap(a[i],a[storeIndex]);
			++storeIndex;
		}
	}
	swap(a[storeIndex],a[end]);
	return storeIndex;
}
int main()
{
	return 0;
} 
