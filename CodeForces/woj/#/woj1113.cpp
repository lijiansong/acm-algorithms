/*Ref*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct    Coord{
    float x;
    float y;
    int value;
}coord;
int The_Biggest_Point(coord spot[],int,float,float,float );
int main(){
    coord *spot;
    float X,Y,R,r,x,y;
    int n,j;
    while(scanf("%f%f%f",&X,&Y,&R)==3&&R>0){
            scanf("%d",&n);
            j=0;
            spot=(coord *)malloc(n*sizeof(coord));
            while(n--){
                scanf("%f%f",&x,&y);
                if(x==X||y==Y)
                    if(x==X)
                        r=abs(Y-y);
                    else
                        r=abs(x-X);
                else
                    r=sqrt(pow(abs(x-X),2)+pow(abs(y-Y),2));
                if(r<R||r==R){
                    spot[j].x=x;
                    spot[j].value=1;
                    spot[j++].y=y;
                }
            }
            if(!j)
                printf("%d\n",j);
            else{
                spot=(coord *)realloc(spot,j*sizeof(coord));
                The_Biggest_Point(spot,j,X,Y,R);
            }
            free(spot);
    }
    return 0;
}
int The_Biggest_Point(coord spot[],int n,float X,float Y,float R){
    int i,j,max;
    float x1,y1,x2,y2;
    for(i=0,max=1;i<n;i++){
        x1=spot[i].x-X,y1=spot[i].y-Y;
        for(j=0;j<n;j++){
            if(i==j)
                continue;
            x2=spot[j].x-X,y2=spot[j].y-Y;
            if(x1*y2-y1*x2<=0)
                spot[i].value++;
        }
        if(spot[i].value>max)
            max=spot[i].value;
    }    
    printf("%d\n",max);
    return 0;
}