const WebsocketServer = require('ws').Server;
let ws = new WebsocketServer({port:8080});

//连接池
let clients = [];
//为每个连接者命名并存在name数组中
let name = [];

ws.on('connection',function(ws){
    //连接者名字为Date().getTime()取第8位开始往后的数字
    let data = new Date().getTime();
    data = data.toString();
    ws.name = data.substr(8);
    name.push(ws.name);

    //将连接加入连接池
    clients.push(ws);

    //给客户端返回生成的名字
    ws.send(JSON.stringify({type:0,name:ws.name}));

    //动态更新在线成员
    clients.forEach(function(wsTemp){
        wsTemp.send(JSON.stringify({type:1,memberList:name}));
    });
    ws.on('message',function(message){
        //广播消息
        clients.forEach(function(wsTemp){
            //if(wsTemp !=ws){
                wsTemp.send(JSON.stringify({type:2,name:ws.name,message:message}));
            //}
        })
    }); 

    ws.on('close',function(message){
        console.log("从连接池中剔除连接.");
        //console.log(name,ws.name);
        clients = clients.filter(function(wsTemp){
            return wsTemp != ws;
        });
        name = name.filter(function(temp){
            return temp !=ws.name;
        });
        clients.forEach(function(wsTemp){
            wsTemp.send(JSON.stringify({type:1,memberList:name}));
        })
    })
});