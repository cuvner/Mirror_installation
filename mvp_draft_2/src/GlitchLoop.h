#pragma once

#include "ofMain.h"

class GlitchLoop{

	public:
    GlitchLoop();
	

    GlitchLoop(float _diameter, float _min, float _max);
    void setup();
    void update();
    void draw();
    float value (float angle);
    
    
    
    //variables
    float diameter;
    float min, max;
    float cx;
    float cy;
  
};
