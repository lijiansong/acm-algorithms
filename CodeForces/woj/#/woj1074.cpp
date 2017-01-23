#include<stdio.h>
#define MAX 10000
int theSort(int left,int right,long int* numbers){
    long int key=numbers[left],temp=0;
    int i=left,j=right;
    while(1){
        for(;right>left;right--){
            if(numbers[right]<key){
                temp=numbers[right];
                numbers[right]=numbers[left];
                numbers[left]=temp;
                break;
            }
        }
        for(;left<right;left++){
            if(numbers[left]>key){
                temp=numbers[left];
                numbers[left]=numbers[right];
                numbers[right]=temp;
                break;
            }
        }
        if(left>=right) break;
    }
    if(left>i) theSort(i,left-1,numbers);
    if(j>right) theSort(right+1,j,numbers);          
    return 0;
}
long int findABC(int right,long int* a){
    for(int i=right;i>=2;i--){
        for(int j=0;j<i,a[j]<=a[i]-a[j];j++){
            for(int k=right-1;k>j;k--)
                if(a[j]+a[k]==a[i])
                    return a[i];
        }  
    }
    return -1l;
}
int main(){
    int t,n;
    long int a[MAX],max;
    scanf("%d",&t);
    while(t){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%ld",&a[i]);
        theSort(0,n-1,a);
        //for(int i=0;i<n;i++)
          //printf("%ld",a[i]);
        max=findABC(n-1,a);
        printf("%ld\n",max);
        t--;            
    }
    return 0;
}