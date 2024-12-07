TWO PAIR SUM IN JS

var obj = {};
var nums = [-3,7,11,15];
var target = 8;
for(var i = 0; i < nums.length; i++){
    var diff1 = target-nums[i]; 
    if(obj[diff1]!=undefined ){
        console.log(obj[diff1],i);
    }
    else obj[nums[i]] = i;
}
