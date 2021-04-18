#include<iostream>
using namespace std;

void insertion(int data[100],int number);
int main(){
    int number;
    cin>>number;
    while(number!=0){
        int data[number];
        for (int i = 0 ; i < number ;i++){
            cin>>data[i];
        }
        insertion(data,number);
        cin>>number;
    } 
}
void insertion(int data[100],int number){
    int key;
    for (int i = 1 ; i < number ; i++){
        key=data[i];
        for (int j = i-1 ; 0<=j ; j--){
            if(key<data[j]){
                data[j+1]=data[j];
                if (j==0){
                    data[j]=key;
                }
            }
            else{
                data[j+1]=key;
                break;
            }
        }
    }
    for(int i = 0 ; i < number ; i++){
        cout<<data[i]<<" ";
        if(i==number-1)cout<<endl;
    }       
} 