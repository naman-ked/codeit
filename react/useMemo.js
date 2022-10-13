
import { useState,useMemo } from "react";

export default function App(){

  const [one,setOne]=useState(1)
  const [two,setTwo]=useState(1)
  
  const isEven=useMemo(()=>{
      console.log("even");
      let i=0;
      while(i<99){
        let j=0;
        i=i+1;
        while(j<999){
          let k=0;
          j=j+1;
          while(k<9999){
            k=k+1;
          } 
        }
      }
      return (one%2===0)
  },[one])
  
  return(
    <div>
   <h1>useMemo</h1>
   <h2>{isEven? "Even":"Odd"}</h2>
   <button onClick={()=>{setOne(one+1)}}>Click 1</button>
   <h3>{one} , {two}</h3>
   <button onClick={()=>{setTwo(two+1)}}>Click 2</button>
   </div>
  );
}
