#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b;
string add(string Num1, string Num2)
{
	string Ans;
	int *a,*b,i,Max,Len,Len1,Len2,k;
	Len1=(int)Num1.length();
	Len2=(int)Num2.length();
	if (Len1>Len2) Len=Len1;
	else Len=Len2;
	Max=Len;
	a=new int[Len+1];
	for (i=0;i<=Len;i++) a[i]=0;
	b=new int[Len];
	for (i=0;i<=Len-1;i++) b[i]=0;
	k=0;
	for (i=Len1-1;i>=0;i--) a[k++]=Num1[i]-'0';
	k=0;
	for (i=Len2-1;i>=0;i--) b[k++]=Num2[i]-'0';
	for (i=0;i<=Len-1;i++)
	{
		a[i]=a[i]+b[i];
		if (a[i]>=10)
		{
			a[i]=a[i]-10;
			a[i+1]++;
		}
	}
	while (Len+1>Max || a[Len+1]==0) Len--;
	for (i=Len+1;i>=0;i--) Ans.append(1,a[i]+'0');
	return Ans;
}

int main()
{
	freopen("hd1002.txt","r",stdin);
	int t;
	cin>>t;
	int count=0;
	for(int i=0;i<t;++i)
	{
		cin>>a>>b;
		if(i!=t-1)
		cout<<"Case "<<i+1<<":"<<endl<<a<<" + "<<b<<" = "<<add(a,b)<<endl/*<<endl*/;
		else
		cout<<"Case "<<i+1<<":"<<endl<<a<<" + "<<b<<" = "<<add(a,b)<<endl;
	}
	return 0;
}
