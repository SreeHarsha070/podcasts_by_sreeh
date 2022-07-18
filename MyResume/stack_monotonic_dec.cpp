// https://leetcode.com/problems/daily-temperatures/
// 739. Daily Temperatures

#include<bits/stdc++.h>
using namespace std;
vector<int>DailyTemp(int n,int temps[]){
	stack<int>st;
	vector<int>res(n,0);
	st.push(n-1);
	for(int i=n-2;i>=0;i--){
		// if val at top less than val I get now
		while(!st.empty() and temps[st.top()<temps[i]] )
		{
			st.pop();
		}
		if (!st.empty() and temps[st.top()]>temps[i]){
			res[i]=st.top()-i;
		}
		st.push(i);

	}
	return res;
}

int main(){
	int n;
	cin>>n;
	int temps[n]={0};
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		temps[i]=temp;
	}
	vector<int>ans=DailyTemp(n,temps);
	for(auto it:ans){
		cout<<it<<endl;
	}

	return 0;
}