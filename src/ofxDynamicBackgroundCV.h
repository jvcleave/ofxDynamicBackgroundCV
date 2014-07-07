#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDynamicBackgroundCV.h"

class ofxDynamicBackgroundCV
{
public:

    ofxDynamicBackgroundCV();
    
	void update(ofBaseHasPixels& sourcePixels);
    void draw(int x=0, int y=0);
    
	cv::Mat accumulatorMat;
    cv::Mat frameMat;
    cv::Mat backgroundOutputMat;
    ofImage backgroundOutputImage;
    
    
    ofImage& getImageRef();
    double alpha;

    void drawDebug(float scale=1.0);
};





