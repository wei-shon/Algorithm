#include<iostream>
using namespace std;

int Euler(int num);
int checkgcd(int first,int second);
int main(){
    int times;
    cin>>times;
    int number[times];
    for(int i = 0 ; i < times ; i++){
        cin>>number[i];
    }
    int answer;
    for(int i = 0 ; i < times ; i++){
        answer=Euler(number[i]);
        cout<<answer<<endl;
    }    
}

int Euler(int num){
    int gcdnum=0;//to count how many prime number 
    int check;
    for(int i = 1 ; i<= num ; i++ ){
        check=checkgcd(num,i);
        if(check==1){//check==1 means there are coprime
            gcdnum++;
        }
    }
    return gcdnum;
}
int checkgcd(int first,int second){
    int third;
    if(second > first){
        third=first;
        first=second;
        second=third;
    }
    int ans=0;
    for(int j = 1; j <= second ;j++){
        if(first%j==0 && second%j==0){
            ans=j;
        }
    }
    return ans;
}