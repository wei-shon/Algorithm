#include<iostream>
using namespace std;
int insertion(int data[100],int number);
int main(){
    int number;
    cin>>number;
    while(number!=0){
        int data[100];
        for (int i = 0 ; i < number ;i++){
            cin>>data[i];
        }
        int swap=insertion(data,number);
        cout<<"Optimal swapping takes "<<swap<<" swaps."<<endl;
        cin>>number;
    } 
}
int insertion(int data[100],int number){
    int key;
    int times=0;
    for (int i = 1 ; i < number ; i++){
        key=data[i];
        for (int j = i-1 ; 0<=j ; j--){
            if(key<data[j]){
                data[j+1]=data[j];
                times+=1;
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
    return times;
} 