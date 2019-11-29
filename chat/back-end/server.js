let express = require("express");
let app     = express();

var http = require('http').createServer(app);

var io = require('socket.io')(http);

io.on('connection', function(socket){
  console.log('a user connected');
  socket.emit("newmessage", {message: "HELLO", user: "ADMIN"})
  socket.on("newmessage", function(data){
    console.log(data);
    io.emit("newmessage", data);
  })
  socket.on('disconnect', function(){
    console.log('user disconnected');
  });
});

http.listen(8000);
