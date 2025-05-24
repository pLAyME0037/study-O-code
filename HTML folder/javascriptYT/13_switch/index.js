// switch an effiecent replacement for If{} else{} statement.

let day = 3;

switch(day){
    case 1:
        console.log(`It is monday.`);
        break;
    case 2:
        console.log(`It is tueday.`);
        break;
    case 3:
        console.log(`It is wenesday.`);
        break;
    case 4:
        console.log(`It is thursday.`);
        break;
    case 5:
        console.log(`It is firday.`);
        break;
    case 6:
        console.log(`It is saturday.`);
        break;
    case 7:
        console.log(`It is sunday.`);
        break;  
}

let testScore = 83;
let letterGrade;

switch(true){
    case testScore >= 90:
        letterGrade = `A`;        
        console.log(letterGrade);
        break;
    case testScore >= 80:
        letterGrade = `B`;
        console.log(letterGrade);
        break;
    case testScore >= 70:
        letterGrade = `C`;
        console.log(letterGrade);
        break;
    case testScore >= 60:
        letterGrade = `D`;
        console.log(letterGrade);
        break;
    case testScore >= 50:
        letterGrade = `E`;
        console.log(letterGrade);
        break;
    default:
        letterGrade = `F`;
        console.log(letterGrade);
        break;
}