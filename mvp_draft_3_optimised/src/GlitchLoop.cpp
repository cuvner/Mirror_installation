#include "GlitchLoop.h"
GlitchLoop::GlitchLoop(float _diameter, float _min, float _max)
{
    diameter = _diameter;
    min = _min;
    max = _max;
    cx = ofRandom(100000);
    cy = ofRandom(100000);
}
//--------------------------------------------------------------
void GlitchLoop::setup(){

}

//--------------------------------------------------------------
void  GlitchLoop::update(){

}

//--------------------------------------------------------------
void GlitchLoop::draw(){
    
}

//--------------------------------------------------------------
float GlitchLoop::value(float a){
    float xoff = ofMap(cos(a), -1, 1, cx, cx+diameter);
    float yoff = ofMap(sin(a), -1, 1, cy, cy+diameter);
    float r = ofNoise(xoff, yoff);
    
    return ofMap(r, 0, 1, min, max);
}
