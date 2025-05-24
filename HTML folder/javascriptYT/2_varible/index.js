/* varible = a container that stores a value.
             Behave as if it were value it contain.

1. declaration      let x;
2. assignment       x = 100;
*/

let x;
x = 100;

let age = 21;
let grade = 9;
let gpa = 2.9;

let firstname = "mean";
let email = "mean@gmail.com";

let online = true;
let _class = false;

console.log(x);

console.log(typeof age);
console.log(`You are ${age} year olds.`);
console.log(`${grade} is your current grade.`);
console.log(`You gpa is : ${gpa}`);

console.log(typeof firstname);
console.log(`You name is ${firstname}. Your Email is (${email})`);

console.log(typeof online);
console.log(`mean is online: ${online}.`);
console.log(`We have class today: ${_class}`);

document.getElementById("p1").textContent = `You name is ${firstname}. Your Email is (${email})`;
document.getElementById("p2").textContent = `You are ${age} year olds.`;
document.getElementById("p3").textContent = `mean is online: ${online}.`;