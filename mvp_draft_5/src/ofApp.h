#pragma once

#include "ofMain.h"
#include "VideoPlayer.hpp"
#include "FaceDetection.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

    VideoPlayer videoPlayer;
    FaceDetection faceDetection;
		
};
