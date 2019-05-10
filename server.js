'use strict'
const http = require('http');
const fs = require('fs');
const url = require('url');

var server = http.createServer((request, response) => {
    response.setHeader("Access-Control-Allow-Origin", "*");
    response.setHeader("Access-Control-Allow-Headers", "Content-Type,Access-Token");
    let pathname = url.parse(request.url).pathname;
    let messages = [];
    if (request.method == 'POST') {
        console.log("post connection...");
        request.on('data', function (message) {
            messages.push(JSON.parse(message));
        });
        request.on('end', function () {
            console.log(messages);
            //console.log(messages[0][1].name);
            response.write("购物车已成功提交!");
            response.end();
        })
    } else if (request.method == 'GET') {
        //fs.readFile(pathname.substr(1), (err, data) => {});
        let data = [
            {
                id: 111,
                type: 3,
                name: "薛定谔的滑稽",
                price: 999,
                src: url
            },
            {
                id: 222,
                type: 4,
                name: "薛定谔的滑稽02",
                price: 999,
                src: url
            },
            {
                id: 333,
                type: 1,
                name: "薛定谔的滑稽03",
                price: 999,
                src: url
            },
            {
                id: 444,
                type: 1,
                name: "薛定谔的滑稽04",
                price: 999,
                src: url
            },
            {
                id: 555,
                type: 1,
                name: "薛定谔的滑稽05",
                price: 999,
                src: url
            },
            {
                id: 666,
                type: 6,
                name: "薛定谔的滑稽06",
                price: 999,
                src: url
            }
        ];
        response.write(JSON.stringify(data));
        response.end();
    } else {
        response.end();
    }
});

server.listen(8080);