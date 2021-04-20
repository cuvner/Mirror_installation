#pragma once

#include "ofMain.h"
#include "VideoPlayer.hpp"
#include "FaceDetection.hpp"

class ofApp : public ofBaseApp{

	public:
    void setup();
    void update();
    void draw();
    void installationSetup();                   // Function to setup installation
    void installationRun();                     // Function to run installation
    void attention();                           // function that loads videos to attract/dismiss attention
    void matrixResolution();                    // Resolution of the dot matrix grid mapped to no.of faces
    void outputData();                          // Data to help setup installation
    void playBackInterval();                    // Interval of attraction mapped to faces detected or not
    void mousePressed(int x, int y, int button);// Toggle between setup and run installation
    void keyPressed(int key);
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
    int interval;
		
};
