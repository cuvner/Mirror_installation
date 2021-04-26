#include "Animation3.h"


Animation3::Animation3() {

}

//--------------------------------------------------------------
void Animation3::setup(){
	//Define Colours
	/*color1 = ofColor(ofColor::yellow);
	color2 = ofColor(ofColor::white);
	iter = 0;*/
}

//--------------------------------------------------------------
void Animation3::update(){
	//iter++;
}

//--------------------------------------------------------------
void Animation3::draw(float x1, float y1){
	//Map Sine to Lerp Iteration
	//float colorMix = ofMap(sin(ofDegToRad(iter)), -1, 1, 0, 1);

	//Lerp Colour
	//ofColor currentColor = color1.getLerped(color2, colorMix);

	ofPushMatrix();
	ofTranslate(x1, y1);
	ofRotate(ofRadToDeg(angle/3));
	ofScale(0.1);

	for (float a = 0; a < 360; a += 5) {
		//ofPushMatrix();
		if (angle < 360) {
			ofRotate(ofDegToRad(a)*cos(ofDegToRad(angle)));
		} else ofRotate(ofDegToRad(a));
		float time = ofGetElapsedTimef();
		ofNoFill();
		ofSetColor(127 + 127 * sin(a * 0.01 + time), 127 + 127 * sin(a * 0.011 + time), 127 + 127 * sin(a * 0.012 + time));
		ofSetLineWidth(0.2);
		//ofDrawLine(x * sin(ofDegToRad(angle)), 0, 0, y-dia/2);
		ofDrawLine(x * sin(ofDegToRad(angle)), 0, x, y-dia);

		ofFill();
		ofDrawEllipse(x * sin(ofDegToRad(angle)), 0, dia, dia);
		ofDrawEllipse(x, y-dia, dia, dia);
		//ofPopMatrix();
	}
	angle ++;
	ofPopMatrix();
}

