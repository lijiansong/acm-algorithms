#include<stdio.h>
#include<stdlib.h>
#define MAX 1005
int theSort(int left,int right,int* numbers){
    int key=numbers[left],temp=0,i=left,j=right;
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

int main(){
    int t,n,p,c,se[MAX];
    scanf("%d",&t);
    c=1; 
    while(c<=t){
        scanf("%d",&n);
        p=0;
        for(int i=0;i<n;i++){
            scanf("%d",&se[i]);
            se[i]-=p;
            p=se[i]+p;      
        }
        theSort(0,n-1,se);
        printf("Case %d:\n",c);
        for(int j=0;j<n;j++){
            if(j<n-1)
                printf("%d ",se[j]);
            else
                printf("%d",se[j]);
        }
        if(c<t)
            printf("\n\n");
        else
            printf("\n");
        c++;
    } 
    return 0; 
}