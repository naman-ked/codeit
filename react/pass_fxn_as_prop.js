import {useState} from 'react';

function Child({handleClick}) {
  return <button onClick={handleClick}>Increment</button>;
}

export default function App() {
  const [count, setCount] = useState(0);

  function handleClick(event,num) {
    setCount(count + 1 + num);
  }

  return (
    <div>
      <h2>Count is: {count}</h2>

      <Child handleClick={(event)=>{handleClick(event,100)}} />
    </div>
  );
}


//Child to parent passing data

import { useState } from "react";
import "./styles.css";

function Child({ click }) {
  return <button onClick={()=>click(210)}>Click me!</button>;
}

export default function App() {
  const [one, setOne] = useState(1);
  const click = (num) => {
    setOne(one + num);
  };
  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>
      <Child click={click} />
      <h3>{one}</h3>
    </div>
  );
}

