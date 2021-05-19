#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int Num;
    cin>>Num;
    for(int i = 0 ; i < Num ;i++){
        // input the information
        int answer=0;
        int floor;
        cin>>floor;
        int everyfloor[floor] ;
        int level=0; // to store floor's size now
        for(int j = 0 ; j < floor ; j++){
            cin>>everyfloor[j];
            if(abs(everyfloor[j])-abs(level)>=0) level =everyfloor[j];//catch the biggest number of floor's size
        }
        answer+=1; // because we find the first floor

        // to calculate how many floors we can build

        bool check;//to check the next floor should be bigger or smaller than 0 
            // if >0 then check = true, if <0 then check=false
        int nextlevel=0; // to catch out the next floor size
        while(true){

            if(level>0) check=false;
            else check=true;
            int record=0;
            for(int k = 0 ; k < floor ;k++){
                if(check == true && everyfloor[k]>nextlevel && abs(level)>abs(everyfloor[k])){
                    nextlevel=everyfloor[k];
                }
                else if(check == false && everyfloor[k]<nextlevel && abs(level)>abs(everyfloor[k])){
                    nextlevel=everyfloor[k];
                }
                else record++;
            }
            if(record==floor)break;
            else{
                answer+=1;
                level=nextlevel;
                nextlevel=0;
            }
        }
        cout<<answer<<endl;
        // for(int w = 0 ; w < temp.size() ; w++) cout<<temp[w]<<" ";
    }
}