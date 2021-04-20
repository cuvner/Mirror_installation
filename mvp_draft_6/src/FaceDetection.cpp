//
//  FaceDetection.cpp
//  mvp_draft_5
//
//  Created by Chris  on 16/04/2021.
//

#include "FaceDetection.hpp"


//--------------------------------------------------------------
FaceDetection::FaceDetection(){

    finder.setup("haarcascade_frontalface_default.xml");
    videoGrabber.setDeviceID(0);
    videoGrabber.setDesiredFrameRate(30);
    videoGrabber.initGrabber(320, 240);
    videoGrabber.setUseTexture(false);  // then you won't see the video
    finder.setScaleHaar(1.1);
    bool faceDet = false;
    init.allocate(320, 240);
    reSize.allocate(160, 120);
}

//--------------------------------------------------------------
void FaceDetection::update(){
    
//    videoGrabber.update();
//
//    if(videoGrabber.isFrameNew()){
//        colorImg.setFromPixels(videoGrabber.getPixels());
//        init = colorImg;
//        img.setFromPixels(init.getPixels());
//        finder.findHaarObjects(img);
//        nFacesDetected = finder.blobs.size();
//    }
    
    
    videoGrabber.update();

    if(videoGrabber.isFrameNew()){
        colorImg.setFromPixels(videoGrabber.getPixels());
        init = colorImg;

//        ofPoint src[4];
//        src[0] = ofPoint(0, 0);
//        src[1] = ofPoint(320, 0);
//        src[2] = ofPoint(320, 240);
//        src[3] = ofPoint(0, 240);
//
//        ofPoint dst[4];
//        dst[0] = ofPoint(0, 0);
//        dst[1] = ofPoint(160, 0);
//        dst[2] = ofPoint(160, 120);
//        dst[3] = ofPoint(0, 120);
//
//        reSize.warpIntoMe(init, src, dst);
        
        //assumes reSize is allocated to be a smaller size than init
        reSize.scaleIntoMe(init);
        img.setFromPixels(reSize.getPixels());
        finder.findHaarObjects(img);
        nFacesPresent = finder.blobs.size();
    }
    

}

//setup installation --------------------------------------------
void FaceDetection::setupInstallation(){
    ofSetColor(255);
    ofNoFill();
    img.draw(0, 0);
    detection(1);
    
   
    
    
    if(finder.blobs.size() > 0 ) {
        
        faceDet = true;
        millis = ofGetElapsedTimeMillis();
    }
    
    if (ofGetElapsedTimeMillis() > (millis + 2000))
    {
        faceDet = false;
    }
    
    
    
   // cout<<faceDet<<endl;
    


}

//--------------------------------------------------------------
void FaceDetection::installation(){
    ofSetColor(255);
    ofNoFill();
    detection(0);
    
    
    // is there a face present boolean
    if(finder.blobs.size() > 0 ) {
        faceDet = true;
        millis = ofGetElapsedTimeMillis();
    }
    
    
    if (ofGetElapsedTimeMillis() > (millis + 2000))
    {
        faceDet = false;
    }
    
    
    
    cout<<faceDet<<endl;
    
}


//--------------------------------------------------------------
void FaceDetection::detection(bool _drawRect){
    ofSetLineWidth(3);
    for(int i = 0; i < finder.blobs.size(); i++) { // loop over all the found faces/blobs
        cur = finder.blobs[i].boundingRect;     // and put a rectangle around the face
        proximity = ofMap (finder.blobs[i].boundingRect.width, 15, 80, 0,10); // map closeness to installation
        cout <<finder.blobs[0].boundingRect.width<<endl;
        // cout <<proximity<<endl;
        if( _drawRect) ofDrawRectangle(cur);
       
    }
}


//No. of faces detetcted at installation------------------------
void FaceDetection::nFacesDetected(){
    
    if (counter%60==0){
        nFacesPresent = finder.blobs.size();
    }
    counter++;
}
//--------------------------------------------------------------
