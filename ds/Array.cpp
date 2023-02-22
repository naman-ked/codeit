/*
  Sorry to steal your line, sir. But I love it when a plan comes together.
*/        
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define F first
#define S second
using namespace std;

void updateArray(array<int,6> arr,int i,int val){
	arr[i]=val;
}


int main() {   
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif
    
    array<int,6> arr= {1,23,3,4,5,6};
    sort(arr.begin(),arr.end());  
    updateArray(arr,0,100);
    for(int i=0;i<arr.size();i++){
    	cout<<arr[i]<<endl;
    }
    arr.fill(5);
    for(int i=0;i<arr.size();i++){
      cout<<arr[i]<<endl;
    }
    return 0;
} 
