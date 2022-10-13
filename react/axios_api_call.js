//Class component

//Functional component
import axios from "axios";
import { useEffect, useState } from "react";
import "./styles.css";

export default function App() {
  const [joke, setJoke] = useState({});

  useEffect(() => {
    console.log("componentDidMount");
    async function fetchData() {
    await axios.get("https://reqres.in/api/users?page=2")
        .then(res=>{
          console.log(res.data.data[0])
        setJoke(res.data.data[0]);
      }).catch(err=> {
        console.log(err);
      })
  }
  fetchData();
  },[]);

  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>

      <h3>Fetch data from API</h3>
      <h4>{joke.id}</h4>
      <h4>{joke.email}</h4>
    </div>
  );
}
