//
//  VideoPlayer.cpp
//  FaceDetectionLab
//
//  Created by Chris  on 07/04/2021.
//

#include "VideoPlayer.hpp"

//--------------------------------------------------------------

VideoPlayer::VideoPlayer(){
// Gif setup  - set record to true to generate pngs
    totalFrames= 240;
    counter=0;
    record=false;
    

    
}

//--------------------------------------------------------------

void VideoPlayer::setup(){
    
    // video file names
    leave = "mime_10.mp4";
    attract = "mime_1.mp4";
    
    
    // vidPlayer setup
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    vidPlayer.load(video);
    vidDuration = vidPlayer.getDuration();
    vWidth = vidPlayer.getWidth();
    vHeight = vidPlayer.getHeight();
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NONE);
    // Load black image for bckd diff
    img.load("blackFrame.png");
    
    
}
//--------------------------------------------------------------

void VideoPlayer::update(){
    
   
        vidPlayer.update();
   
    
    //Do computing only if the new frame was obtained
    if ( vidPlayer.isFrameNew() ) {
        //Getting a new frame
        image.setFromPixels( vidPlayer.getPixels() );
        
        //Convert to ofxCv images
        ofPixels & pixels = vidPlayer.getPixels();
        image.setFromPixels( pixels );
        
        float decimate = 0.25;              //Decimate images to 25% (makes calculations faster + works like a blurr too)
        ofxCvColorImage imageDecimated1;
        imageDecimated1.allocate( image.width * decimate, image.height * decimate );
        imageDecimated1.scaleIntoMe( image, CV_INTER_AREA );             //High-quality resize
        grayImage = imageDecimated1;

        
        //Convert to grayscale image
       // grayImage = image;
        
        //Smoothing image
       // blurred = grayImage;
       // blurred.blurGaussian( 9 );
        
        //put mask into pixels
        // pixels = mask.getPixels();
        
        
        //Store first frame to background image
        if ( !background.bAllocated ) {
            background = grayImage;
        }
        
        //Find difference of the frame and background
        diff = grayImage;
        diff.absDiff(grayImage, background); // get pixel difference
        
        //Thresholding for obtaining binary image
        mask = diff;
        mask.threshold( 100 ); //Threshold controlled by mouseX
        //It should be adjusted for good results when using another videos than in example.
        
    }
}
//--------------------------------------------------------------

void VideoPlayer::draw(){
    
    dotMatrix(); // draws the dot grid
    gif();       // create looping gif if record set true in setup
    
}

//--------------------------------------------------------------
void VideoPlayer::dotMatrix(){
    
    // Matrix setup
    
    resolution = ofMap(facesDetected, 0, 2, 300, 300,true);
    spacing = ofGetWidth()/resolution;
    startPos = spacing/2;
    maxSize = spacing/2;
    
    
    ofSetColor( 255 );    //Set color for images drawing
    
    // Put grey mask into pixel array here
    // and get video w + h
    ofPixels & pixels = mask.getPixels();
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
void VideoPlayer::gif(){
    //can record a gif for documentation
    float percent = 0;
    if(record){
        percent = float(counter)/totalFrames;
    }else{
        percent = float(counter%totalFrames)/totalFrames;
    }
    
    if (record && counter<=totalFrames) {
        ofSaveScreen("output/gif-"+ ofToString(counter,3,'0' )+".png");
        if(counter==totalFrames){
            exit();
        }
    }
    if (ofGetElapsedTimeMillis() >4000) {
        counter++;
    }
}
