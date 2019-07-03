const http = require('http');
const url = require('url');
const fs = requrie('fs');

var server = http.createServer((request,response)=>{
    let pathname = url.parse(request.url).pathname;
    pathname = pathname.substr(1);
    fs.readFile(pathname,(err,data)=>{
        if(err){
            response.writeHead(404,"Content-Type:text/html");
        }else{
            response.writeHead(200,"Content-Type:text/html");
            response.write(data.toString());
        }
        response.end();
    });
});

server.listen(8080);