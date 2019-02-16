#include<stdio.h>
#include<stdlib.h>
#define INF 53356
char str[105][105]; 
int tmp =0; 
void  Ppath(int path[][100],int i2,int j2)
{
    int k2;
    k2=path[i2][j2];
    if(k2==-1)
    {
        return;
    } 
    Ppath(path,i2,k2);
    printf("%c",str[tmp][k2]); 
    tmp = k2; 
    Ppath(path,k2,j2);
}

void Dispath(int A[][100],int path[][100],int n)
{
    
              Ppath(path,0,n-1);
              printf("%c",str[tmp][n-1]); 
          
}
      
int main()
{
    int ncity,nrode;  
    while(scanf("%d%d",&ncity,&nrode)!=EOF)
    { 
    int a[4000][5];
    char b[4000];
    char c[4000];    
    int i,j;    
    for(i=0;i<nrode;i++)
    {
          for(j=0;j<5;j++)
          {
                  scanf("%d",&a[i][j]);
          } 
          scanf("%s",&b[i]);
    }
    int pl,sl;                
    scanf("%d%d",&pl,&sl);          
    int n,i1,j1,k1;
    int G[100][100];
    int A[100][100],path[100][100];
    for(i1=0;i1<ncity;i1++)
        for(j1=0;j1<ncity;j1++)
        { 
              A[i1][j1]=INF; 
              G[i1][j1]=INF; 
        } 
    for(n=0;n<nrode;n++)
    {      
        int p,q;
        p=a[n][0];
        q=a[n][1]; 
        G[p][q]=a[n][4]; 
        str[p][q]=b[n]; 
    }                        
    for(i1=0;i1<ncity;i1++)
        for(j1=0;j1<ncity;j1++)
        {
              A[i1][j1]=G[i1][j1];
              path[i1][j1]=-1;
        }
    for(n=0;n<nrode;n++)
    {                    
        int p,q;
        p=a[n][0];
        q=a[n][1]; 
        if(a[n][2]>pl||a[n][3]>sl)
        {
              A[p][q]=INF;
        }
    }
    for(k1=0;k1<ncity;k1++)
    {
        for(i1=0;i1<ncity;i1++)
              for(j1=0;j1<ncity;j1++)
                  if(A[i1][j1]>A[i1][k1]+A[k1][j1])
                  {                                                              
                          A[i1][j1]=A[i1][k1]+A[k1][j1];
                          path[i1][j1]=k1;                                                            
                  }
    }
    Dispath(A,path,ncity); 
    } 
    return 0;
} 