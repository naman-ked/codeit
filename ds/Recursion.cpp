//FIBONACCI
#include<iostream>
#include<vector>
using namespace std;
//TOP DOWN APPROACH
int fib(int n,vector<int> &result){
    if(result[n]!=-1){
    	return result[n];
    }
    return result[n]= fib(n-1,result) + fib(n-2,result);
}

int main(){
	int n=10;
	vector<int> result(n+1,-1);
	result[0]=0;
	result[1]=1;
	cout<<fib(n,result);
	return 0;
}

//BOTTOM UP APPROACH use iterative fib[i]=fib[i-1]+fib[i-2];
