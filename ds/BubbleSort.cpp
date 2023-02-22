/*
  Sorry to steal your line, sir. But I love it when a plan comes together.
*/        
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define F first
#define S second
using namespace std;

void solve(){
      int n;
      cin>>n;
      int arr[n];
      int i , j;
      for(i=0;i<n;i++){
      	cin>>arr[i];
      }
      //bubble sort
      bool swapped;
      for(int i=0;i<n-1;i++){
      	for(int j=0;j<n-i-1;j++){
      		if(arr[j]>arr[j+1]){
      			swap(arr[j],arr[j+1]);
      			swapped=true;
      		}
      	}
      	if(swapped== false)
      		break;
      }
       for(i=0;i<n;i++){
      	cout<<arr[i]<<endl;
      }
}

int main() {   
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif
    
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
} 
