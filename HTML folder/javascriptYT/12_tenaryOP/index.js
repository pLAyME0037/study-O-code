// tenary operator = a shortcut to if else statements help to assign a varible base on a "condition ? codeIfTrue : codeIfFalse";

let age = 21;
let ageConfirmation = age >= 18 ? `you are an adult.` : `you still an miner.`;
console.log(ageConfirmation);

let time = 15;
let greeting = time < 12 ? `good morning` : `good afternoon`;
console.log(greeting);

let stud = true;
let studMessage = stud ? `you are a student` : `you aren't a student.`;
console.log(studMessage);

let percusceAmount = 120;
let discount = percusceAmount >= 100 ? 10 : 0;
console.log(`your total is $${percusceAmount - percusceAmount * (discount/100)}`)