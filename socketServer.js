const WebsocketServer = require('ws').Server;
let ws = new WebsocketServer({port:8080});

//连接池
let clients = [];

ws.on('connection',function(ws){
    clients.push(ws);
    ws.on('message',function(message){
        //广播消息
        console.log(message);
        clients.forEach(function(wsTemp){
            if(wsTemp !=ws){
                wsTemp.send(message);
            }
        })
    }); 

    ws.on('close',function(message){
        console.log("从连接池中剔除连接.");
        clients = clients.filter(function(wsTemp){
            return wsTemp != ws;
        })
    })
});