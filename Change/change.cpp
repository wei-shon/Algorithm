#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> coins, int amount);
int main(){
    int Set;
    cin>>Set;
    int answerset[Set];
    for(int i = 0 ; i < Set ;i++){
        int CashSetNum;
        cin>>CashSetNum;
        int cashtofind;
        cin>>cashtofind;
        vector <int> CashSet;
        int temp;
        for(int j = 0 ; j < CashSetNum ;j++){
            cin>>temp;
            CashSet.push_back(temp);
        }
        int answer=coinChange(CashSet,cashtofind);
        cout<<answer<<endl;
    }

}
int coinChange(vector<int> coins, int amount) {
    long long inf = (long long)1<<32;//very big number in order to set infinity integer
    vector<long long> DP(amount+1, inf);//sturct vector length=amout+1 and content are all 100....000(32bits)
    DP[0]=0;
    int min_coin = coins[0];
    for(int i = 1; i<coins.size(); i++){//find the minimal coin
            min_coin = min(coins[i], min_coin);
    }
    for(int i = min_coin; i<= amount; i++){
        long long min_way = inf;
        for(int coin: coins){
            if(i-coin>=0){
                min_way = min(min_way, DP[i-coin]);
            }
        }
        DP[i] = min_way+1;
    }
    return DP[amount]<inf?DP[amount]:-1;
}
/*

test data
2
3 10
1 5 7
100 50000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100

1
3 19
1 3 5 7

1
4 20
1 4 5 12
*/