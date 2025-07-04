// .checked = property that determines the checked state of an HTML checkbox or radio button element.

const confirm_Chb = document.getElementById("confirm_Chb");
const visa_Btn = document.getElementById("visa_Btn");
const mastercard_Btn = document.getElementById("mastercard_Btn");
const paypal_Btn = document.getElementById("paypal_Btn");
const submit_Btn = document.getElementById("submit_Btn");
const submit_result = document.getElementById("submit_result");
const payment_result = document.getElementById("payment_result");

submit_Btn.onclick = function(){
    if(confirm_Chb.checked){
        submit_result.textContent = `You have agree to term and condition.`;
    }
    else{
        submit_result.textContent = `You have to check on term and condition first before contionus.`;
    }

    if(visa_Btn.checked){
        payment_result.textContent = `Procceding paying with visa card.`;
    }
    else if(mastercard_Btn.checked){
        payment_result.textContent = `Procceding paying with mastercard card.`;
    }
    else if(paypal_Btn.checked){
        payment_result.textContent = `Procceding paying with paypal card.`;
    }
    else{
        payment_result.textContent = `You must select payment type.`;
    }
}