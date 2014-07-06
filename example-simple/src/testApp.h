#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDynamicBackgroundCV.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    int videoWidth;
    int videoHeight;
    
    ofVideoGrabber camera;
   
    ofxDynamicBackgroundCV background;
    ofVideoPlayer videoPlayer;
};
