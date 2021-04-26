#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(60);
//    finder.setup("haarcascade_righteye_2splits.xml");
    
    videoGrabber.setDeviceID(0);
	
    videoGrabber.setDesiredFrameRate(30);
    videoGrabber.setup(320, 240);
	
	millis = ofGetElapsedTimeMillis();

	animation1.setup();
	animation2.setup();
	animation3.setup();
	animation4.setup();

	phaser = 0;
	
	col = ofColor(ofColor::red);

}

//--------------------------------------------------------------
void ofApp::update(){
//    finder.setScaleHaar(3.5);
    videoGrabber.update();
    img.setFromPixels(videoGrabber.getPixels());
//    finder.blobs.clear();
//    finder.findHaarObjects(img);

	img.setImageType(OF_IMAGE_GRAYSCALE);

	animation1.update();
	animation2.update();
	animation3.update();
	animation4.update();


	minX = 10000;
	minPos = -1;
	phaser++;

}

//--------------------------------------------------------------
void ofApp::draw(){
	img.draw(0, 0, ofGetWidth(), ofGetHeight());
	//ofDrawRectangle(ofGetWidth() / 4, ofGetHeight() / 4, ofGetWidth() / 2, ofGetHeight() / 2);
//    if (finder.blobs.size() > 0 && ofGetElapsedTimeMillis() >= (millis + 5000))
//    {
		render();
//    }
	
	animation2.draw();

	//// displays the position of the mouse     
	//string pixelCoords = "(" + to_string(mouseX) + ", " + to_string(mouseY) + ")";  // creates a string with pixel position
	//ofSetColor(255, 0, 255);     // set text colour
	//ofDrawBitmapString(pixelCoords, mouseX, mouseY); // write text with pixel position following the mouse
}

void ofApp::render() {
	ofSetColor(col);
	img.draw(0, 0, ofGetWidth(), ofGetHeight());

//
    if (ofGetElapsedTimeMillis() >= (millis + 6500)) {
        timer = true;
    }
    else (timer = false);

    if (ofGetElapsedTimeMillis() >= (millis + 15000)) {
        timer2 = true;
    }
    else (timer2 = false);
//
//
//    for (unsigned int i = 0; i < finder.blobs.size(); i++) { // loop over all the found faces/blobs
//        ofRectangle cur2 = finder.blobs[i].boundingRect;     // and put a rectangle around the face
//        if (cur2.getCenter().x < minX) {
//            minX = cur2.getCenter().x;
//            minPos = i;
//        }
//
//    }
//
//    if (minPos > -2) {
//        ofRectangle cur = finder.blobs[minPos].boundingRect;
//        //img.drawSubsection(0, 0, ofGetWidth(), ofGetHeight(), cur.x - 200, cur.y - 100, cur.width * 8, cur.height * 5);
//        //img.drawSubsection(0, 0, ofGetWidth(), ofGetHeight(), ofGetWidth() / 4, ofGetHeight() / 4, ofGetWidth() / 2, ofGetHeight() / 2);
//
//        float cntrX = 723;
//        float cntrY = 393;
//
//        ofScale(1920. / 960.);
//        //ofNoFill();
//        //ofDrawRectangle(cur);
//
//        //ofPoint cntr = cur.getCenter();
        ofPoint cntr = ofPoint(100,100);

        if (timer == true) {
			//animation2.calculateLissajousPoints();
			//animation2.drawLissajous(cntrX, cntrY);
			//animation2.drawLissajous(cntr.x, cntr.y + 13);
			//animation1.draw(cntr.x, cntr.y + 13);
			animation3.draw(cntr.x, cntr.y + 13);
			//animation4.draw(cntr.x, cntr.y + 13);
        }

		if (timer2 == true) {
			animation2.calculateLissajousPoints();
			animation2.drawLissajous(cntr.x, cntr.y + 13);
			
		}

	}

//}

