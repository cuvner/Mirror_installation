//
//  VideoPlayer.cpp
//  emptyExample
//
//  Created by Chris  on 16/04/2021.
//

#include "VideoPlayer.hpp"


//--------------------------------------------------------------
 VideoPlayer::VideoPlayer(){
    
//
//    vidPlayer.load(video);
//    vidPlayer.play();
//    vidPlayer.setLoopState(OF_LOOP_NORMAL);
//
//
//    colorImg.allocate(320,240);
//    grayImage.allocate(320,240);
//    grayBg.allocate(320,240);
//    grayDiff.allocate(320,240);
//
//    bLearnBakground = true;
//    threshold = 100;
//
//     // video file names
//     leave = "02.mp4";
//     attract = "01.mp4";
//
//     vWidth = vidPlayer.getWidth();
//     vHeight = vidPlayer.getHeight();
}

//--------------------------------------------------------------
void VideoPlayer::setup(){
    vidPlayer.load(video);
    //vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NONE);
    
    
//    colorImg.allocate(320,240);
//    grayImage.allocate(320,240);
//    grayBg.allocate(320,240);
//    grayDiff.allocate(320,240);
    
    bLearnBakground = true;
    threshold = 100;
    
    // video file names
    leave = "02.mp4";
    attract = "01.mp4";
    
    vWidth = vidPlayer.getWidth();
    vHeight = vidPlayer.getHeight();
    
}
//--------------------------------------------------------------
void VideoPlayer::update(){
    
    bool bNewFrame = false;
    

    
    
    
    vidPlayer.update();
    bNewFrame = vidPlayer.isFrameNew();
    
    if (bNewFrame){
        

        colorImg.setFromPixels(vidPlayer.getPixels());

        
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;        // the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
      
    }
    
}

//--------------------------------------------------------------
void VideoPlayer::draw(){
    
    // draw the incoming, the grayscale, the bg and the thresholded difference
   
    
    dotMatrix(); // draws the dot grid
   
}

//--------------------------------------------------------------
void VideoPlayer::keyPressed(int key){
    
  
}

//--------------------------------------------------------------
void VideoPlayer::dotMatrix(){
    
    // Matrix setup
    
    //resolution = ofMap(facesDetected, 0, 2, 300, 300,true);
    resolution = 200;
    spacing = ofGetWidth()/resolution;
    startPos = spacing/2;
    maxSize = spacing/2;
    
    
    ofSetColor( 255 );    //Set color for images drawing
    
    // Put grey mask into pixel array here
    // and get video w + h
    ofPixels & pixels = grayDiff.getPixels();
    int vidWidth = pixels.getWidth();
    int vidHeight = pixels.getHeight();
    
    
    // Dot Matrix for loop here
    ofPushMatrix();
    ofScale(3);
    for (int i = 0; i < vidWidth; i+=spacing){
        for (int j = 0; j < vidHeight; j+=spacing){
            
            int cWidth = (ofGetWidth()/2);
            int cHeight = (ofGetHeight()/2);
            int locX = (i+spacing);
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
