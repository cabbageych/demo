var ws = require("nodejs-websocket")
var port = 8080;
const http = require('http');
const fs = require('fs');
const url = require('url');

var httpServer = http.createServer((request, response) => {
	let pathname = url.parse(request.url).pathname;
	//console.log(pathname.substr(1));
	fs.readFile(pathname.substr(1), (err, data) => {
		if (err) {
			response.writeHead(404, { "Content-Type": "text/html" });
		} else {
			var reg = /jpg|png|gif|jpeg|bmp/;
			if (reg.test(pathname)) {
				response.writeHead(200, { "Content-Type": "image/jpeg" });
				response.write(data);
			} else {
				response.writeHead(200, { "Content-Type": "text/html" });
				response.write(data.toString());
			}
		}
		response.end();
	})
});
httpServer.listen(8081);

// 连接池
var clients = [];
//为每个连接者命名并存在name数组中
let name = [];

// Scream server example: "hi" -> "HI!!!"
var server = ws.createServer(function (conn) {
	//连接者名字为Date().getTime()取第8位开始往后的数字
	let data = new Date().getTime();
	data = data.toString();
	conn.name = data.substr(8);
	name.push(conn.name);

	//将连接加入连接池
	clients.push(conn);

	//给客户端返回生成的名字
	conn.send(JSON.stringify({ type: 0, name: conn.name }));

	//动态更新在线成员
	clients.forEach(function (wsTemp) {
		wsTemp.send(JSON.stringify({ type: 1, memberList: name }));
	});

	//console.log("New connection");
	//console.log(clients.length);
	conn.on("text", function (str) {
		//test
		if (str == '{"ping":"1"}') {
			conn.send('alive!');
			return ;
		}


		//广播消息
		clients.forEach(function (wsTemp) {
			//if(wsTemp !=ws){
			wsTemp.send(JSON.stringify({ type: 2, name: conn.name, message: str }));
			//}
		})
	})
	conn.on("close", function (code, reason) {
		clients = clients.filter(function (wsTemp) {
			return wsTemp != conn;
		});
		name = name.filter(function (temp) {
			return temp != conn.name;
		});
		clients.forEach(function (wsTemp) {
			wsTemp.send(JSON.stringify({ type: 1, memberList: name }));
		})
	})
	conn.on("error", function (err) {
		//console.log("handdle error");
		//console.log(err);
	})
}).listen(port);
