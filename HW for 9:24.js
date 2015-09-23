//var gpio = require('rpi-gpio');
var colors = require('colors');

//ir light up Led at pin 17
var GPIO = require('onoff').Gpio,
    led = new GPIO(17, 'out');
    led2 = new GPIO(23, 'out');
    button = new GPIO(4, 'in', 'both');
    button2 = new GPIO(18, 'in', 'both');


function light(err, state) {
    if(state == 1) {
        led.writeSync(1);
        console.log('Light'.yellow);
  } else {
        led.writeSync(0);
 }
}

function light2(err, state) {
    if(state == 1) {
        led2.writeSync(1);
        console.log('Light'.red);
    } else {
        led2.writeSync(0);
    }
}


button2.watch(light2);
button.watch(light);
