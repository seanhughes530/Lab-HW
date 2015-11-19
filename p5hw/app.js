var bodyParser = require('body-parser');
var express = require("express");
var app = express();//create instance of express
var port = 8000;
var url='localhost'
var server = app.listen(port);
var io = require("socket.io").listen(server);//socket io listen on port
var serialport = require("serialport");//serial port instance
var SerialPort = serialport.SerialPort;
var sport = new SerialPort("/dev/ttyAMA0", { // create SerialPort instance called sport
  baudrate: 9600,// give baudrate
  parser: serialport.parsers.readline("\n") //parse data when end of line present
}, false);

var prompt = require('prompt');
prompt.start();
var message;

app.use(express.static(__dirname + '/'));//serve diectory this file is in
console.log('Simple static server listening at '+url+':'+port);


//socket.io stuff
io.sockets.on('connection', function (socket) {//open io connection
sport.open(function(error) {//open serial connection
  if (error) {
    console.log('failed to open: ' + error);//if serial fails
  } else {
	  prompt.get(['message'], function (err, result){
	  	message = result.message;
	  	socket.emit('message', {m: message});
	 });

  	socket.on('box1', function (data){
  		console.log("The "+ data.num +" Box was Hit!");
  	});
  	socket.on('box2', function (data){
  		console.log("The "+ data.num +" Box was Hit!");
  	});
   	socket.on('box3', function (data){
  		console.log("The "+ data.num +" Box was Hit!");
  	});
   	socket.on('box4', function (data){
  		console.log("The "+ data.num +" Box was Hit!");
  	});
//     // port.write("A");
//     console.log('Serial open');
//   socket.on('fromLeftBut', function (data) { //listen for toScreen fron socket 
//     console.log("you clicked "+data.l+" button"); // log data
//   });
//  socket.on('fromRightBut', function (data) { //listen for toScreen fron socket 
//     console.log("you clicked "+data.r+" button"); // log data
//   });

// sport.on("data", function (data) {
//   console.log("your data from serial= "+data);
//       socket.emit('serialText', { s: data}); //emit to screen the data recived from socket io

}
});
});




