// const = a variable that can not be change.

const PI = 3.14159;
let radius;
let circumference;

document.getElementById("submitButton").onclick = function(){
    radius = document.getElementById("radiusOfaCircletxt").value;
    radius = Number(radius);
    circumference = 2 * PI * radius;
    document.getElementById("output").textContent = circumference + `cm`;
}