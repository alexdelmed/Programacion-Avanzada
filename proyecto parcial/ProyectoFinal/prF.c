#include <iostream>
#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define mod 1000000007

typedef long long int lli;
using namespace std;


lli dp[100010][4][4];

int len;
string s;
int cou=0;
int calls=0;

lli solve(int idx,int ub1,int ub2){
	if(idx>len) return 0;
	if(idx==len && ub2 && ub1) {
		return 1;
	}
	else if(idx==len) {
	return 0;
	}
	else if(dp[idx][ub1][ub2]!=-1) return dp[idx][ub1][ub2]; 
	lli ans=0;
if(ub1==0){
	for(int i=s[idx];i<='Z';i++)
{     
if(s[idx]<i){
	ans=(ans+solve(idx+1,1,1))%mod;
}
if(s[idx]==(i)){
	ans=(ans+solve(idx+1,0,ub2))%mod;

}
}
}

else{
for(int i='A';i<='Z';i++){
	if(s[idx]<i){
		ans=(ans+solve(idx+1,1,1))%mod;
	}
	else if(s[idx]>i){
		ans=(ans+solve(idx+1,1,0))%mod;
}
else {
ans=(ans+solve(idx+1,1,ub2))%mod;
}
}
}

//cout<<idx<<" "<<ans<<endl;

dp[idx][ub1][ub2]=ans;

return ans;

}

int main() {
int t;

{
memset(dp,-1,sizeof dp);
cin>>s;
len=s.length();
string  ss="";
lli ans=solve(0,0,0);
cout<<ans<<endl;

}

return 0;

}   
