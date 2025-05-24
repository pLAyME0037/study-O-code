// string Medthods = allow you to manipulate and work with text (String).
let username = `sokmean`;

console.log(`find the input letter: `,username.indexOf(`m`));

console.log(`find the input value: `,username.charAt(0));

console.log(`find the last of input value: `,username.lastIndexOf(`a`));

console.log(`the full lenght of input value: `, username.length);

let usernametwo = `      sokmeanchhim        `;
usernametwo = usernametwo.trim();
console.log(`get rid of space before or after: `, usernametwo);

let usernameThree = `Sokmean`;
usernameThree = usernameThree.toUpperCase();
console.log(`To upper case: `, usernameThree);

let username4 = `SokMean`;
username4 = username4.toLowerCase();
console.log(`To lower case: `, username4);

let username5 = `Sokmean`;
username5 = username5.repeat(4);
console.log(`repeat strings: `, username5);

let username6 = ` Sokmean`;
let result = username6.startsWith(` `);
console.log(`string start with( ): `, result);
if(result){
    console.log(`your user name can't be start with a space.`);
}else{
    console.log(username6);
}

let username7 = `Sokmean`;
let result2 = username7.endsWith(`.`);
console.log(`string end with(.): `, result2);
if(result2){
    console.log(username7);
}else{
    console.log(`your user name need to end with a (.)`);
}
 
let username8 = `Sok mean`;
let result3 = username8.includes(` `);
console.log(`string start with( ): `, result3);
if(result3){
    console.log(`your user name can't include a space.`);
}else{
    console.log(username8);
}

let phoneNum = `012 747 445`;
phoneNum = phoneNum.replaceAll(` `, `-`);
console.log(`replace spaces with(-)`, phoneNum);

let phoneNum2 = `012 747 445`;
phoneNum2 = phoneNum2.padStart(15, `+`);
console.log(`padStart replace spaces with(+)`, phoneNum2);

let phoneNum3 = `012 747 445`;
phoneNum3 = phoneNum3.padEnd(15, `+`);
console.log(`padEnd replace spaces with(+)`, phoneNum3);
