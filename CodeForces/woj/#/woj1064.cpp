#include<stdio.h>
#include<stdlib.h>
#define MAX 50005
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
    int left[MAX],temp,n,l;
    while(scanf("%d",&n)==1){
    l=0;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(0==i){
            left[l]=temp;
            l++;
        }else{
            int j=0;
            for(;j<l;j++){
                if(left[j]==temp)
                    break;    
            }
            if(j==l){
                left[l]=temp;
                l++;        
            }      
        }    
    }
    theSort(0,l-1,left);
    for(int i=0;i<l;i++){
        if(0!=i)
            printf(" ");
        printf("%d",left[i]);
    }
    printf("\n");
    }
    return 0;  
}