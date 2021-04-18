#include<iostream>
using namespace std;

int FIBO(int number);
int main(){
    int times;
    cin>>times;
    for (int i = 0 ; i < times ; i++){
        int number ;
        cin>>number;
        int answer=FIBO(number);
        cout<<answer<<endl;
    }
}
int FIBO(int number){
    int answer;
    if(number==1) answer=1;
    else if(number==2) answer=1;
    else if(number>=3){
        int a=1;
        int b=1;
        for(int j = 0 ; j < number-2 ; j++){
            answer=a+b;
            a=b;
            b=answer;
        }
    }
    return answer;
}