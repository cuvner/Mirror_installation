#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
	finder.setup("haarcascade_frontalface_default.xml");

    videoGrabber.setDeviceID(0);
    videoGrabber.setDesiredFrameRate(30);
    videoGrabber.initGrabber(320, 240);
}

//--------------------------------------------------------------
void ofApp::update(){
    finder.setScaleHaar(1.1);
    videoGrabber.update();

    if(videoGrabber.isFrameNew()){
        finder.blobs.clear();
        finder.findHaarObjects(img);
        img.setFromPixels(videoGrabber.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofNoFill();
    img.draw(0, 0);
    
    ofSetLineWidth(3);
    for(int i = 0; i < finder.blobs.size(); i++) { // loop over all the found faces/blobs
        cur = finder.blobs[i].boundingRect;     // and put a rectangle around the face
        ofDrawRectangle(cur);
    }
    
    ofSetHexColor(0xffffff); // reports framerate
    stringstream reportStr;
    reportStr  << " fps: " << ofGetFrameRate() << endl;

    ofDrawBitmapString(reportStr.str(), 20, ofGetHeight()-50);


    
}
