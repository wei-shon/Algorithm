# include <iostream>
# include <vector>
# include <queue>

using namespace std;

typedef struct node{//因為vector不能儲存二維陣列 所以我自己新建一個node來儲存 8-拼圖 
    int map[3][3];
}node;
//下面的函式是用來判斷8-拼圖是否是我們想要的 8-拼圖
bool check(queue <node*> &GoMap, vector<node*> &Record ,int TrueMap[3][3],    int WhereIsZeroRow, int WhereIsZeroCol, string command);

int main(){
    queue <node*> GoMap;//用來判斷下一個搜尋的對象
    vector<node*> Record;//紀錄已經做過的 8-拼圖
    node *temp = new node;//用來儲存第一個 8-拼圖
    int Map[3][3];//紀錄8-拼圖的樣子
    int TrueMap[3][3];//紀錄我們想要8-拼圖的樣子
    int WhereIsZeroRow;//紀錄0(8-拼圖的空格)在row的位置
    int WhereIsZeroCol;//紀錄0(8-拼圖的空格)在col的位置
    for(int i = 0 ; i < 3 ; i++){//輸入8-拼圖起始狀態 以及 放進第一個node
        for(int j = 0 ; j < 3 ; j++){
            cin>>Map[i][j];
            temp->map[i][j]=Map[i][j];
        }
    }
    Record.push_back(temp);//紀錄8-拼圖放入
    GoMap.push(temp);//把第一個node(8-拼圖)放入queue
    for(int i = 0 ; i < 3 ; i++){//輸入我們想要8-拼圖的樣子
        for(int j = 0 ; j < 3 ; j++){
            cin>>TrueMap[i][j];
        }
    }


    //下面為開始尋找8-拼圖
    //用bool來判斷上下左右移動之後 是否為最終的8-拼圖
    bool up;
    bool down;
    bool right;
    bool left;
    while(GoMap.size()>0){//用來判斷queue是否還有要尋找的8-拼圖
        int checkcount=0;//紀錄在queue的8-拼圖跟最後狀態有幾個是一樣的
        //output the map
        node *wow = new node;//建立新的node 用來儲存queue的第一個node
        wow=GoMap.front();

        for(int i = 0 ; i < 3 ; i++){//輸出queue中的第一個node 並且紀錄有幾個點是跟最後的8-拼圖一樣
            for(int j = 0 ; j < 3 ; j++){
                if(j==2)cout<<wow->map[i][j]<<endl;
                else cout<<wow->map[i][j]<<" ";
                if(wow->map[i][j]==TrueMap[i][j]) checkcount++;
            }
            
        }
        //check whether output map is the answer or not
        if(checkcount == 9){//如果有9個都是 一樣的 則跳出迴圈，因為我們已經找到了
            break;
        }
        //find where is zero 尋找0是在哪裡
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(wow->map[i][j]==0){WhereIsZeroRow=i;WhereIsZeroCol=j;}
            }
        }        
        if(WhereIsZeroRow==0){
            if(WhereIsZeroCol==0){//如果0在(0,0) 則只能往右、下移動
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
            }
            else if(WhereIsZeroCol==1){//如果0在(0,1) 則只能往右、下、左移動
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }
            else if(WhereIsZeroCol==2){//如果0在(0,2)則只能往下、左移動
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }            
        }
        else if(WhereIsZeroRow==1){
            if(WhereIsZeroCol==0){//如果0在(1,0)則只能往上、右、下移動
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
            }
            else if(WhereIsZeroCol==1){//如果0在(1,1) 都可以移動
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }
            else if(WhereIsZeroCol==2){//如果0在(1,2) 則只能往上、左、下移動
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }  
        }
        else if(WhereIsZeroRow==2){
            if(WhereIsZeroCol==0){//如果0在(2,0) 則只能往上、右移動
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
            }
            else if(WhereIsZeroCol==1){//如果0在(2,1) 則只能往上、右、左移動
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }
            else if(WhereIsZeroCol==2){//如果0在(2,2)則只能往上、左移動
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }  
        }
        GoMap.pop();//將queue中的第一個點丟掉
    }
}
bool check(queue <node*> &GoMap, vector<node*> &Record ,int TrueMap[3][3],int WhereIsZeroRow, int WhereIsZeroCol , string command){
    int NextMap[3][3];//此為預判移動位置的8-拼圖
    bool flag=true;//用來記錄移動後的8-拼圖是否已經走過了
    for(int i = 0 ; i < 3 ; i++){//先將原本的8-拼圖放到預判移動的8-拼圖裡
        for(int j = 0 ; j < 3 ; j++){
            NextMap[i][j]=GoMap.front()->map[i][j];
        }
    }    
    //確認要移動的位置    
    if(command == "up"){//若為上 則交換row 和 row-1 的位置
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow-1][WhereIsZeroCol]);
    }
    else if(command == "down"){//若為下 則交換row 和 row+1 的位置
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow+1][WhereIsZeroCol]);
    }
    else if(command == "right"){//若為右 則交換 col 和 col-1 的位置
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow][WhereIsZeroCol+1]);
    }
    else if(command == "left"){//若為左 則交換 col 和 col+1 的位置
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow][WhereIsZeroCol-1]);
    }
    //建立一個新node 等等要用來放入queue和用來記錄的 vector
    node *temp =new node;

    //set node *temp 把預判的8-拼圖放到temp裡面
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            temp->map[i][j]=NextMap[i][j];
        }
    }

    for(int k = 0 ; k < Record.size() ;k++){//去檢查預判的8-拼圖是否有出現在vector裡面
        int count = 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(NextMap[i][j]==Record[k]->map[i][j]) count++;
            }
        }
        if(count==9){ flag=false; return flag;}//如果有，則直接回傳false
    }    
    //若沒有，則把預判的8-拼圖放入queue跟vector裡面
    GoMap.push(temp);
    Record.push_back(temp);
    return flag;//回傳true
}