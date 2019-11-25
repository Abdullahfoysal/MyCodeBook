#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>

using namespace std;
#define mx 100000000
#define bit 32
int prime[mx/32];
bool check(int N,int pos){
	return (bool)(N & 1<<pos);
}

int Change(int N,int pos){

	return (N | 1<<pos);

}

void seive(){
	for(int i=3;i*i<=mx;i+=2){
		if(check(prime[i/bit],i%32)==false){
			for(int j=i*i;j<=mx;j+=(i<<1)){
				prime[j/bit]=Change(prime[j/bit],j%bit);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	seive();
	std::vector<int> v;
	v.push_back(-1);
	v.push_back(2);
	for(int i=3;i<mx;i+=2){
		if(!check(prime[i/bit],i%bit)){
				v.push_back(i);
		}
	}

	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<v[n]<<endl;
	}


	

	
	return 0;
}





