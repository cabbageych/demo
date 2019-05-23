const fs = require('fs');
const http = require('http');
const url = require('http');

var server = http.createServer((request,response)=>{
    let pathname = url.parse(request.url).pathname;
    
});

server.listen(8080);