var i;
var res;

i = 0;
res = 0;
const fs = require('fs');
fs.readFile(process.argv[2], 'utf-8', (err, data)=>{
	if (err)
	{
		console.log(err.message);
	}
	// try{
		while(i < data.length)
		{
			if (data[i] == '\n')
			{
				res++
			}
			i++
		}
		console.log(res)
	// }
	// catch(err){
	// 	console.log(err.message);
	// }
})
