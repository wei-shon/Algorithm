#include<iostream>
#include<vector>
using namespace std;

int main(){
    int area1 = 0;
    int area4 = 0;
    int area9 = 0;
    int area16 = 0;
    int area25 = 0;
    int area36 = 0;
    cin>>area1;
    cin>>area4;
    cin>>area9;
    cin>>area16;
    cin>>area25;
    cin>>area36;
    vector<int> Count;
    while(area1 != 0 || area4 != 0 || area9 != 0 || area16 != 0 || area25 != 0 || area36 != 0)
    {
        int TotalArea=0;
        int answer=0;
        if(area36>0){
            answer+=area36;
        }
        if (area25>0){
            for(int i = 0 ; i < area25 ;area25--){
                if(area1>0 && 11>=area1){
                    area1=0;
                }
                else if(area1>11){
                    area1-=11;
                }
                answer+=1;
            }
        }
        if(area16>0){
            for(int i = 0 ; i < area16 ;area16--){
                if(area4>0 && 5>=area4){
                    area4=0;
                    if(area1>20-area4*4){
                        area1-=(20-area4*4);
                    }
                    else{
                        area1=0;
                    }
                }
                else if(area4>5){
                    area4-=5;
                }
                else{               
                    if(area1>20) area1-=20;
                    else area1=0;
                }
                answer+=1;
            }            
        }
        if(area9>0){
            answer+=(area9/4);
            area9=area9%4;
            
            if(area9==1){
                if(area4>0 && 5>=area4){
                    if(area1>27-area4*4){
                        area1-=(27-area4*4);
                    }
                    else{
                        area1=0;
                    }
                    area4=0;
                }
                else if(area4>5){
                    area4-=5;
                    if(area1>7){
                        area1-=7;
                    }
                    else{
                        area1=0;
                    }
                }
                else{                    
                    if(area1>27) area1-=27;
                    else area1=0;
                }
                answer+=1;                
            }
            else if (area9==2){
                if(area4>0 && 3>=area4){
                    if(area1>18-area4*4){
                        area1-=(18-area4*4);
                    }
                    else{
                        area1=0;
                    }
                    area4=0;
                }
                else if(area4>3){
                    area4-=3;
                    if(area1>6){
                        area1-=6;
                    }
                    else{
                        area1=0;
                    }
                }
                else{                    
                    if(area1>18) area1-=18;
                    else area1=0;
                }
                answer+=1;  
            }
            else if (area9==3){
                if(area4>0 && 1>=area4){
                    if(area1>9-area4*4){
                        area1-=(9-area4*4);
                    }
                    else{
                        area1=0;
                    }
                    area4=0;
                }
                else if(area4>1){
                    area4-=1;
                    if(area1>5){
                        area1-=5;
                    }
                    else{
                        area1=0;
                    }
                }
                else area1-=9;
                answer+=1;
            }               
        }
        if(area4>0){
            answer+=area4/9;
            area4=area4%9;
            
            if(area4>0){
                if(area1>36-area4*4){
                    area1-=(36-area4*4);
                }
                else{
                    area1=0;
                }
                area4=0; 
                answer+=1;               
            }
        }
        else{
            answer+=area1/36;
            if(area1>0) answer+=1;
        }
        if(TotalArea%36!=0) answer+=1;
        Count.push_back(answer);
        cin>>area1;
        cin>>area4;
        cin>>area9;
        cin>>area16;
        cin>>area25;
        cin>>area36;        
    }
    for(int i = 0 ; i < Count.size();i++){
        cout<<Count[i]<<endl;
    }
}