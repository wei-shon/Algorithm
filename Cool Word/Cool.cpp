# include <iostream>
# include <vector>
# include <algorithm>
#include <string> 
using namespace std;
int cool(int set);
int main(){
    int Num;
    cin>>Num;
    vector<int> wow;
    for(int i = 0 ; i < Num ;i++){
        int set;// to remember how many set we need to do
        cin>>set;
        int answer=cool(set);//to check whether it is cool or not
        wow.push_back(answer);//to save in vector because online juduge will not give me "Wrong Answer"
    }
    for(int i = 0 ; i < wow.size() ; i++) cout<<"Case "<<i+1<<": "<<wow[i]<<endl;// output answer
}
int cool(int set){
    int answer=0;
    string word;
    vector<char>letters={};//to remember what the char we have
    vector<int>numbers={};//to remember how many char we have
    for (int i = 0 ; i < set ;i++){
        cin>>word;
        for(int j = 0 ; j < word.size() ;j++){
            if(j==0){//use this because in the first word letters and numbers don not have any data , the below for-loop cannot run
                letters.push_back(word[j]);
                numbers.push_back(1);
                continue;
            }//to check letter whether in the letters or not
            for(int k = 0 ; k <letters.size() ;k++){
                if(word[j]==letters[k]){//if in this letter's number+1
                    numbers[k]+=1;
                    break;
                }
                else if(k==letters.size()-1){// if not add this letter into letters and add 1 into numbers
                    letters.push_back(word[j]);
                    numbers.push_back(1);
                    break;
                }
            }
        }
        sort(numbers.begin(),numbers.end());//sort because we only to check whether the letter's number is same with other letter or not
        for(int z = 0 ; z < numbers.size() ; z++){
            if(z==numbers.size()-1 && numbers.size()>1) {// if letter's number s not the same then this case is successful then answer +1
                answer+=1;
                break;
            }
            else if(numbers[z]==numbers[z+1]){// if not then we break and go to next case
                break;
            }
        }
        letters.clear();// for each word we should clear the vector
        numbers.clear();// for each word we should clear the vector
    }
    return answer;
}