#pragma once

#include "ofMain.h"
//#include "ofxCvHaarFinder.h"

class Animation1 {
	public:
    Animation1();
		void setup();
		void update();
		void draw(float x, float y);
		void fractal(float x, float y, float d);

		float phase;
		
		ofColor color1;
		ofColor color2;
};
