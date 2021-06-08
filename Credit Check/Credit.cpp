# include<iostream>
# include<vector>
# include<string>
using namespace std;
bool check(string credit);
int chartoint(char a);
int main(){
    int Num;
    cin>>Num;
    for(int i = 0 ; i < Num ;i++){
        string CreditCardNumber="";
        //use 4 because the credit have four sets of number
        for(int j = 0 ; j < 4 ;j++){
            string temp;
            cin>>temp;
            CreditCardNumber+=temp;
        }
        bool answer=check(CreditCardNumber);
        if(answer==true){
            cout<<"Valid"<<endl;
        }
        else{
            cout<<"Invalid"<<endl;
        }
        CreditCardNumber="";
    }
}
bool check(string credit){
    int odd=0;
    int even=0;
    
    for(int i = 0 ; i < credit.size();i++){
        if(i%2==1){
            odd+=chartoint(credit[i]);
        }
        else{
            int temp=chartoint(credit[i]);
            temp*=2;
            if(temp<10){
                even+=temp;
            }
            else{
                even+=1;
                even+=temp%10;
            }
        }
    }
    int check=(even+odd)%10;
    if(check==0) return true;
    else return false;
}
int chartoint(char a){
    if(a=='0') return 0;
    else if(a=='1')return 1;
    else if(a=='2')return 2;
    else if(a=='3')return 3;
    else if(a=='4')return 4;
    else if(a=='5')return 5;
    else if(a=='6')return 6;
    else if(a=='7')return 7;
    else if(a=='8')return 8;
    else return 9;
}