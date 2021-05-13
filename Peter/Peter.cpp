#include<iostream>
using namespace std;

int smoke(int n , int k);
int main(){
    int Num;
    cin>>Num;
    int answer[Num];
    for(int i = 0 ; i < Num ; i++)
    {
        int k ;
        cin >> k;
        int n ;
        cin>>n ;
        int Total=smoke(n,k);
        answer[i]=Total;
    }
    for(int j = 0 ; j < Num ; j++) cout<<answer[j]<<endl;
}
int smoke(int n , int k){
    int ans=0;
    int beforesomke=n;
    int aftersomke=0;
    while(beforesomke>0)
    {
        ans+=beforesomke;
        aftersomke+=beforesomke;
        beforesomke=aftersomke/k;
        aftersomke=aftersomke%k;
    }
    //ans+=beforesomke;
    return ans;
}