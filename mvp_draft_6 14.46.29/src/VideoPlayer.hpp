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
    void dotMatrix();
    
    void keyPressed(int key);
   

    ofVideoPlayer         vidPlayer;

    
    ofxCvColorImage            colorImg;
    
    ofxCvGrayscaleImage     grayImage;
    ofxCvGrayscaleImage     grayBg;
    ofxCvGrayscaleImage     grayDiff;
    
    ofxCvContourFinder     contourFinder;
    
    int                 threshold;
    bool                bLearnBakground;
    
    // Pixel grid
    int spacing;
    int startPos;
    int maxSize;
    
    int nFacesPresent; // store the value of no. of faces present at installation
    int resolution;
    
    int vWidth;
    int vHeight;
    
    // video name strings
    string video;
    string leave;
    string attract;
    
    // video file array - attract
    string greet[4] = {"0", "1", "2", "3"};
};
