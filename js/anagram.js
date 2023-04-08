// string anagram problem
let s1="hello",s2="lyeoh" //input
var arr1 = new Array(26).fill(0);
var arr2 = new Array(26).fill(0);
if(s1.length!=s2.length){
    console.log("False")
}
else {
for(var i=0;i<s1.length;i++){
    arr1[s1.charCodeAt(i)-97]+=1;
    arr2[s2.charCodeAt(i)-97]+=1;
}
for(var i=0;i<26;i++){
 if(arr1[i]!=arr2[i]){
     console.log(false);
     arr1[0]=-1;
     break;
 }
}
 if(arr1[0]!=-1)
 console.log(true);
}
// Output : false
