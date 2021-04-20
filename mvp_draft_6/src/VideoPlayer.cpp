//
//  VideoPlayer.cpp
//  Used OFX video player example for reference
//

#include "VideoPlayer.hpp"


//--------------------------------------------------------------
 VideoPlayer::VideoPlayer(){
    
}

//--------------------------------------------------------------
void VideoPlayer::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    vidPlayer.load(video);

    // set up video player
    vWidth = vidPlayer.getWidth();
    vHeight = vidPlayer.getHeight();
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NONE);

 

    
    bLearnBakground = true;
    threshold = 100;
    
    // video file names
    leave = "02.mp4";
    attract = "01.mp4";

}
//--------------------------------------------------------------
void VideoPlayer::update(){
    
    bool bNewFrame = false; // check to see if frame is new
    
    vidPlayer.update();
    bNewFrame = vidPlayer.isFrameNew();
    
    if (bNewFrame){
        

        colorImg.setFromPixels(vidPlayer.getPixels()); // sets first frame as background to calculate
                                                       // the background differencing

        
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage; // the = sign copys the pixels from grayImage
                                //into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
      
    }
    
}

//--------------------------------------------------------------
void VideoPlayer::draw(){

    dotMatrix(); // draws the dot grid
   
}

// Matrix setup--------------------------------------------------------
void VideoPlayer::dotMatrix(){
    
    
    
    resolution = ofMap(nFacesPresent, 0, 5, 600, 100,true); // Map faces present tot he matrix resolution
    spacing = ofGetWidth()/resolution;                      // the more faces the lower the resolution
    startPos = spacing/2;
    maxSize = spacing/2;                                    // Size of the dots
    
    
    ofSetColor( 255 );    //Set color for dot matrix
    
    // Put grey mask into pixel array here
    // and get video w + h
    ofPixels & pixels = grayDiff.getPixels();
    int vidWidth = pixels.getWidth();
    int vidHeight = pixels.getHeight();
    
    
    // Dot Matrix for loop here
    ofPushMatrix();
    ofScale(4);
    for (int i = 0; i < vidWidth; i+=spacing){
        for (int j = 0; j < vidHeight; j+=spacing){
            int startPosition = 50;
            int cWidth = (ofGetWidth()/2);
            int cHeight = (ofGetHeight()/2);
            int locX = (i+spacing)+startPosition;
            int locY = j+spacing;
            ofColor c = pixels.getColor(i, j);
            
            int brightness = c.getBrightness();
            float radius = ofMap(brightness, 0, 255, 0, maxSize);
            ofFill();
            ofDrawCircle(locX,locY,radius);
        }
    }
    ofPopMatrix();
    
    
}
//--------------------------------------------------------------
