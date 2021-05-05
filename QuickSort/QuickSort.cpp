#include <iostream>
using namespace std;
void Quick(int Array[], int Num , int lb ,int rb);
int main()
{
    //input
    int Num;
    cin>>Num;
    int Data[Num];
    for(int i = 0 ; i < Num ; i++)
    {
        cin>>Data[i];
    }
    //Quick Sort
    int rb=Num-1;
    int lb=0;
    for(int i =0; i < Num ; i++)
    {
        if(i==Num-1)
        {
            cout<<Data[i]<<" "<<endl;
            break;
        }
        cout<<Data[i]<<" ";
    } 
    Quick(Data , Num, lb ,rb);
}
void Quick(int Array[],int Num ,int lb , int rb){
    if (lb>=rb)
    {
        return;
    }
    int p=Array[lb];
    int l=lb+1;
    int r=rb;
    while(true)
    {
        
        //find Array[l]>=p
        while(l<=rb)
        {
            if(Array[l]>p) break;
            l++;
        }
        // find Array[r]<p or r==lb
        while(r>lb)
        {
            if(Array[r]<p) break;
            r--;
        }
        if(l>r)
        {
            break;
        }
        //switch Array[l] and Array[r]
        int temp=Array[l];
        Array[l]=Array[r];
        Array[r]=temp;
        for(int i =0; i < Num ; i++)
        {
            if(i==Num-1)
            {
                cout<<Array[i]<<" "<<endl;
                break;
            }
            cout<<Array[i]<<" ";
        } 
    }
    //switch Array[lb] and Array[r]
    int temp=Array[lb];
    Array[lb]=Array[r];
    Array[r]=temp;
    for(int i =0; i < Num ; i++)
    {
        if(i==Num-1)
        {
            cout<<Array[i]<<" "<<endl;
            break;
        }
        cout<<Array[i]<<" ";
    }
    Quick(Array , Num, lb ,r-1);
    Quick(Array , Num, r+1 ,rb);
}