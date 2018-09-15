var express = require('express');
var app = express();
var io = require('socket.io')(app.listen(8081));
var five = require('johnny-five');
 
app.use(express.static(__dirname + '/app'));
 
app.get('/', function (req,res) { 
  	res.sendFile(__dirname + '/public/botones.html');
});
 
 
var board = new five.Board({
  	repl:false
});
 
board.on('ready', function () {
    var speed, commands, motors;
    var anode = new five.Led.RGB({
        pins: {
            red: 9,
            green: 11,
            blue: 10
        },
        isAnode: true
    });
 
    commands = null;
 
    anode.on();
    anode.color("#efe13d");
 
    anode.blink(1000);
 
    var blink = true;
 
    io.on('connection', function (socket) {
        socket.on('azul', function (){
            anode.on();
            anode.color("#3366CC");
        });
 
        socket.on('verde', function (){
            anode.on();
            anode.color("#009900");
        });
 
        socket.on('rojo', function (){
            anode.on();
            anode.color("#FF0000");
        });
 
        socket.on('stop', function (){
            if (blink){
                anode.stop(); // to stop blinking
                blink = false;
            }
            else{
                anode.blink(1000);
                blink = true;
            }
        });
 
        socket.on('off', function (){
            anode.off();  // to shut it off (stop doesn't mean "off")
        });
 
        socket.on('on', function (){
            anode.on(); // to turn on, but not blink
        });
 
    });
});