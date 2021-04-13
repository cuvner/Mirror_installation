#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if (ofGetElapsedTimeMillis()<3000) videoPlayer.video = videoPlayer.attract;
 
    videoPlayer.setup();
    faceDetector.setup();
    
    debug = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    faceDetector.update();
    videoPlayer.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    if (debug){ // debug mode for setting up installation,
       
        installationSetup();
    } else {
        installationRun();
        
}
    
}
//Set up function click mouse to exit ----------------------------

    void ofApp::installationSetup(){
        
    faceDetector.draw(); //face detect call drawing video
    videoPlayer.draw();
    matrixResolution();
    int interval;
    
    if (faceDetector.faceDet){ // set the interval for playback depending on face detection
        interval = 300;
    } else
        interval = 900;
    
    // Get attention when there is either no faces or a face detected at distance
    if (counter%interval == 0 && faceDetector.proximity <= 4 && !videoPlayer.vidPlayer.isPlaying()){
        videoPlayer.video = "mime_" + videoPlayer.greet[(int)ofRandom(4)] + ".mp4"; // file name array
        videoPlayer.setup();
    }
    cout<<videoPlayer.video<<endl; // video player debug aray
    
    // If face gets to close then shoo away
    if (counter%100 == 50 && faceDetector.proximity > 5 && !videoPlayer.vidPlayer.isPlaying()) {
        videoPlayer.video = videoPlayer.leave;
        videoPlayer.setup();
    }
    cout << videoPlayer.vidPlayer.isPlaying()<<endl; // debug video playing bool
    
    ofSetHexColor(0xffffff); // reports framerate
    stringstream reportStr;
    reportStr  << " fps: " << ofGetFrameRate() << endl
    << " faces detected: " << faceDetector.nFacesDetected << endl
    << " resolution: " << videoPlayer.resolution << endl
    << " face size: " << faceDetector.proximity << endl;
    ofDrawBitmapString(reportStr.str(), 20, ofGetHeight()-50);
    counter ++;
}

//Run installation-----------------------------------------------
    void ofApp::installationRun(){

    
    faceDetector.installation(); // face detect call without drawing video
    videoPlayer.draw();
    matrixResolution();
    int interval;
    
    if (faceDetector.faceDet){ // set the interval for playback depending on face detection
        interval = 300;
    } else
        interval = 900;
    
    // Get attention when there is either no faces or a face detected at distance
    if (counter%interval == 0 && faceDetector.proximity <= 4 && !videoPlayer.vidPlayer.isPlaying()){
        videoPlayer.video = "mime_" + videoPlayer.greet[(int)ofRandom(4)] + ".mp4"; // file name array
        videoPlayer.setup();
       
    }
    
    
    // If face gets to close then shoo away
    if (counter%100 == 50 && faceDetector.proximity > 5 && !videoPlayer.vidPlayer.isPlaying()) {
        videoPlayer.video = videoPlayer.leave;
        videoPlayer.setup();
    }
    
    counter ++;
}
    
//Change resolution depending on faces detected ----------------
void ofApp::matrixResolution(){
    videoPlayer.facesDetected = faceDetector.nFacesDetected;
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    debug = !debug;
}
