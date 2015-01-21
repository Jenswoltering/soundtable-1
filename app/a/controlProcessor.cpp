#include "controlProcessor.h"
#include <QDebug>
using namespace cv;


ControlProcessor::ControlProcessor():
    filterProcessor(new FilterProcessor())
  , detectProcessor(new DetectProcessor())
  , soundProcessor(new SoundProcessor())
  , frameCount(0)
  , sendtestvalue(0)
  , rawData(15)
{

}

ControlProcessor::~ControlProcessor()
{
    delete filterProcessor;
    delete detectProcessor;
    delete soundProcessor;
}
Mat ControlProcessor::process(const Mat &input){
    frameCount=frameCount+1;
    unprocessedFrame = input;
    processedFrame=filterProcessor->process(unprocessedFrame);
    if (frameCount%3==0){
        rawData = detectProcessor->analyse(processedFrame);
        qDebug() << "ArrayControl: " << rawData.size();
        soundProcessor->process(mode,masterVol,rawData);
    }


    return processedFrame;
    
}
void ControlProcessor::setMute(float pMute){
    mute=pMute;
}

void ControlProcessor::setMasterVol(float vol){
    masterVol=vol;
}
void ControlProcessor::setMode(float pMode){
    mode=pMode;
}
void ControlProcessor::setBeat(float pBeat){
    beat=pBeat;
}


