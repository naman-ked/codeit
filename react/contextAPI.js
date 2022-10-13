//Parent component
import {  createContext, useState } from "react";
import "./styles.css";
import A from "./A";
import B from "./B";

export const myContext =  createContext();

export default function App() {
  const [name] = useState("Naman");
  const [roll] = useState(29);
  return (
    <div className="App">
      <h1>Provider App</h1>
      <myContext.Provider value={{name,roll}}>
        <A />
        <B />
      </myContext.Provider>
      
    </div>
  );
}
//Child component A & B

import {myContext} from "./App";
export default function A() {
  return (
    <div>
      <h1>A component</h1>
      <myContext.Consumer>
      {data=><>
      <h3>{data.name}</h3>
      <h2>{data.roll}</h2>
      </>
      }
      </myContext.Consumer>
      
    </div>
  );
}


import {myContext} from "./App";

export default function B({ name }) {
  return (
    <div>
      <h1>B component</h1>
      <myContext.Consumer>
      {data=><>
      <h3>{data.name}</h3>
      <h2>{data.roll}</h2>
      </>
      }
      </myContext.Consumer>
    </div>
  );
}
