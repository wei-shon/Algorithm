# include<iostream>
# include<vector>
# include<string>
# include <string.h>    //memset
# include <stack>       //stack
#include <algorithm>    //find
using namespace std;
int intfirst(string a);
int intsecond(string a);
bool Hamiltonian_check(stack <int> path, int N ,vector<vector<int>>& adj);
bool Hamiltonian_path(vector<vector<int>>& adj, int N);

int main(){
    int Num;
    cin>>Num;
    for(int i = 0 ; i < Num ;i++){
        int edge;
        cin>>edge;
        vector<int>first;
        vector<int>second;
        vector<int>nodeset;
        int node=0;
        //input edge
        for(int j = 0 ; j < edge ;j++){
            string temp;
            cin>>temp;
            first.push_back(intfirst(temp));
            second.push_back(intsecond(temp));
        }
        //find node(vertex)
        for(int w = 0 ; w < first.size() ;w++){
            if(w == 0) {
                nodeset.push_back(first[w]);
                nodeset.push_back(second[w]);
            }
            for(int j = 0 ; j < nodeset.size() ; j++){
                if(first[w]==nodeset[j]) break;
                else if (j==nodeset.size()-1) nodeset.push_back(first[w]);
            }
            for(int j = 0 ; j < nodeset.size() ; j++){
                if(second[w]==nodeset[j]) break;
                else if (j==nodeset.size()-1) nodeset.push_back(second[w]);
            }            
        }
        node=nodeset.size();

        //draw graph
        vector<vector<int>> adj ;
        vector<int>temp(node);
        //intialize the vector's size
        adj.resize(node,temp);
        //set all of the vector's value
        for(int j = 0 ; j < node ;j++){
            for(int k = 0 ; k < node ; k++){
                adj[j][k]=0;
            }
        }         
        for(int j = 0 ; j < first.size() ;j++){
            adj[first[j]-1][second[j]-1]=1;
            adj[second[j]-1][first[j]-1]=1;
        }
        //find hamilton cycle
        int N = adj.size();
        if (Hamiltonian_path(adj, N))
            cout << "True"<<endl;
        else
            cout << "False"<<endl;
    }
}
int intfirst(string a){
    string temp="";
    for(int i = 0 ; i < a.size() ; i++ ){
        if(a[i]!='(') temp+=a[i];
        else if(a[i]==',') break;
    }
    return stoi(temp);
}
int intsecond(string a){
    string temp="";
    int position=0;
    for(int i = 0 ; i < a.size() ; i++ ){
        if(a[i]==',') position=i;
    }
    for(int i = position+1 ; i < a.size() ; i++ ){
        if(a[i]==')') break;
        else temp+=a[i];
    }
    return stoi(temp);
}
bool Hamiltonian_path(vector<vector<int>>& adj, int N ){
    //use path to remember which point we are going
    stack <int> path;
    //to try every point to be the beginer 
    for(int i = 0 ; i < N ;i++){
        path.push(i);
        bool temp = Hamiltonian_check(path , N ,adj);
        if(temp==true){//if we find the path then return true
            return true;
        }
        path.pop();
    }
    //if all of them are wrong then means we have on solution and return false
    return false;
}
bool Hamiltonian_check(stack <int> path, int N, vector<vector<int>>& adj){
    stack <pair<int ,int>>gone;//to remember we are go to where then we can traceback to last point
    //initial the graph
    int graph[N][N];
    for(int j = 0 ; j < N ;j++){
        for(int k = 0 ; k < N ; k++){
            graph[j][k]=adj[j][k];
        }
    }
    //to remember the beginner
    int firstpoint=path.top();
    //to remember which point we have gone, since the stack can't check , I use this to check
    vector <int> ThePointWeAreGoing;
    ThePointWeAreGoing.push_back(path.top());
    vector<int>::iterator it;
    //to set the flag because we may return the beginner so that we sould to check whether we have another path 
    bool flag = false;
    for(int j = path.top() ; path.size()<N  ; j = path.top()){
        for(int k = 0 ; k < N ; k++){
            if(graph[j][k]==1){//if we have the path then go into
                it = find(ThePointWeAreGoing.begin(),ThePointWeAreGoing.end(),k);
                if(it == ThePointWeAreGoing.end()){//it means that the next point we have not gone
                    gone.push({j,k});
                    path.push(k);
                    ThePointWeAreGoing.push_back(k);
                    graph[j][k]=0;
                    graph[k][j]=0;
                    break;
                }
            }
            if(k==N-1){//if we don't have another points then we trace back to last point
                graph[gone.top().second][gone.top().first]=1;//if we are in (4,5) and meet no path then we should set (5,4)=1 and (4,5)=0 since we know (4,5) is no path , but we still can use (5,4)
                gone.pop();
                //graph[gone.top().first][gone.top().second]=0;//it means this road is dead. No path to the end
                path.pop();
                ThePointWeAreGoing.pop_back();
                if(path.top()==firstpoint){//if we first return to the beginner
                    flag=true;
                }
            }
        }
        if(path.size()==N){
            if(graph[path.top()][firstpoint]==1) return true;
            else path.pop();
        }
        if(flag){ //if we return to the beginner then we should check whether another point we can go
            for(int z = 0 ; z <N ;z++){
                if(graph[firstpoint][z]==1){//it means we have road to find
                    break;
                }
                else if(z==N-1) return false;// it means we have find out
            }
        }

    }      
    return false;//if we check all the point ,but it has no path then return false
}