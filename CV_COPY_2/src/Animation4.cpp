#include "Animation4.h"

//--------------------------------------------------------------

Animation4::Animation4() {

}

//--------------------------------------------------------------
void Animation4::setup(){
	//ofSetBackgroundColor(0);
	ofSetCircleResolution(100);
	//ofSetDepthTest(true);
}

//--------------------------------------------------------------
void Animation4::update(){
	xRatio = 5.9 + 0.00002;
	yRatio = 6 + 0.0002;
	step = 0.006;
}

//--------------------------------------------------------------
void Animation4::draw(float x, float y){
	/*float time = ofGetElapsedTimef();
	ofScale(0.2);
	for (int i = 0; i < 3000; i += 5) {
		ofSetColor(127 + 127 * sin(i * 0.01 + time), 127 + 127 * sin(i * 0.011 + time), 127 + 127 * sin(i * 0.012 + time), 100);
		ofDrawCircle(x + 100 * sin(i * 0.01 + time), i-150, 150 + 40 * sin(i * 0.005 + time));
	}*/

	ofTranslate(x, y);
	for (float i = 0; i < TWO_PI; i += step) {
		float time = ofGetElapsedTimef();

		vector<int>v1;

		for (int i = 0; i < 2000; i += 10) {
			ofSetColor(127 + 127 * sin(i * 0.01 + time), 127 + 127 * sin(i * 0.011 + time), 127 + 127 * sin(i * 0.012 + time), 100);
			v1.push_back(i);
		}

		float x2 = ampX * sin((t)* xRatio);
		float y2 = ampY * cos((t)* yRatio);
		ofDrawEllipse(x2, y2, dotSize, dotSize);

		t += step;
		cout << i << endl;
	}
}

