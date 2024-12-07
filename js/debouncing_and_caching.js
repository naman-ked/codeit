//JS Code 

import "./styles.css";

var timer;
let cache = {"abcd":"first imput", "bcde":"second input"};

function handleSearch(val){

   if(timer) clearTimeout(timer);
   timer = setTimeout(()=>{
     if(val!="" && val in cache){
       console.time();
       console.log(cache[val]);
       console.timeEnd();
     }
     else if(val!=""){
       try{
       console.time();
       setTimeout(()=>{
         console.log("APi response",val);
       },5000);
       console.timeEnd();
       }
       catch{
         console.log(err);
       }
       //fetch().then().catch((err)=>{


       //})
     }
    
   },3000);
}


var typed =  document.getElementById("search");

typed.addEventListener("input", (event)=>{
 handleSearch(event.target.value)
})

// HTML Code
<!DOCTYPE html>
<html>
 <head>
   <title>Parcel Sandbox</title>
   <meta charset="UTF-8" />
 </head>


 <body>
   <div id="app">
      <label> Search bar  </label> &nbsp;&nbsp;
     <input type="text" id="search" />
     <div id="dropdown"></div>
   </div>


   <script src="src/index.js"></script>
 </body>
</html>
