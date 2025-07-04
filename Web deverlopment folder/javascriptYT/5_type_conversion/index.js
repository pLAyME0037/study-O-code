// type conversion = change the datatype of a value to another (strings, numbers, boolens) 

let age = window.prompt("How old are you?");
age = Number(age);
age+=1;

console.log(typeof age, age);