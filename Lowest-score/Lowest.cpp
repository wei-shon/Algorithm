# include <iostream>
#include <vector>
using namespace std;
int main(){
    int Num;
    cin >> Num;
    for(int i = 0 ; i < Num ; i++){
        int people;
        cin >> people;
        int Score[people];
        for(int j = 0 ; j < people ; j ++){
            cin>> Score[j];
        }
        vector<int> Aclass;
        vector<int> Bclass;
        int w = 0;//index
        for(int k = 0 ; k < people ; k++){
            if(Score[k]<Score[k+1]) Aclass.push_back(Score[k]);
            if(Score[k]>Score[k+1]){
                Aclass.push_back(Score[k]);
                w=k+1;
                break;
            }
        } 
        for(int q = w ; q < people ; q++){
            Bclass.push_back(Score[q]);
        }
        char answer[3] ;
        int index=0;
        for(int z = 0 ; z < w ; ){
            for(int y = 0 ; y < people-w ;){
                if(index==3) break;
                else if(Aclass[z]<Bclass[y]){
                    z++;
                    answer[index]='A';
                    index++;
                }
                else if (Aclass[z]> Bclass[y]){
                    y++;
                    answer[index]='B';
                    index++;
                }
            }
            if(index==3) break;
            else{
                for (; index < 3 ; index ++){
                    answer[index]='A';
                }
            }
        }
        for(int p = 0 ; p < 3 ; p++){
            if(p==2) cout<<answer[p]<<endl;
            else cout<<answer[p];
        }
    }
}