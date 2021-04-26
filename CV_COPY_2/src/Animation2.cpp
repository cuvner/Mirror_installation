#include "Animation2.h"

//--------------------------------------------------------------

Animation2::Animation2(){   

}

//--------------------------------------------------------------
void Animation2::setup() {
	ofSetBackgroundColor(255);
	iter = 0;
	millis = ofGetElapsedTimeMillis();

	//Define Colours
	color1 = ofColor(ofColor::deepSkyBlue);
	color2 = ofColor(ofColor::whiteSmoke);

//    vertigo.load("vertigo3.mp3");
//    vertigo.setVolume(0.6);
//    vertigo.setLoop(true);
	//vertigo.play();

}

//--------------------------------------------------------------
void Animation2::update() {
	
	iter += 1;	


}

//--------------------------------------------------------------
void Animation2::draw() {

	//ranNum = ofRandom(0, 100);
	////cout << ranNum << endl;

	//if (ranNum == 5) {
	//	freqX = ofRandom(2, 10);
	//	freqY = ofRandom(2, 10);
	//	//calculateLissajousPoints();
	//	cout << freqX << endl;
	//}

}

void Animation2::calculateLissajousPoints() {

	int i = ofGetFrameNum() % 400;

	if (lissajousPoints.size() > 100) {
		lissajousPoints.erase(lissajousPoints.begin());
	}


	float angle = ofMap(i, 0, pointCount, 0, TWO_PI);
	float x = sin(angle * freqX + ofDegToRad(phi)) * cos(angle * modFreqX);
	float y = sin(angle * freqY) * cos(angle * modFreqY);


	x = x * (ofGetWidth() / 2 - 30);
	y = y * (ofGetHeight() / 2 - 30);

	lissajousPoints.push_back(vec2(x, y));


}

void Animation2::drawLissajous(float x1, float y1) {
	float d, a, h, n;

	//colorMode(RGB, 255, 255, 255, 100);

	//Map Sine to Lerp Iteration
	float colorMix = ofMap(sin(ofDegToRad(iter)), -1, 1, 0, 1);

	//Lerp Colour
	ofColor currentColor = color1.getLerped(color2, colorMix);

	ofSetLineWidth(lineWeight);
	//SETLINECAP(ROUND);
	ofFill();

	ofPushMatrix();
	ofTranslate(x1, y1);
	//Define Rotation
	ofRotateZ(ofGetFrameNum() * PI / 3);
	ofPushMatrix();
	float myScale = ofMap(sin(ofDegToRad(iter)), -1, 1, 0.37, 0.1);
	ofScale(myScale);


	for (int i1 = 0; i1 < lissajousPoints.size(); i1++) {
		for (int i2 = 0; i2 < i1; i2++) {

			vec2 p1 = lissajousPoints[i1];
			vec2 p2 = lissajousPoints[i2];

			d = distance(p1, p2);
			a = pow(1 / (d / connectionRadius + 1), 6);

			//float time = ofGetElapsedTimef();
			//currentColor = (127 + 127 * sin(d * 0.02 + time), 127 + 127 * sin(d * 0.021 + time), 127 + 127 * sin(d * 0.022 + time));

			/*vector<int>v1;

			for (int i = 0; i < 1000; i += 10) {
				currentColor = (127 + 127 * sin(i * 0.01 + time), 127 + 127 * sin(i * 0.011 + time), 127 + 127 * sin(i * 0.012 + time));
				v1.push_back(i);
			}*/

			//cout << d << endl;
			if (d <= connectionRadius) {
			ofSetColor(currentColor, a*lineAlpha);
			ofDrawLine(p1.x, p1.y, p2.x, p2.y);
			
			}
		}
	}
	ofPopMatrix();
	ofPopMatrix();

	/*cout << x1 << endl;
	cout << y1 << endl;*/
}




