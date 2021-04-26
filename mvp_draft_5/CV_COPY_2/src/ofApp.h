#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "Animation1.h"
#include "Animation2.h"
#include "Animation3.h"
#include "Animation4.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void render();

		ofEasyCam cam;
		ofImage img;
		ofVideoGrabber videoGrabber;
        ofxCvHaarFinder finder;
        ofPixels gray;

		Animation1 animation1;
		Animation2 animation2;
		Animation3 animation3;
		Animation4 animation4;



		float phaser;
		float millis;
		bool timer, timer2;
		float minX, minPos;
		float scl;
		int test;

		ofColor col;

};
