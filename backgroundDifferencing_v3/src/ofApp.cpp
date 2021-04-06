#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    video.setDeviceID(0);
//    video.setDesiredFrameRate(60);
//    video.initGrabber(640, 480);
    
    ofSetVerticalSync(true);
    vidPlayer.load("exampleMask_2.mp4");
    vWidth = vidPlayer.getWidth();
    vHeight = vidPlayer.getHeight();
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NORMAL);
    
    spacing = ofGetWidth()/100;
    startPos = spacing/2;

}

//--------------------------------------------------------------
void ofApp::update(){
	//video.update();	//Decode the new frame if needed
    
    vidPlayer.update();
   // bNewFrame = vidPlayer.isFrameNew();

	//Do computing only if the new frame was obtained
	if ( vidPlayer.isFrameNew() ) {
		//Getting a new frame
		image.setFromPixels( vidPlayer.getPixels() );

		//Convert to grayscale image
		grayImage = image;

		//Smoothing image
		blurred = grayImage;
		blurred.blurGaussian( 9 );
        
        //put mask into pixels
        // pixels = mask.getPixels();
        

		//Store first frame to background image
		if ( !background.bAllocated ) {
			background = blurred;
		}

		//Find difference of the frame and background
		diff = blurred;
		diff.absDiff(blurred, background); // get pixel difference
        
		//Thresholding for obtaining binary image
		mask = diff;
		mask.threshold( 100 ); //Threshold controlled by mouseX
        	//It should be adjusted for good results when using another videos than in example.

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
		ofSetColor( 255, 255, 255 );	//Set color for images drawing


        ofPixels & pixels = mask.getPixels();
            int vidWidth = pixels.getWidth();
            int vidHeight = pixels.getHeight();
         
            
            
            
           
            ofSetColor(255);
           
            
            for (int i = 4; i < vidWidth; i+=8){
                for (int j = 4; j < vidHeight; j+=8){
                    int locX = 400+i;
                    int locY = 200+j;
                    ofColor c = pixels.getColor(i, j);
                     float maxSize = 2;
                    int brightness = c.getBrightness();
                    float radius = ofMap(brightness, 0, 255, 0, maxSize);
                    ofDrawCircle(locX,locY,radius);
                }
            }
            

            
            
            
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   
}
//--------------------------------------------------------------
void ofApp::keyPressed(int button){
  // background = blurred;
}
