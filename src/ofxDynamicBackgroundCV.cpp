#include "ofxDynamicBackgroundCV.h"

using namespace ofxCv;
using namespace cv;

ofxDynamicBackgroundCV::ofxDynamicBackgroundCV()
{
   alpha = 0.01;
}


void ofxDynamicBackgroundCV::update(ofBaseHasPixels& sourcePixels)
{
    frameMat = toCv(sourcePixels);
    
    if(accumulatorMat.empty())
    {
        frameMat.convertTo(accumulatorMat, CV_32F);
    }
    
    cv::accumulateWeighted(frameMat, accumulatorMat, alpha);
    cv::convertScaleAbs(accumulatorMat, backgroundOutputMat);
   
}


void ofxDynamicBackgroundCV::draw(int x=0, int y=0)
{
    toOf(backgroundOutputMat, backgroundOutputImage);
    backgroundOutputImage.update();
    backgroundOutputImage.draw(x, y);
    
}