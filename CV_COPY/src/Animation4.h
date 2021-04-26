#pragma once

#include "ofMain.h"

using namespace glm;


class Animation4 {
public:
	Animation4();
		void setup();
		void update();
		void draw(float x, float y);

		float bgColor;
		float width = 100;
		float height = 100;
		int dotSize = 2;

		float t = 0;

		float xRatio;
		float yRatio;
		float step;

		//int gutter = 50;
		float ampX = width / 2;
		float ampY = height / 2;


		
};
