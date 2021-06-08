# include<iostream>
# include<vector>
# include<string>
using namespace std;
int check(vector<char> farm);
int main(){
    int Num;
    cin>>Num;
    vector<int>a;
    for(int i = 0 ; i < Num ;i++){
        vector<char> farm;
        int LendNumber;
        cin>>LendNumber;
        for(int j = 0 ; j < LendNumber ;j++){
            char temp;
            cin>>temp;
            farm.push_back(temp);
        }
        int answer=check(farm);
        a.push_back(answer);
        cout<<"Case "<<i+1<<": "<<answer<<endl;
    }
}
int check(vector<char> farm){
    int total=0;
    int temp=0;
    for(int i = 0 ; i < farm.size();i++){
        if(farm[i]=='.'){
            temp+=1;
            if(temp==1 && farm[i+1]=='#' && farm[i+2]=='.'){//this situation is .#. we can put 稻草人 at #
                total+=1;
                temp=0;
                i=i+2;
            }
        }
        else if(farm[i]=='#' && temp>0){
            if(temp<=3 && temp>0) total+=1;
            else {
                temp=temp/2;
                total+=temp; 
            }
            temp=0;
        }
        if(temp==3){//if we have "..." then this is the biggest we can cover so we can flag a Scarecrow.
            total+=1;
            temp=0;
        }
        if(i==farm.size()-1 && temp>0){//to check the end of farm
            if(temp<=3) total+=1;
            else {
                temp=temp/2;
                total+=temp; 
            }
            temp=0;
        }
    }
    return total;
}