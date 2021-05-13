#include<iostream>

using namespace std;

int bricks(int StackNum , int Stack[]);
int main(){
    int Num ;
    cin>>Num;
    int answer[Num];
    for(int i = 0 ; i < Num ; i++)
    {
        int StackNum;
        cin>>StackNum;
        int Stack[StackNum];
        for(int j = 0 ; j < StackNum ;j++)
        {
            cin>>Stack[j];
        }
        answer[i]=bricks(StackNum,Stack);
    }
    for(int j = 0 ;j < Num ; j++){
        cout<<answer[j]<<endl;
    }
}

int bricks(int StackNum , int Stack[]){
    int Count=0;
    int Average=0;
    for(int i = 0 ; i < StackNum ;i++)
    {
        Average+=Stack[i];
    }
    Average=Average/StackNum;
    for(int j = 0 ; j < StackNum ; j++)
    {
        for(int k = j+1 ; k < StackNum ;){
            if(Stack[j]-Average>0 && Stack[k]-Average<0){
                Stack[j]=Stack[j]-1;
                Stack[k]=Stack[k]+1;
                Count++;
            }
            else if(Stack[j]-Average<0 && Stack[k]-Average>0){
                Stack[j]=Stack[j]+1;
                Stack[k]=Stack[k]-1;
                Count++;
            }
            else k++;
        }
    }
    return Count;
}