# include <iostream>
# include <vector>
# include <algorithm>
#include <string> 
using namespace std;

//struct a node to save the tree point we want to save
typedef struct node{
    char letter;//to save what letter we are
    int number;//to save letter's number
    string answer;//to save what huffman code we are
    bool check;//use to chack whether this node we went before?
    node *left;//remember the left child
    node *right;//remember the right child
    node *up;//remember the father
}node;

int main(){

    //input data
    string word;
    cin>>word;
    vector<node*> tree={};
    //to struct 
    for(int i = 0 ; i < word.size() ;i++){
        if(i==0){
            node *first = new node;
            first->check=false;
            first->letter=word[i];
            first->number=1;
            first->answer="";
            first->left=NULL;
            first->right=NULL;
            first->up=NULL;
            tree.push_back(first);         
            continue;
        }
        for(int k = 0 ; k < tree.size() ;k++){
            if(word[i]==tree[k]->letter){//if in this ch's number+1
                tree[k]->number+=1;
                break;
            }
            else if(k==tree.size()-1){// if not add this letter into ch and add 1 into num
                node *first = new node;
                first->check=false;
                first->letter=word[i];
                first->number=1;
                first->answer="";
                first->left=NULL;
                first->right=NULL;
                first->up=NULL;
                tree.push_back(first); 
                break;
            }
        }
    }

    //bubble sort
    for(int i = 0 ; i < tree.size() ; i++){
        for(int j = i+1 ; j < tree.size(); j++ ){
            if(tree[i]->number>tree[j]->number){
                node *te = new node;
                te=tree[j];
                tree[j]=tree[i];
                tree[i]=te;                
            }
        }
    } 

    //creat a tree

    if(tree.size()==1){
        cout<<tree[0]->letter<<":"<<0<<endl;
    }
    else if(tree.size()==2){
        for(int i = 0 ; i < tree.size() ;i++){
            cout<<tree[i]->letter<<":"<<i<<endl;
        }        
    }
    else{

        //to struct tree
        node *ptr;//指向root
        while( tree.size() >1){
            //抓出兩個較小數量的字母 合併成一個新的樹 father的數量是兩個child 的數量加總 ，child的上面則是father(tree[0]->temp and tree[1]->temp)
            node *temp = new node;//father
            temp->check=false;
            temp->letter='q';
            temp->number=tree[0]->number+tree[1]->number;
            temp->answer="";
            tree[0]->up=temp;//child's up
            tree[1]->up=temp;//child's up
            //we don't campare tree[0]and tree[1] since we have sorted ,tree[0] is smallest and tree[1] is second smallest
            temp->left=tree[0];
            temp->right=tree[1];
            temp->up==NULL;
            tree.erase(tree.begin());
            tree.erase(tree.begin());
            tree.push_back(temp);            
            //bubble sort
            if(tree.size()>2){//bubble sort because we will add new node into tree vector so we should sort again
                for(int i = 0 ; i < tree.size() ; i++){
                    for(int j = i+1 ; j < tree.size(); j++ ){
                        if(tree[i]->number>tree[j]->number){
                            node *te = new node;
                            te=tree[j];
                            tree[j]=tree[i];
                            tree[i]=te;              
                        }

                    }
                }
            }
            else if(tree.size()==2){//to deal with only two node in tree vector
                if(tree[0]->number>tree[1]->number){
                    node *te = new node;
                    te=tree[0];
                    tree[0]=tree[1];
                    tree[1]=te;              
                }
            } 
        }

        //go through every node in tree and set their huffamn code to themself
        ptr=tree[0];
        node* temp=ptr;
        string w="";//to record what huffman code we should give to letter;
        vector <char> finalanswer={};//use to catch the leaf's letter we want to output
        vector <string> finalnum={};//use to catch the leaf's huffman code we want to output
        while(true){
            if(ptr->left!=NULL && ptr->left->check==false){
                w+="0";
                ptr=ptr->left;
                ptr->answer+=w;
                ptr->check=true;
            }
            else if(ptr->right!=NULL && ptr->right->check==false){
                if(temp==ptr){//if do this then it show we have went through all the left side of tree
                    ptr->check=true;
                }
                w+="1";
                ptr=ptr->right;
                ptr->answer+=w;            
                ptr->check=true;
            }
            else if(ptr->left==NULL && ptr->right==NULL){
                char a=ptr->letter;
                finalanswer.push_back(a);
                finalnum.push_back(ptr->answer);
                w.erase(w.end()-1);
                ptr=ptr->up;
                
            }
            //if all this node's child we have went before
            else if((ptr->left!=NULL && ptr->left->check==true)&& (ptr->right!=NULL  && ptr->right->check==true)){
                if(temp==ptr&& ptr->check==true){//if we have went through all this tree's node then we should break out while-loop
                    break;
                }
                ptr=ptr->up;
                w.erase(w.end()-1);

            }
        }

        //bubble sort since we would output what letter we want to output decided by their huffman code's big or small
        for(int i = 0 ; i < finalanswer.size();i++){
            for(int j = i+1 ; j < finalanswer.size();j++){
                if(stoi(finalnum[i])>stoi(finalnum[j])){
                    string temp=finalnum[i];
                    finalnum[i]=finalnum[j];
                    finalnum[j]=temp;
                    char tem =finalanswer[i];
                    finalanswer[i]=finalanswer[j];
                    finalanswer[j]=tem;
                }
            }
        }

        // output the answer
        for(int i = 0 ; i < finalanswer.size();i++){
            cout<<finalanswer[i]<<":"<<finalnum[i]<<endl;
        }
    }
}
/*test example
aaaaaabbbbbbbjjjjjjjjuuuuuuuuu
abbcccc
mississippis
*/