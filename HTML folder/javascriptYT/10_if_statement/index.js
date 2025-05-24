// if statement = if condition is true, execute code.
//                if not, do sth else.

// let identify = false;

// if(identify){
//     console.log(`You're a human!`);
// }else{
//     console.log(`You're not a human!`);
// }

// let num = 8;
// let oddOReven = num % 2;

// if(oddOReven > 0){
//     console.log(`${num} is an odd number`);
// }
// else if(oddOReven = 0){
//     console.log(`${num} can be devided by 2.`)
// }
// else if(oddOReven = 1){
//     console.log(`${num} cann't be devided by 2.`)
// }
// else{
//     console.log(`${num} is an even number`);
// }
// ==================================================
const ageInput = document.getElementById('agetxt');
const licenseCheck = document.getElementById('licenseChk');
const submitBtn = document.getElementById('submitBtn');
const resultEle = document.getElementById('resultEle');
const resultEleTwo = document.getElementById('resultEleTwo');

submitBtn.onclick = function(){
    // Clear previous results
    resultEle.textContent = '';
    resultEleTwo.textContent = '';

    // Use .value for input field, .checked for checkbox
    const age = Number(ageInput.value);
    const hasLicense = licenseCheck.checked; // .checked is already boolean

    // Validate age input
    if (isNaN(age) || age <= 0) {
        resultEle.textContent = 'Please enter a valid age.';
        return;
    }

    if (age < 18) {
        resultEle.textContent = `You are not old enough to get a license yet.`;
        if (hasLicense) {
            resultEleTwo.textContent = `It seems you already have your license despite being under 18?`;
        } else {
            resultEleTwo.textContent = `You don't have your license yet.`;
        }
    } else {
        resultEle.textContent = `You are old enough to have a license.`;
        if (hasLicense) {
            resultEleTwo.textContent = `You already have your license.`;
        } else {
            resultEleTwo.textContent = `You don't have your license yet.`;
        }
    }
}