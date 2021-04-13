#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "FaceDetector.h"


class VideoPlayer : public ofBaseApp {
public:
//  Constructor and Generic functions here
    VideoPlayer();
    void setup();
    void update();
    void draw();
    void dotMatrix();
    void gif();
    
// video name strings
    string video;
    string leave;
    string attract;
    
//Load an image
    ofImage img;
    
//open cv objects here
    ofxCvColorImage image;
    ofxCvGrayscaleImage grayImage;
    //ofxCvGrayscaleImage blurred;
    ofxCvGrayscaleImage background;
    ofxCvGrayscaleImage diff;
    ofxCvGrayscaleImage mask;
    //ofxCvColorImage currentColor;        //First and second original images
    

    
// video player object and variables
    ofVideoPlayer         vidPlayer;
    float vidDuration;
    
// video file array - attract
    string greet[4] = {"0", "1", "2", "3"};
    
    
// video file array - repel
    string repel [1];
    
    int vWidth;
    int vHeight;
    
// Pixel grid
    int spacing;
    int startPos;
    int maxSize;
    
// gif counter
    int totalFrames;;
    int counter;
    bool record;

    int facesDetected;
    int resolution;
    
};
