// Random Number Generator

// let randomNum = Math.floor(Math.random() * 6) + 1;

// const min = 5;
// const max = 10;
// let randomNumTwo = Math.floor(Math.random() * max) + min;

// console.log(randomNum, randomNumTwo);

const rollBtn = document.getElementById("rollBtn");
const rollLbOne = document.getElementById("rollLbOne");
const rollLbTwo = document.getElementById("rollLbTwo");
const rollLbThree = document.getElementById("rollLbThree");
const min = 1;
const max = 6;
let randomNumOne;
let randomNumTwo;
let randomNumThree;

rollBtn.onclick = function(){
    randomNumOne = Math.floor(Math.random() * max) + min;
    randomNumTwo = Math.floor(Math.random() * max) + min;
    randomNumThree = Math.floor(Math.random() * max) + min;
    rollLbOne.textContent = randomNumOne;
    rollLbTwo.textContent = randomNumTwo;
    rollLbThree.textContent = randomNumThree;
}