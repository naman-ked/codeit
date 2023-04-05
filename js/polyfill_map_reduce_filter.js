let arr=[1,2,3,4,5,6,7];

Array.prototype.myMap = function(cb){
    let result=[];
    for(let i=0;i<this.length;i++){
        result.push(cb(this[i]));
    }
    return result;
}

const res=arr.myMap((a)=>a*2);
console.log(res);   // [ 2,  4,  6, 8, 10, 12, 14]

Array.prototype.myFilter = function(cb){
    let result=[];
    for(let i=0;i<this.length;i++){
        if(cb(this[i]))
        result.push(this[i]);
    }
    return result;
}

const res=arr.myFilter((a)=>a>2);
console.log(res);


Array.prototype.myReduce = function(cb,initial){
    let acc=initial==='undefined' ? initial: this[0];
    for(let i=0;i<this.length;i++){
        acc=cb(acc,this[i]);
    }
    return acc;
}

const res=arr.myReduce((acc,curr)=>{
    acc=acc+curr;
    return acc;
},0);

console.log(res); //29
