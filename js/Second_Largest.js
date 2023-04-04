const input=[1,4,7,7,4,7];

let h=0;
let h1=0;

input.map((i)=>{
    if(i>h){
        h1=h;
        h=i;
    }
    else if(i<h && i>h1){
        h1=i;
    }
});

console.log(h1,h);
