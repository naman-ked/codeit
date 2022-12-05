let arr = [1,2,[3,4,5,6],[7,8,[9,10]]];
//console.log(arr.flat(2))
counter=2;
const myFlat = (arr,counter) => {
    let result= [];
    arr.map((a)=>{
      if(Array.isArray(a) && counter>0) result.push(...myFlat(a,counter-1));
      else result.push(a)
    });
    return result;
}
console.log(myFlat(arr,counter));
