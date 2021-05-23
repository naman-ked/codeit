//Count pairs with given sum
// Time: O(n)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int pairSum(vector<int> arr,int k){
	//Logic 
    int sum=0;
    unordered_map<int,int> s;
    for(int i=0;i<arr.size();i++){
       int x=k-arr[i];
       if (!(s.find(x) == s.end())){
         sum+=s[x];    
       }
       if (s.find(arr[i]) == s.end()) s.insert(make_pair(arr[i],1));
       else s[arr[i]]++;
    }
    return sum;
}

int main(){

	vector<int> arr{1, 1, 1, 1};
	int S = 2;

	int p = pairSum(arr,S);
	if(p==0){
		cout<<"No such pair";
	}
	else{
        cout<<p;
		//cout<<p[0]<<","<<p[1]<<endl;
	}

	return 0;
}
