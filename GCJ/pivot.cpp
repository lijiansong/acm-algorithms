#include<iostream>
#include<algorithm>
/*
快排分区函数： 
随机选择一个数作为枢纽元（pivot），这里选择第一个数，
把比枢纽元小的数放在数组的左边，
把大于等于枢纽元的数移到数组的右边，
一趟遍历过后枢纽元归位， 
返回枢纽元的位置下标 
*/
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
int partition_(int a[],int start,int end)
{
	int pivotIndex=start;
	int pivot=a[pivotIndex];
	swap(a[pivotIndex],a[end]);
	int storeIndex=start;
	for(int i=0;i<end;++i)
	{
		if(a[i]<pivot)
		{
			if(i!=storeIndex)
			{
				swap(a[i],a[storeIndex]);
			}
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
