//
//  VideoPlayer.cpp
//  emptyExample
//
//  Created by Chris  on 16/04/2021.
//

#include "VideoPlayer.hpp"


//--------------------------------------------------------------
 VideoPlayer::VideoPlayer(){
    

    vidPlayer.load("01.mp4");
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NORMAL);

    
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    bLearnBakground = true;
    threshold = 100;
}

//--------------------------------------------------------------
void VideoPlayer::update(){
    ofBackground(100,100,100);
    
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
    ofSetHexColor(0xffffff);

    grayDiff.draw(360,280);
    
  
   
}

//--------------------------------------------------------------
void VideoPlayer::keyPressed(int key){
    
    switch (key){
        case ' ':
            bLearnBakground = true;
            break;
        case '+':
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
    }
}

//--------------------------------------------------------------
