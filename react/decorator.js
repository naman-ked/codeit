//anotherComponent.js
import React, {Component} from "react";
import navBar from "./decorator/navBar";
@navBar()
class AnotherComponent extends Component {
  render() {
   return(
     <div>
       <p>Hello World</p>
      </div>
   )}
}
