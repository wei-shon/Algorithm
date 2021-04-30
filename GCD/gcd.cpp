#include <iostream>
using namespace std;

int main() {
	int times ;
	cin>>times;
	for (int i = 0 ; i < times ; i++){
		int first;
		int second;
		cin>>first;
		cin>>second;
		int third;
		if(second > first){
			third=first;
			first=second;
			second=third;
		}
		int ans=0;
		for(int j = 1; j <= second ;j++){
			if(first%j==0 && second%j==0){
				ans=j;
			}
		}
		cout<<ans<<endl;
	}
}
