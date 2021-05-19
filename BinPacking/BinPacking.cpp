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
    for(;0<Num;)
    {
        for(int j = 0 ; j < Num ;j++)
        {
            // cout<<BoxInside-Things[j]<<"##"<<endl;
            if(BoxInside-Things[j]>-0.01){
                BoxInside=BoxInside-Things[j];
                Things.erase(Things.begin()+j);
                Num--;
                break;
            }
            else if(j==Num-1)
            {
                answer+=1;
                BoxInside=1;
            }
        }
        if(Num==0)
        {
            answer+=1;
        }
        // for(int i = 0 ; i < Num ; i++) cout<<Things[i]<<endl;
    }
    return answer;
}