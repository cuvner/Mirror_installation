#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "VideoPlayer.hpp"

class FaceDetector {
	public:
    FaceDetector();
		void setup();
		void update();
		void draw();
        void installation();
        void facesDetected();
      
		ofImage img;
		ofVideoGrabber videoGrabber;
		ofxCvHaarFinder finder;
        ofRectangle cur;
    
   
    
    float millis;
    bool faceDet;
    int proximity;
    int nFacesDetected;
    int counter;
};
