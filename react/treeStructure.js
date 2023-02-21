//DATA.json
{
  "name":"root",
  "isFolder":true,
  "subFolders":[{
    "name":"src",
    "isFolder":false
  },
  {
    "name":"assets",
    "isFolder":true,
    "subFolders":[
      {
        "name":"icons",
        "isFolder":false
      },
      {
        "name":"images",
        "isFolder":false
      }
    ]
  }]
}

//APP.js
import "./styles.css";
import data from "./data.json";
import Tree from "./Tree";

export default function App() {
  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>

      <h3>Tree Folder Structure</h3>
      <Tree data={data} />
    </div>
  );
}


//TREE.js
import { useState } from "react";
import "./styles.css";

export default function Tree(props) {
  const [click, setClick] = useState(false);
  if (props.data.isFolder) {
    return (
      <div>
        <h3
          onClick={() => {
            setClick(!click);
          }}
        >
          {props.data.name}
        </h3>
        <div style={{ display: click ? "block" : "none",paddingLeft:"30px" }}>
          {props.data.subFolders.map((folder)=>{
          return <Tree data={folder} key={folder.name} />
          })}
        </div>
      </div>
    );
    } else {
      return (
        <div>
          <h3>{props.data.name}</h3>
       </div>
     );
     }
}
