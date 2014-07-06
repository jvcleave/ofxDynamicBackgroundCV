#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDynamicBackgroundCV.h"

class ofxDynamicBackgroundCV
{
public:

    ofxDynamicBackgroundCV();
    
	void update(ofBaseHasPixels& sourcePixels);
    void draw(int x, int y);
    
	cv::Mat accumulatorMat;
    cv::Mat frameMat;
    cv::Mat backgroundOutputMat;
    ofImage backgroundOutputImage;
    
    double alpha;

};





