#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    //    ofSetupOpenGL(640,480, OF_FULLSCREEN);            // <-------- setup the GL context
    //
    //    // this kicks off the running of my app
    //    // can be OF_WINDOW or OF_FULLSCREEN
    //    // pass in width and height too:
    //    ofRunApp( new ofApp());
    ofGLFWWindowSettings msettings;
    msettings.setSize( 1920, 1080 );
    msettings.numSamples = 0;
    auto mainWin = ofCreateWindow( msettings );
    
    auto app = make_shared<ofApp>();
    ofRunApp( mainWin, app );
    ofRunMainLoop();

}
