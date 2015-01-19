#include "detectProcessor.h"
#include <QDebug>
using namespace cv;


DetectProcessor::DetectProcessor()
 
{
    
}

void DetectProcessor::analyse(const Mat &input){
    Mat mask;
    input.copyTo(mask);
    vector<vector<Point> >contours;
    findContours(mask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    qDebug() << "Anzahl Objekte: " << contours.size();
    for(int i = 0; i < contours.size(); i++){
                    Mat maskSingleRegion(mask.rows,mask.cols,CV_8UC1,Scalar(0, 0, 0));
                    drawContours(maskSingleRegion, contours, i, Scalar(255, 255, 255), CV_FILLED);
                    RegionAnalyse(maskSingleRegion);
            }


            //vector<Point>contour = contours[i];
            //int area = contourArea(contour);
            //qDebug() << "Objekte-Nr.: " << i;
            //qDebug() << "Objekte-Nr.: " << area;


  }

void DetectProcessor::RegionAnalyse(const Mat &input){
    Mat maskSingleRegion;
    Mat copyOfMask;
    input.copyTo(maskSingleRegion);
    maskSingleRegion.copyTo(copyOfMask);
    vector<vector<Point> >contours;
    findContours(copyOfMask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    vector<Point>contour = contours[0];
    int area = contourArea(contour);
    Moments imageMoments = moments(contours[0]);
    double hu[7];
    HuMoments(imageMoments,hu);

    qDebug() << "Objekte-Moment Groesse.: " << imageMoments.m00;
    qDebug() << "Objekte-Groesse.: " << area;
    qDebug() << "Objekte-Hu 2.: " << hu[2];


    centerOfMass(maskSingleRegion);
}

void DetectProcessor::centerOfMass(Mat& image){
    int sumx = 0;
    int sumy = 0;
    int count = 0;
    float alpha = 0.9;
    cv::Point center;

    for(int x = 0; x < image.cols; x++){
        for (int y = 0; y < image.rows; y++){
            if (image.at<uchar>(y,x) == 255){
                sumx += x;
                sumy += y;
                count++;
            }
        }
    }
    if (count > 0){
        center = (1 - alpha) * center + alpha * Point(sumx/count, sumy/count);
         qDebug() << "Objekte- x.: " << center.x;
         qDebug() << "Objekte- y.: " << center.y;
    }
}


