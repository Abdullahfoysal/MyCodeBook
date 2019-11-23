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
#define character 'A'//if number '0' || small 'a' type of character to hash
#define base 26
#define mod (1000000000+9)
#define ll long long int
ll bigMod(int a,int b,int m);

ll Hashing(string key){
	ll result=0;
	for(int i=0;i<key.size();i++){
		int d=key[i]-character;
		 d++;

		result+=(d*bigMod(base,i,mod))%mod;
		// cout<<(d*bigMod(base,i,mod))%mod<<endl;
		result=result%mod;

	}
	return result;

}

ll bigMod(int a,int b,int m){//a==base,b==power,m=mod==(total number of your number system)
	ll r=1;
	if(b==0)return 1;
	else r=bigMod(a,b/2,m);

	if(b%2==0) 
		r=(r*r)%m;
	else r=(r*r*a)%m;
	// cout<<r<<" "<<endl;

	return r;
}

int main(int argc, char const *argv[])
{

	//hashing for matching two string equal
	
		string str,p;
		
		cin>>str;
		cin>>p;
		//Get unique value with Base(totall unique char in string)
		ll value1=Hashing(str);
		ll value2=Hashing(p);

		//complexity bigO(1)
		if(value1==value2)cout<<"Matched string"<<endl;
		else cout<<"Not matching"<<endl;
		// cout<<value<<endl;
		
	
	return 0;
}





