// string slicing = create a sub string from a portion of another string.

                    // String.slice(Start,end)

const fullname = `sok mean`;

// let firstname = fullname.slice(0, 3);
// let lastname = fullname.slice(4);

let firstchar = fullname.slice(0, 1);
let lastchar = fullname.slice(-1);

let firstname = fullname.slice(0, fullname.indexOf(` `));
let lastname = fullname.slice(fullname.indexOf(` `) + 1);

console.log(firstname);
console.log(lastname);
console.log(`the start letter:`, firstchar);
console.log(`the end letter:`,lastchar);

const email = `mean@gmail.com`;

let username = email.slice(0 ,email.indexOf(`@`));
let companyMailSevice = email.slice(email.indexOf(`@`));

console.log(username);
console.log(companyMailSevice);