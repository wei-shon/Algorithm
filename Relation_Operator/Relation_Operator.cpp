#include<iostream>
using namespace std;

int main(){
    int first;
    int second;
    cin>>first;
    while(first!=0){
        cin>>second;
        if(first>second){
            cout<<">"<<endl;
        }
        else if(first==second){
            cout<<"="<<endl;
        }
        else{
            cout<<"<"<<endl;
        }
        cin>>first;
    }
}