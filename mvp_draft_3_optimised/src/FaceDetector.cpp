#include "FaceDetector.h"

//--------------------------------------------------------------

FaceDetector::FaceDetector()
{    
}

//--------------------------------------------------------------
void FaceDetector::setup(){
   
	finder.setup("haarcascade_frontalface_default.xml");

    videoGrabber.setDeviceID(0);
    videoGrabber.setDesiredFrameRate(30);
    videoGrabber.initGrabber(320, 240);
    bool faceDet = false;
}

//--------------------------------------------------------------
void FaceDetector::update(){
    nFacesDetected = finder.blobs.size();
    finder.setScaleHaar(1.1);
    videoGrabber.update();

    if(videoGrabber.isFrameNew()){
        finder.blobs.clear();
       
        finder.findHaarObjects(img);
        img.setFromPixels(videoGrabber.getPixels());
    }
}

//--------------------------------------------------------------
void FaceDetector::draw(){
    ofSetColor(255);
    ofNoFill();
    img.draw(0, 0);
    
    ofSetLineWidth(3);
    for(int i = 0; i < finder.blobs.size(); i++) { // loop over all the found faces/blobs
        cur = finder.blobs[i].boundingRect;     // and put a rectangle around the face
        proximity = ofMap (finder.blobs[i].boundingRect.width, 0, 200, 0,10); // map closeness to installation
        cout <<proximity<<endl;
       ofDrawRectangle(cur);
    }
    
    
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
void FaceDetector::installation(){
    ofSetColor(255);
    ofNoFill();
    
    // blobs, bounding box and mapping proximity
    ofSetLineWidth(3);
    for(int i = 0; i < finder.blobs.size(); i++) { // loop over all the found faces/blobs
        cur = finder.blobs[i].boundingRect;     // and put a rectangle around the face
        proximity = ofMap (finder.blobs[i].boundingRect.width, 0, 200, 0,10); // map closeness to installation
      
    }
    
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
void FaceDetector::facesDetected(){
   
    if (counter%60==0){
        nFacesDetected = finder.blobs.size();
    }
    counter++;
}
//--------------------------------------------------------------

