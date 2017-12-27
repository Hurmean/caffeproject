#include <QCoreApplication>
#include <iostream>
#include "MTCNN.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void MTCNNtest()
{

    /////////////////////////////////////////////
    //the vector used to input the address of the net model
    vector<string> model_file = {
            "/home/hfx/project/caffeproject/model/det1.prototxt",
            "/home/hfx/project/caffeproject/model/det2.prototxt",
            "/home/hfx/project/caffeproject/model/det3.prototxt",
            "/home/hfx/project/caffeproject/model/det4.prototxt"
    };

    //the vector used to input the address of the net parameters
    vector<string> trained_file = {
            "/home/hfx/project/caffeproject/model/det1.caffemodel",
            "/home/hfx/project/caffeproject/model/det2.caffemodel",
            "/home/hfx/project/caffeproject/model/det3.caffemodel",
            "/home/hfx/project/caffeproject/model/det4.caffemodel"
    };

    MTCNN mtcnn(model_file, trained_file);

    cv::Mat img = cv::imread("/home/hfx/project/caffeproject/result/trump.jpg",1);
//    imshow("Live", img);
//    waitKey(1000);
    int frame_count = 0;
    //while(cap.read(img))
    {
        vector<Rect> rectangles;
        vector<float> confidences;
        std::vector<std::vector<cv::Point>> alignment;

        mtcnn.detection(img, rectangles, confidences, alignment);

        for(int i = 0; i < rectangles.size(); i++)
        {
            int green = confidences[i] * 255;
            int red = (1 - confidences[i]) * 255;
            cv::rectangle(img, rectangles[i], cv::Scalar(0, green, red), 3);
            //cv::rectangle(img,rectangles[i],)
            for(int j = 0; j < alignment[i].size(); j++)
            {
                cv::circle(img, alignment[i][j], 5, cv::Scalar(255, 255, 0), 3);
            }
        }

        frame_count++;
        cv::putText(img, std::to_string(frame_count), cvPoint(3, 13),cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 255, 0), 1, CV_AA);
//      writer.write(img);
        imshow("Live", img);
        waitKey(10000);
    }
    /////////////////////////////////////////////
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    MTCNNtest();

    //return a.exec();
    return 0;
}
