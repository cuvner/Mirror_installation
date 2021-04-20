#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);// Set background
    ofSetFrameRate(30);// Set framerate to suit Rpi4
    videoPlayer.video = videoPlayer.greet[(int)ofRandom(4)] + ".mp4"; //Load random video file from array
    videoPlayer.setup(); // Setup video instance

   
    debug = true;
}


//--------------------------------------------------------------
void ofApp::update(){
    faceDetector.update(); // Update the face detector
    videoPlayer.update();  // Update the video player

    
    
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
    videoPlayer.draw(); // Draw the matrix for background differencing videos
    matrixResolution(); // Set the resolution depending on no. faces present
    playBackInterval(); // Play back interval for video matrix depenfing on proximity to installation
    attention();        // Function to determin to attract or repel participants
   
    //cout << videoPlayer.vidPlayer.isPlaying()<<endl; // debug video playing bool
    
    outputData();       // Output varaiables to setup installation
    counter ++;         // Counter for modulo
}


//Run installation-----------------------------------------------
void ofApp::installationRun(){
    
    
    faceDetector.installation(); // face detect call without drawing video
    videoPlayer.draw(); // Draw the matrix for background differencing videos
    matrixResolution(); // Set the resolution depending on no. faces present
    playBackInterval(); // Play back interval for video matrix depenfing on proximity to installation
    attention();        // Function to determin to attract or repel participants
    
    counter ++;         // Counter for modulo
}

//Change resolution depending on faces detected ------------------
void ofApp::matrixResolution(){
    videoPlayer.nFacesPresent = faceDetector.nFacesPresent;
}


//Attract/dismiss a participent-----------------------------------
void ofApp::attention(){
   
    // Get attention when there is either no faces or a face detected at distance
    
    
    
    if (counter%interval == 0 && faceDetector.proximity < 5 && videoPlayer.vidPlayer.getIsMovieDone() ){
        modulo ++;
        videoPlayer.video = videoPlayer.greet[(int)ofRandom(4)] + ".mp4";
        videoPlayer.setup();
        
        
    }
    // cout<<videoPlayer.video<<endl; // video player debug aray
    
    // If face gets to close then shoo away
    if (counter%40 == 0 && faceDetector.proximity > 5 && videoPlayer.vidPlayer.getIsMovieDone()) {
        
        
        videoPlayer.video = videoPlayer.repel[0] + ".mp4";
        videoPlayer.setup();
        
    }
}


//interval to play back videos----------------------------------
void ofApp::playBackInterval(){
    
    if (faceDetector.faceDet){ // set the interval for playback depending on face detection
            interval = 200;
    } else  interval = 500;
    
}


//Output data stream for debug------------------------------------
void ofApp::outputData(){
ofSetHexColor(0xffffff); // reports framerate
stringstream reportStr;
reportStr  << " fps: " << ofGetFrameRate() << endl
<< " faces detected: " << faceDetector.nFacesPresent<< endl
<< " video file" << videoPlayer.video<< endl
<< " resolution: " << videoPlayer.resolution << endl
<< " face size: " << faceDetector.proximity << endl
<< " interval: " << interval << endl
<< " counter: " << counter<< endl;
ofDrawBitmapString(reportStr.str(), 20, ofGetHeight()-100);
counter ++;
    }


// Toggle between setup and Installation----------------------------
void ofApp::mousePressed(int x, int y, int button){
    debug = !debug;
}
void ofApp::keyPressed(int key){
    
    if (key == 'r') {   videoPlayer.video = "02.mp4";
        videoPlayer.setup();
    }
}
