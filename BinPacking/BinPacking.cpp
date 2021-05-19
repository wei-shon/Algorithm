#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Box(int Num,vector<float> Things);
int main(){
    int Num;
    cin>>Num;
    vector<float> Things;
    float size;
    for(int i = 0 ; i < Num ;i++)
    {
        cin>>size;
        Things.push_back(size);
    }
    //sort(Things.begin(),Things.end(),greater<float>());
    int answer=Box(Num ,Things);
    cout<<answer<<endl;
}
int Box(int Num ,vector<float> Things){
    int answer=0;
    float BoxInside=1.0;
    for(;0<Num;)//insure we pick all the things we want to put into box
    {
        for(int j = 0 ; j < Num ;j++)
        {
            if(BoxInside-Things[j]>-0.01){//use -0.1 because the float number subtraction each other cannot make sure equal to 0
                BoxInside=BoxInside-Things[j];
                Things.erase(Things.begin()+j);//if we had choosen we delete from the vector
                Num--;
                break;//use break is make sure we choose from the first things and 
                     //because we use erase so the index may have some problem so we forcibly it run from begin.
            }
            else if(j==Num-1)//we caannot put any things into box, then we choose new box to use
            {
                answer+=1;
                BoxInside=1.0;
            }
        }
        if(Num==0 && BoxInside<1.0)//because finally our box have nothing to put, so we make check the inside of final box have something or not
        {
            answer+=1;
        }
    }
    return answer;
}