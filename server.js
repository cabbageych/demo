'use strict'
const http = require('http');
const fs = require('fs');
const url = require('url');

var server = http.createServer((request, response) => {
    response.setHeader("Access-Control-Allow-Origin", "*");
    response.setHeader("Access-Control-Allow-Headers", "Content-Type,Access-Token");
    let pathname = url.parse(request.url).pathname;
    //console.log(pathname);
    let messages = [];
    if (request.method == 'POST') {
        //console.log("post connection...");
        request.on('data', function (message) {
            messages.push(JSON.parse(message));
        });
        request.on('end', function () {
            //console.log(messages);
            //console.log(messages[0][1].name);
            response.write("购物车已成功提交!");
            response.end();
        })
    } else if (request.method == 'GET') {
        if (pathname.substr(1) != '') {
            fs.readFile(pathname.substr(1), (err, data) => {
                if (err) {
                    response.writeHead(404, ("Content-Type", "text/html"));
                } else {
                    let reg = /jpg|png|jpeg|gif/;
                    if (reg.test(pathname)) {
                        response.writeHead(200, ("Content-Type", "image/jpg"));
                        response.write(data);
                    } else {
                        response.writeHead(200, ("Content-Type", "text/html"));
                        response.write(data.toString());
                    }

                }
                response.end();
            })
        } else {
            let imageUrl = 'images/huaji.jpg';
            //fs.readFile(pathname.substr(1), (err, data) => {});
            let data = [
                {
                    id: 111,
                    type: 3,
                    name: "薛定谔的滑稽",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 222,
                    type: 4,
                    name: "薛定谔的滑稽02",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 333,
                    type: 1,
                    name: "薛定谔的滑稽03",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 444,
                    type: 2,
                    name: "薛定谔的滑稽04",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 555,
                    type: 1,
                    name: "薛定谔的滑稽05",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 666,
                    type: 6,
                    name: "薛定谔的滑稽06",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 777,
                    type: 1,
                    name: "薛定谔的滑稽04",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 888,
                    type: 5,
                    name: "薛定谔的滑稽05",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 999,
                    type: 6,
                    name: "薛定谔的滑稽06",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 999,
                    type: 7,
                    name: "薛定谔的滑稽06",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 888,
                    type: 5,
                    name: "薛定谔的滑稽05",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 999,
                    type: 6,
                    name: "薛定谔的滑稽06",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                },
                {
                    id: 999,
                    type: 2,
                    name: "薛定谔的滑稽06",
                    price: 999,
                    url: imageUrl,
                    description: "emmmm des for test!",
                    totalCount: 99,
                    shopName: "cabbage"
                }
            ];
            response.write(JSON.stringify(data));
            response.end();
        }
    } else {
        response.end();
    }
});

server.listen(8082);

//主页请求
/*
data = {
    id:'',  //商品id
    type:'',  //商品类别编码
    name:'',  //商品名称
    price:'',  //商品价格
    des:'',   //商品描述
    totalCount:'',   //商品剩余库存
    url:'',    //商品图片url
    sellerName:'' //商家姓名（如果有商店名就用店名没有就用商家姓名）
}


//购物车提交
data = {
    id:'',   //商品id
    type:'',  //商品类别编码
    name:'',   //商品名称
    count:'',  //对应商品数量
}*/
