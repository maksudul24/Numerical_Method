#include<bits/stdc++.h>

using namespace std;
double cof(int n,double p)
{
	double ans=p;
	double fac=n;
	double fac_ans=1;
	for(int i=1;i<n;i++){
		ans*=(p-i);
		fac_ans*=fac;
		fac--;
		if(i==n-1){
			ans=ans/fac;	
		}
	}
	return ans;
}
int main()
{
    double ara[100][100],p,total=0,n;
    int i,j;
    double x[100],temp;
    cout<<"Enter The Number of Elemnts\n";
    cin>>n;
    cout<<"Enter x with corresponding value fomat:x f(x)\n";
    for(i=0;i<n;i++){
       scanf("%lf %lf",&x[i],&ara[0][i]);
    }
    //creating table
    for(i=1;i<n;i++){
        for(j=1;j<n-i;j++){
            ara[i][j-1]=ara[i-1][j]-ara[i-1][j-1];
        }
    }
    cout<<"Enter given value to find:\n";
    cin>>temp;
    //finding p
    p=(temp-x[0])/(x[1]-x[0]);
    //performing forward interpolation
    for(i=1;i<n;i++){
   		if(i!=1) temp=cof(i-1,p);
   		else temp=1;
       total+=(temp*ara[i][0]);
    }
    printf("Value is %lf\n",total);
    return 0;
}
    
    
