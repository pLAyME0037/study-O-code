// User Input
// 1. windows prompt

// let username;
// username = window.prompt("What is your username?");
// console.log(username);

// 2. HTML textbox

document.getElementById("mysubmit").onclick = function(){
    username = document.getElementById("mytext").value;
    document.getElementById("myh1").textContent = `Hello, ${username}`;
}