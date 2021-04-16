#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoPlayer.draw();
    // finally, a report:
    ofSetHexColor(0xffffff);
    stringstream reportStr;
    reportStr << "fps: " << ofGetFrameRate();
    ofDrawBitmapString(reportStr.str(), 20, 600);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------


