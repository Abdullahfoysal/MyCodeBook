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
#define mx 1000
#define bit 32
#define scan(a)({scanf("%d",&a);})
int prime[mx/bit];

int gcd(int a,int b) //a>b
{
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
bool isPrime(int N,int pos){

	return (bool)(N & 1<<pos);
}
int SetPrime(int N,int pos){
	return (N |1<<pos);
}

void sieve(){
	for(int i=3;i*i<=mx;i+=2){
		if(!isPrime(prime[i/bit],i%bit)){
			for(int j=i*i;j<=mx;j+=(i<<1)){
				prime[j/bit]=SetPrime(prime[j/bit],j%bit);
			}
		}
	}
}

int DivisorCount(int divisor){
	int totalDivisor=1;
		for(int i=2;i*i<=divisor;i++){
			int count=0;

			if(!isPrime(prime[i/bit],i%bit)){
				while(divisor%i==0){

					divisor/=i;
					count++;
				}
				totalDivisor*=(count+1);

			}
		}
		if(divisor>1) totalDivisor=(totalDivisor << 1);

		return totalDivisor;
}

int main(int argc, char const *argv[])
{
	sieve();
	int t;
	scan(t);
	while(t--){
		int a,b;
		scan(a);scan(b);
		if(a<b)swap(a,b);
		int divisor=gcd(a,b);

		// cout<<DivisorCount(divisor)<<endl;
		printf("%d\n",DivisorCount(divisor));

		

	}

	
	return 0;
}


