// counting unique numbers
arr=[1,1,2,2,3,4,4,5,6,7,8,8];
count=1;
for(var i=1;i<arr.length;i++){
    if(arr[i]!=arr[i-1]){
        count+=1;
    }
}
console.log(count);
//Output : 8
