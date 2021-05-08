let http = require('http');
const URL = process.argv[2];

// try{
	http.get(URL, (res) =>{
		res.setEncoding('utf-8');
		res.on('data', (chunk) =>{
			console.log(chunk);
		})
		res.on('error', (e) => {
		console.log(e.message); //エラー時
		})
});
