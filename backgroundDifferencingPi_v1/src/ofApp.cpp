#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    video.setDeviceID(0);
//    video.setDesiredFrameRate(60);
//    video.initGrabber(640, 480);
    
    vidPlayer.load("exampleMask.mp4");
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NORMAL);
    
    spacing = ofGetWidth()/20;
    startPos = spacing/2;

    debug = true;
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
         pixels = mask.getPixels();

		//Store first frame to background image
		if ( !background.bAllocated ) {
			background = blurred;
		}

		//Find difference of the frame and background
		diff = blurred;
		diff.absDiff(blurred, background); // get pixel difference
        
		//Thresholding for obtaining binary image
		mask = diff;
		mask.threshold( ofMap(mouseX, 0, ofGetWidth(), 0, 200) ); //Threshold controlled by mouseX
        	//It should be adjusted for good results when using another videos than in example.
		
        	//Find contours
		contourFinder.findContours( mask, 10, 20000, 20, false );

		//Store objects' centers
        	blobs = contourFinder.blobs;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
		ofSetColor( 255, 255, 255 );	//Set color for images drawing

        //DEBUG MODE: draws the color image (top left), the difference from background (top right)
        //the thresholded image (bottom left) and the original image with centroids (bottom right).
        if (debug){
            int w = image.width;
            int h = image.height;
            //Original decimated image
            image.draw(0, 0, w/2, h/2);

            //Difference
            diff.draw( w/2, 0, w/2, h/2 );

            //Thresholded
            mask.draw( 0, h/2, w/2, h/2 );

            //Draw found contours
            contourFinder.draw( 0, h/2, w/2, h/2 );

            //Draw centers over decimated image
            image.draw(w/2, h/2, w/2, h/2);
            ofSetColor( 255, 255, 0 );
            ofSetLineWidth( 2 );
            ofTranslate(w/2, h/2);
            for (int i=0; i<blobs.size(); i++) {
                ofPoint p = blobs[i].centroid / ofPoint(2,2) ;
                ofDrawLine( p.x - 20, p.y, p.x + 20, p.y );
                ofDrawLine( p.x, p.y - 20, p.x, p.y + 20 );
            }
            ofSetLineWidth(1);
        }
        else{
            //Draw centers over original image and the centroids
         //   image.draw(0, 0);
            // mask.draw( 0, 0 );
            for (int i =0; i<(ofGetWidth()/spacing); i++) {
                for (int j = 0; j<(ofGetHeight()/spacing); j++) {
                    int locX = startPos + ( i * spacing);
                    int locY = startPos + ( j * spacing);
                    ofPushMatrix();
                    ofTranslate(locX, locY);
                    ofColor c = pixels.getColor(locX, locY);
                    int brightness = c.getBrightness();
                    float maxSize = spacing/2;
                    float radius = ofMap(brightness, 0, 255, 0, maxSize);
                    ofPushStyle();
                    ofSetColor(0);
                    ofDrawCircle(0, 0, maxSize);
                    ofPopStyle();
                    ofDrawCircle(0, 0, radius);
                    
                    //ofSetColor(c);
                    ofPopMatrix();
                }
            }
            
            
            
           

//            ofPushStyle();
//            ofSetColor( 255, 255, 0 );
//            ofSetLineWidth( 2 );
//            for (int i=0; i<blobs.size(); i++) {
//                ofPoint p = ofPoint(blobs[i].centroid.x, blobs[i].centroid.y);
//                ofDrawLine( p.x - 20, p.y, p.x + 20, p.y );
//                ofDrawLine( p.x, p.y - 20, p.x, p.y + 20 );
//            }
//            ofPopStyle();
        }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    debug = !debug;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int button){
  // background = blurred;
}
