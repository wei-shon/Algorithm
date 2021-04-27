#include<iostream>
#include<cmath>
using namespace std;

void check(int num);
int main(){
    int times;
    cin>>times;
    int num[times];
    int answer;
    for(int i = 0 ;i < times;i++ ){
        cin>>num[i];
    }
    for(int i = 0 ;i < times;i++ ){
        check(num[i]);
    }
    
}
void check(int num){
    int answer=0;//to check whether this number can divid by 2-9 if can't answer=-1
    int count=0;//use to count what index the array save
    int array[100];//use to save the digits  
    if(num<10){
        cout<<num<<endl;
    }
    else{
        while(true){
            for(int i = 9 ; 0 < i ; i--){
                if(i==1){
                    answer=-1;
                    break;
                }
                else if(num%i==0){
                    array[count]=i;
                    count++;
                    num=num/i;
                    break;
                }
            }
            if(num<10){
                array[count]=num;
                break;                
            }
            if(answer==-1){
                break;
            }
        }
        if(answer!=-1){
            for(int i = count  ;  i >=0 ; i--){
                cout<<array[i];
            }
        }
        else if(answer==-1){
            cout<<-1;
        }
        cout<<endl;
    }
}