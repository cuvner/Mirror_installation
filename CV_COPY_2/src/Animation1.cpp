#include "Animation1.h"

//--------------------------------------------------------------

Animation1::Animation1(){    
}

//--------------------------------------------------------------
void Animation1::setup(){
	//Define Colours
	color1 = ofColor(ofColor::ghostWhite);
	color2 = ofColor(ofColor::green);
	phase = 0;
}

//--------------------------------------------------------------
void Animation1::update(){
	//Itterate Phaser for Sine
	phase += 2;
}

//--------------------------------------------------------------
void Animation1::draw(float x, float y){
	float size = ofMap(sin(ofDegToRad(phase)), -1, 1, 30, 60);
	ofPushMatrix();
	ofTranslate(x, y);
	fractal(0, 0, size);
	ofPopMatrix();
}


//--------------------------------------------------------------


void Animation1::fractal(float x, float y, float d) {
	//Map Sine to Lerp Iteration
	float colorMix = ofMap(sin(ofDegToRad(phase)), -1, 1, 0, 1);

	//Define Rotation
	//ofRotateY(ofGetFrameNum() * PI /2);
	ofRotateZ(ofGetFrameNum() * PI / 2);

	//Lerp Colour
	ofColor currentColor = color1.getLerped(color2, colorMix);
	ofSetColor(currentColor);

	//Define Hexagon
	ofSetCircleResolution(5);
	ofSetLineWidth(0.2);

	ofNoFill();
	ofSetColor(currentColor);

	//Call Function Within Itself
	ofDrawCircle(x, y, d);

	//Define Exit From Recursion
	if (d > 1) {
		fractal(x, y, d / 1.2);

	}
}


