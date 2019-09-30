const testAddon = require('./build/Release/testaddon.node');


console.log('===================');
 console.log('사용가능함수들:',testAddon);
console.log('===================');

 console.log('hello 함수테스트',testAddon.hello());
 console.log('myfunction 함수테스트',testAddon.myfunction());
console.log('add 함수테스트', testAddon.add(5, 10));


module.exports = testAddon;
