/**
 * @file main.cpp
 * @author Nuo Ma
 * @date Feb5,2017
 * @version 1.0
 * 
 * @purpose: Display Video stream
 */

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void help()
{
    cout
        << "------------------------------------------------------------------------------" << endl
        << "This code display video from IPcam."                                   << endl
        << "Usage:"                                                                         << endl
        << "./display ip type"<< endl
          << "eg ./display 192.168.1.50 vivotek"<< endl
          << "press ESC to end display"<< endl
          << "different adderss for mjpg/h.264, look for manufacture instruction"<< endl
        << "Press anykey to continue"<< endl
        << "------------------------------------------------------------------------------" << endl
        << endl;
}


int main(int argc, char *argv[]) {
    VideoCapture vcap;
    Mat image;
    const string ip = argv[1]; //first input is IP address
    const string type = argv[2];//oncam or vivotek
    
    
    if(type == "oncam")
    //this is for OnCam h264
        const string videoStreamAddress = string("rtsp://admin:admin@") + ip + string("/video.sdp?name=MJPEG");
    // this is for OnCam h264
    //  const string videoStreamAddress = string("rtsp://admin:admin@") + ip + string("/h264/video.sdp");
    // this works on a oncam concealed12 primary H.264
    //const std::string videoStreamAddress = "rtsp://admin:admin@192.168.1.52/h264/video.sdp";

     else
        if(type == "vivotek")
    //this is for vivotek mjpg
        const string videoStreamAddress = string("http://root:admin@") + ip + string(":80/video.mjpg");
    else;
        break; 


    //open the video stream and make sure it's opened
    if(!vcap.open(videoStreamAddress)) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    for(;;) {
        if(!vcap.read(image)) {
            cout << "No frame" << endl;
            waitKey();
        }
        imshow("Output Window", image);
        if(waitKey(1) >= 0) break;
    }   
}


