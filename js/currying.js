
  //implement currying for this function

console.log(add(5)(4)(3)(2)(1)());

function add(a){
  return function (b){
  if(b) return add(a+b);
  return a;
  }
}


what is curry and make a curried version of given function

function sum(a, b, c){
  return a + b + c; 
}
function curry(fn){
  return function curriedFn(...params){
    if(params.length >= fn.length){
      return fn(...params);
    }
    else{
      return function(...next){
        return curriedFn(...params,...next);
      }
    }
  }
}

let curriedSum = curry(sum);

console.log(curriedSum(1, 2, 3));   // 6, still callable normally
console.log(curriedSum(1)(2,3));    // 6, currying of 1st arg
console.log(curriedSum(1)(2)(3));   // 6, full currying
