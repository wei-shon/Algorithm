#include <iostream>
#include <string>
using namespace std;

int main(){
    int Num;
    cin>>Num;
    string first;
    string second;
    for(int k = 0 ; k < Num ; k++){
        cin>>first>>second;
        bool answer= false;
        if(first.size()>second.size()){
            cout<<"No"<<endl;
            continue;
        }
        int j=0;
        for(int i = 0 ; i < second.size();i++){
            if(first[j]==second[i]){
                j++;
            }
            if(j==first.size()){
                answer=true;
            }
        }
        if(answer==true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}