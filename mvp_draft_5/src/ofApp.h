#pragma once

#include "ofMain.h"
#include "VideoPlayer.hpp"
#include "FaceDetection.hpp"

class ofApp : public ofBaseApp{

	public:
    void setup();
    void update();
    void draw();
    void installationSetup();
    void installationRun();
    void matrixResolution();
    void mousePressed(int x, int y, int button);// setup screen
    // void timer();
    
   // ofImage img;
   // ofVideoGrabber videoGrabber;
    ofxCvHaarFinder finder;
    ofRectangle cur;
    FaceDetection faceDetector;
    VideoPlayer videoPlayer;
    
    
    bool debug;
    float millis;
    int counter;
		
};
