
let intervals = [[8,10],[15,18],[1,4],[4,5]];
//Output: [[1,6],[8,10],[15,18]]
// for(var i=0;i<intervals.length;i++){
//     console.log(intervals[i][0],intervals[i][1]);
// }


for(let i=0;i<intervals.length-1;i++){
    for(let j=i+1;j<intervals.length;j++){
        if(intervals[i][0]>intervals[j][0]){
            let temp1 = intervals[j][0]; 
            let temp2 = intervals[j][1];
            intervals[j][0] = intervals[i][0];
            intervals[j][1] = intervals[i][1];
            intervals[i][0] = temp1;
            intervals[i][1] = temp2;
        }
    }
}

let result = [];
let n = intervals.length;
for(let i=0;i<n;i++){
   if(i<n-1 && intervals[i][1] >= intervals[i+1][0]){
            let temp1 = intervals[i][0]; 
            let temp2 = intervals[i+1][1];
            result.push([temp1,temp2]);
            i++;
   }
   else result.push([intervals[i][0],intervals[i][1]]);
}

for(var i=0;i<result.length;i++){
     console.log(result[i][0],result[i][1]);
}

