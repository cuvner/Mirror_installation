#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofBackground(0);
    if (ofGetElapsedTimeMillis()<3000) videoPlayer.video = videoPlayer.attract;
    ofSetFrameRate(30);
//    videoPlayer.video = "02.mp4";
//    videoPlayer.setup();

   
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
    
    faceDetector.setupInstallation(); //face detect call drawing video
    videoPlayer.draw();
    matrixResolution();
    playBackInterval();
    attention();
   
    cout << videoPlayer.vidPlayer.isPlaying()<<endl; // debug video playing bool
    
    outputData();
    counter ++;
}


//Run installation-----------------------------------------------
void ofApp::installationRun(){
    
    
    faceDetector.installation(); // face detect call without drawing video
    videoPlayer.draw();
    matrixResolution();
    playBackInterval();
    attention();
    
    counter ++;
}

//Change resolution depending on faces detected ------------------
void ofApp::matrixResolution(){
    videoPlayer.nFacesPresent = faceDetector.nFacesPresent;
}


//Attract/dismiss a participent-----------------------------------
void ofApp::attention(){
    // Get attention when there is either no faces or a face detected at distance
    
   
    
    if (counter%interval == 0 && faceDetector.proximity <= 4 && !videoPlayer.vidPlayer.isPlaying()){
        videoPlayer.video = videoPlayer.greet[(int)ofRandom(1)] + ".mp4"; // file name array
        videoPlayer.video = "01.mp4";
        videoPlayer.setup();
       
    }
    // cout<<videoPlayer.video<<endl; // video player debug aray
    
    // If face gets to close then shoo away
    if (counter%100 == 50 && faceDetector.proximity > 5 && !videoPlayer.vidPlayer.isPlaying()) {
        videoPlayer.video = videoPlayer.leave;
        videoPlayer.video = "02.mp4";
        videoPlayer.setup();
       
    }
}


//interval to play back videos----------------------------------
void ofApp::playBackInterval(){
    
    if (faceDetector.faceDet){ // set the interval for playback depending on face detection
            interval = 300;
    } else  interval = 900;
    
}


//Output data stream--------------------------------------------
void ofApp::outputData(){
ofSetHexColor(0xffffff); // reports framerate
stringstream reportStr;
reportStr  << " fps: " << ofGetFrameRate() << endl
<< " faces detected: " << faceDetector.nFacesPresent<< endl
<< " video file" << videoPlayer.video<< endl
<< " resolution: " << videoPlayer.resolution << endl
<< " face size: " << faceDetector.proximity << endl
<< " counter: " << counter<< endl;
ofDrawBitmapString(reportStr.str(), 20, ofGetHeight()-100);
counter ++;
    }


// Toggle between setup and Installation--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    debug = !debug;
}
void ofApp::keyPressed(int key){
    
    if (key == 'r') {   videoPlayer.video = "02.mp4";
        videoPlayer.setup();
    }
}
