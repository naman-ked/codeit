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
