#include "testApp.h"

bool useCamera = true;

void testApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    if (useCamera)
    {
        videoWidth = 1280;
        videoHeight = 720;
        camera.initGrabber(videoWidth, videoHeight);
    }else
    {
        string videoPath = ofToDataPath("/Volumes/WORK_IN_PROGRESS/OPENFRAMEWORKS/VIDEO/h264_lan/001759-Apple ProRes 422 for Interlaced material-H.264 LAN Streaming.mov", true);
        videoPlayer.loadMovie(videoPath);
        videoPlayer.play();
    }
    
    
}


void testApp::update()
{
    if (useCamera)
    {
        camera.update();
        if(camera.isFrameNew())
        {
            background.update(camera);
        }
    }else
    {
        videoPlayer.update();
        if(videoPlayer.isFrameNew())
        {
            background.update(videoPlayer);
        }
    }
    
    
    
}

void testApp::draw()
{
    if (useCamera)
    {
        camera.draw(0, 0);
        background.draw(0, videoHeight);
    }else
    {
        videoPlayer.draw(0, 0);
        background.draw(0, videoPlayer.getHeight());
    }
    
    
}
