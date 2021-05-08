var i;
var res;

i = 0;
res = 0;
const fs = require('fs');
let text = fs.readFileSync(process.argv[2], 'utf-8');

while(text[i])
{
	if (text[i] == '\n')
		res++
	i++
}
console.log(res)