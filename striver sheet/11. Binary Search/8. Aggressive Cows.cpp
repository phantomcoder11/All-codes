/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
bool isValid(int mid,int n,int c,int pos[]){
    int lastcow=pos[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(pos[i]-lastcow>=mid){
            count++;
            lastcow=pos[i];
        }
    }
    return (count>=c);
	
}
void solve(){
	int n,c;
	cin>>n>>c;
	int pos[n];
	for(int i=0;i<n;i++){
		cin>>pos[i];
	}
	int ans=-1;
	sort(pos,pos+n);
	int low=1,high=pos[n-1]-pos[0];
	while(low<=high){
		int mid=(low+high)/2;
		if(isValid(mid,n,c,pos)){
			low=mid+1;
			ans=mid;
		}else high=mid-1;
	}

	cout<<high<<endl;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}