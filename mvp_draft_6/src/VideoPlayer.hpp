#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"

//#define _USE_LIVE_VIDEO        // uncomment this to use a live camera
// otherwise, we'll use a movie file

class VideoPlayer : public ofBaseApp{
    
public:
    VideoPlayer();
    void setup();
    void update();
    void draw();
    void dotMatrix(); // function to create the dot matrix from video file

   

    ofVideoPlayer         vidPlayer;

    
    ofxCvColorImage        colorImg;
    
    ofxCvGrayscaleImage     grayImage;
    ofxCvGrayscaleImage     grayBg;
    ofxCvGrayscaleImage     grayDiff;
    
    ofxCvContourFinder     contourFinder;
    
    // setup for background differencing
    int  threshold; // sets differencing threshold
    bool bLearnBakground; // saves first frame and sets background for differencing
    
    // Pixel grid
    int spacing;
    int startPos;
    int maxSize;
    
    // Store variables for 
    int nFacesPresent; // store the value of no. of faces present at installation
    int resolution;
    
    int vWidth;
    int vHeight;
    
  
    
    // video name strings
    string video;
    string leave;
    string attract;
    
    // video file arrays
    
    string greet[5] = {"01", "02", "03","04", "05"};// attract
    string repel [1] = {"10"};  //repel
};
