# include <iostream>
# include <algorithm>
using namespace std;
void bubble(int score[]);
int main(){
    int Num;
    cin>>Num;
    int answer=0;
    for(int i = 0 ; i < Num ;i++){
        int score[20];
        for(int j = 0 ; j < 20 ;j++){
            cin>>score[j];
        }
        int target;
        cin>>target;
        bubble(score);
        for(int w = 0 ; w < target ;w++){
            if(w==target-1) answer=score[w];
        }
        cout<<answer<<endl;
    }
}
void bubble(int score[]){
    for(int i = 0 ; i < 20 ; i++){
        for(int j = i+1 ; j < 20; j++ ){
            if(score[i]>score[j]){
                int temp = score[j];
                score[j]=score[i];
                score[i]=temp;
            }
        }
    }
}