var back;

var x1;
var x2;
var x3;
var x4;

var y;

var bW, bH;

var mX;
var mY;
var mW, mH;

var xSpeed = 5;
var ySpeed = 3;

var c;

var start = false;

function setup() {
  createCanvas(1000, 500);
  back=0;
  
  x1 = 200;
  x2 = 350;
  x3 = 500;
  x4 = 650;

  y = 175;

  bW = 100;
  bH = 100;

  mW = 50;
  mH = 50;


  mX = 50;
  mY = 50;


}

function draw() {
	background(back);
	fill(0,0,255);
	if (start == true){
		rect(x1, y, bW,bH);
		rect(x2, y, bW,bH);
		rect(x3, y, bW,bH);
		rect(x4, y, bW,bH);

		ellipse(mX, mY, mW, mH);

		movement();
		collision();
	} else {

	}
	
}

// function addColor(){
// 	c = (random(0,255), random(0,255), random(0,255));
// 	fill(c);
// }

function movement(){
	mY += ySpeed;
	mX += xSpeed;

	if (mY >= 500 - mH/2){
		ySpeed *= -1;
	} else if (mY <= mH/2){
		ySpeed *= -1;
	}

	if (mX >= 1000 - mW/2){
		xSpeed *= -1;
	} else if (mX <= mW/2){
		xSpeed *= -1;
	}
}

function collision(){
	if ((mX >= x1) && (mX <= x1+bW) && (mY >= y) && (mY <= y+bH)) {
		//addColor();
		console.log("touch 1");
		box1();
	}
	if ((mX >= x2) && (mX <= x2+bW) && (mY >= y) && (mY <= y+bH)) {
		//addColor();
		console.log("touch 2");
		box2();
	}
	if ((mX >= x3) && (mX <= x3+bW) && (mY >= y) && (mY <= y+bH)) {
		//addColor();
		console.log("touch 3");
		box3();
	}
	if ((mX >= x4) && (mX <= x4+bW) && (mY >= y) && (mY <= y+bH)) {
		//addColor();
		console.log("touch 4");
		box4();
	}
}

