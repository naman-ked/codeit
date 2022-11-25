/** getDerivedStateFromProps(props, state) is a static method that is called just before render() method in both mounting and updating phase in React. 
It takes updated props and the current state as arguments. **/

import React from 'react';
import ReactDOM from 'react-dom';
  
class App extends React.Component {
  render() {
    return (
      <div>
      <Child name = "sachin"></Child>
      </div>
    )
  }
}
  
class Child extends React.Component{
    constructor(props){
        super(props);
        this.state = { name: "kapil"};
    }
    static getDerivedStateFromProps(props, state) {
        if(props.name !== state.name){
            //Change in props
            return{
                name: props.name
            };
        }
        return null; // No change to state
    }
    /* if props changes then after getDerivedStateFromProps
       method, state will look something like 
  
    {
        name: props.name
    }
    */
    render(){
       return (
        <div> My name is {this.state.name }</div>
       )
    }
}
                      
export default App;
