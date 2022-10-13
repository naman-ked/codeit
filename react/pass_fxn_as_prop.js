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
