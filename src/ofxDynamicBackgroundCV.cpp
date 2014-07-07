#include "ofxDynamicBackgroundCV.h"


ofxDynamicBackgroundCV::ofxDynamicBackgroundCV()
{
   alpha = 0.01;
}


void ofxDynamicBackgroundCV::update(ofBaseHasPixels& sourcePixels)
{
    frameMat = ofxCv::toCv(sourcePixels);
    
    if(accumulatorMat.empty())
    {
        frameMat.convertTo(accumulatorMat, CV_32F);
    }
    
    cv::accumulateWeighted(frameMat, accumulatorMat, alpha);
    cv::convertScaleAbs(accumulatorMat, backgroundOutputMat);
   
}


void ofxDynamicBackgroundCV::draw(int x, int y) //default:0,0
{
    getImageRef().draw(x, y);
}


ofImage& ofxDynamicBackgroundCV::getImageRef()
{
    ofxCv::toOf(backgroundOutputMat, backgroundOutputImage);
    backgroundOutputImage.update();
    return backgroundOutputImage;
}


void ofxDynamicBackgroundCV::drawDebug(float scale) //default:1.0
{
    float scaledWidth = frameMat.size().width*scale;
    float scaledHeight = frameMat.size().height*scale;
    ofColor color1 = ofColor::black;
    ofColor color2 = ofColor::yellow;
    
    ofxCv::drawMat(frameMat, 0, 0, scaledWidth, scaledHeight);
    ofDrawBitmapStringHighlight("frameMat", 0, 20, color1, color2);
    
    ofPushMatrix();
        ofTranslate(0, scaledHeight);
            ofxCv::drawMat(backgroundOutputMat, 0, 0, scaledWidth, scaledHeight);
            ofDrawBitmapStringHighlight("backgroundOutputMat", 0, 20, color1, color2);
    ofPopMatrix();

    ofPushMatrix();
        ofTranslate(scaledWidth, 0);
            ofxCv::drawMat(accumulatorMat, 0, 0, scaledWidth, scaledHeight);
            ofDrawBitmapStringHighlight("accumulatorMat", 0, 20, color1, color2);
    ofPopMatrix();
    return;
    
    ofPushMatrix();
        ofTranslate(scaledWidth, scaledHeight);
            getImageRef().draw(0, 0, scaledWidth,scaledHeight);
            ofDrawBitmapStringHighlight("backgroundOutputImage", 0, 20, color1, color2);
    ofPopMatrix();
}