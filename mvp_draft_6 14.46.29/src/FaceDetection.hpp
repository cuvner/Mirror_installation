#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "ofxOpenCv.h"

class FaceDetection {
public:
    FaceDetection();
    void setup();
    void update();
    void setupInstallation();
    void installation();
    void nFacesDetected();//No. of faces detetcted at installation
    void detection(bool _drawRect);// loop over found faces and draw a square
    void test();
    
    ofImage img;
    ofVideoGrabber videoGrabber;
    ofxCvHaarFinder finder;
    ofRectangle cur;
    
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage init;
    ofxCvGrayscaleImage reSize;
    
    
    float millis;
    bool faceDet;
    int proximity;
    int nFacesPresent;
    int counter;
};
