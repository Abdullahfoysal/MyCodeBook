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
#define mx 1000010
int sp[mx];

void sufixWhichIsAlsoPrefix(string str,int sp[]){

	for(int i=1,j=0;i<str.size();i++){
		if(str[i]==str[j]){
			sp[i]+=(j+1);
			j++;
		}
		else{
			while(j-1>=0){
				if(str[i]==str[sp[j-1]]){
					sp[i]+=j-1+1;
					j=j-1;
					break;
				}
				j=sp[j-1];
			}
		}
	}
}
void kmp(string str,string pat,int sp[]){
	sufixWhichIsAlsoPrefix(pat,sp);
	bool flag=true;

	for(int i=0,j=0;i<str.size();i++){

		if(str[i]==pat[j]){
			j++;	
		}
		else{
			if(j-1>=0){
				j=sp[j-1];
				if(str[i]==pat[j]){
					j++;
				}
			}	
		}
///if found any matched
		if(j==pat.size()){
				cout<<i+2-pat.size()<<" ";
				j=sp[j-1];
				flag=false;
				//cout<<"#"<<j<<endl;
			}
	}

	if(flag)cout<<"Not Found\n";


}

int main(int argc, char const *argv[])
{
	string str,pat;

	cin>>str;
	cin>>pat;
	kmp(str,pat,sp);

	

	return 0;
}





