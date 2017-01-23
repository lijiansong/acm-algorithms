#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int readIn(int n,int* numbers){
    char* num;
    int numSize=10;
    num=(char*)malloc(n*numSize*sizeof(char));
    gets(num);
    int i=0,j=0;
    while(num[i]){
        if('0'==num[i]&&32==num[i-1]) break;
        if(32==num[i]){
            j++;
        }else{
            numbers[j]=numbers[j]*10+(num[i]-'0');
        }
        i++;
    }

  return 0;
}
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
    int* numbers;
    int n=1000000;
    numbers=(int*)malloc(n*sizeof(int));
    readIn(n,numbers);
    int length=0;
    for(int i=0;i<n;i++){
            if(numbers[i]==0) break;
            length++;
    }
    int temp=0;
    theSort(0,length-1,numbers);
    
    for(int i=0;i<length;i++){
            while(numbers[i]==numbers[i+1]) i++;
            printf("%d ",numbers[i]);
            }
    return 0;
}