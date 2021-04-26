#pragma once

#include "ofMain.h"

using namespace glm;

class Animation2 {
	public:
    Animation2();
		void setup();
		void update();
		void draw();
		void calculateLissajousPoints();
		void drawLissajous(float x1, float y1);

		ofSoundPlayer vertigo;
		vector<vec2>lissajousPoints;

		int pointCount = 400;
		int freqX = ofRandom(2, 10);
		int freqY = ofRandom(2, 10);
		float phi = 10;
		float iter;

		float millis;
		bool timer;
		int ranNum;

		int modFreqX = 3;
		int modFreqY = 2;
		float lineWeight = 2;

		ofColor lineColor = ofColor(255);
		ofColor color1;
		ofColor color2;
		ofColor currentColor;

		float lineAlpha = 255;

		float connectionRadius = 300;
		float connectionRamp = 10;
		
};
