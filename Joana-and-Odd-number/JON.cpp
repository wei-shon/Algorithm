#include<iostream>
#include <climits>
using namespace std;
void Joana(int Data);
void cool(int num)
{
    int sum=0;
    for(int i=3;i<=num;i+=2)
        sum+=i;
    
    long long ans=0;
    ans = (2*sum-3)*(2*sum-1)*(2*sum+1);
    cout<< ans<<endl;
}

int main(){
    int DataCount;
    cin>>DataCount;
    int DataArray[DataCount];
    for (int i = 0 ; i < DataCount; i++){
        cin>>DataArray[i];
    }
    for (int j = 0 ; j < DataCount; j++){
        Joana(DataArray[j]);
        // cool(DataArray[j]);
    }    
}
void Joana(int Data){
    long long int ProductOfNumber=1;//its max value is 2**63
    int Count=0;
    if(Data==1){
        cout<<1<<endl;
    }
    else{
        int num=0;
        for(int i = 0 ; num <= Data ; i++){
            if(num>Data){
                break;
            }
            Count+=num;
            num=2*i+1;
        }
        Count-=1;//since we have take out 1 for spacial case
        for(int j = 2 ; j <= 1000000000; j++){
            if(j%2==1){
                if(Count<=3){
                    ProductOfNumber*=j;
                }
                Count--;
            }
            if(Count==0){
                break;
            }
        }
        cout<<ProductOfNumber<<endl;
    }
}