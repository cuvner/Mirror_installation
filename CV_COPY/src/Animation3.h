#pragma once

#include "ofMain.h"

class Animation3 {
public:
	Animation3();
		void setup();
		void update();
		void draw(float x1, float y1);

		float x = 300;
		float y = 300;
		float dia = 10;
		float angle = 90;

		ofColor color1;
		ofColor color2;
		float iter;
		int lineAlpha = 255;
		
};
