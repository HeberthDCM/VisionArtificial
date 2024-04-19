#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;
/*
int main()
{
    Mat img = imread("F:/Jesus/UNSA/Maestria/Cursos/VisionArtificial/Tareas/Tarea2Ecualizar/kodim08_grayscale.png");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    imshow("First OpenCV Application", img);
    moveWindow("First OpenCV Application", 0, 45);
    waitKey(0);
    destroyAllWindows();

    cvtColor(img, img, COLOR_BGR2GRAY);   

    vector<Mat> bgr_planes;
    split(img, bgr_planes);
    int histSize = 256;
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange[] = { range };
    bool uniform = true, accumulate = false;
    Mat b_hist, g_hist, r_hist, main_hist;
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);

    std::cout << "BLUE HISTOGRAM" << endl;
    std::cout << b_hist << endl;
    std::cout << "GREEN HISTOGRAM" << endl;
    std::cout << g_hist << endl;
    std::cout << "RED HISTOGRAM" << endl;
    std::cout << r_hist << endl;
    vector<float> new_hist = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 8, 8, 12, 12, 12, 12, 12, 15, 15, 15, 15, 18, 18, 18, 21, 21, 22, 22, 26, 26, 27, 30, 31, 31, 35, 35, 36, 40, 40, 44, 44, 44, 48, 48, 52, 52, 55, 55, 59, 59, 63, 63, 66, 66, 70, 70, 73, 73, 77, 77, 80, 80, 83, 86, 86, 90, 90, 92, 96, 96, 99, 102, 102, 105, 108, 108, 110, 115, 115, 118, 120, 123, 123, 125, 127, 129, 129, 131, 133, 134, 136, 136, 137, 139, 140, 141, 143, 144, 146, 146, 147, 148, 149, 151, 152, 153, 154, 156, 158, 159, 161, 162, 164, 165, 167, 169, 170, 172, 174, 175, 176, 177, 179, 181, 181, 182, 183, 184, 184, 186, 186, 187, 188, 188, 189, 190, 191, 191, 192, 193, 193, 194, 195, 195, 195, 196, 197, 197, 198, 198, 199, 199, 200, 200, 201, 201, 201, 202, 202, 203, 203, 203, 204, 204, 205, 205, 206, 206, 206, 207, 207, 207, 208, 208, 208, 209, 209, 210, 210, 210, 211, 211, 211, 212, 212, 213, 213, 214, 214, 214, 215, 216, 216, 217, 217, 218, 219, 220, 221, 222, 222, 223, 225, 226, 227, 229, 231, 232, 234, 235, 237, 238, 239, 240, 242, 243, 243, 244, 245, 245, 245, 246, 246, 247, 247, 247, 248, 248, 248, 249, 249, 250, 255};
    Mat b_hist_r(new_hist);
    Mat g_hist_r(new_hist);
    Mat r_hist_r(new_hist);
    waitKey(0);
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
    normalize(b_hist_r, b_hist_r, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist_r, g_hist_r, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist_r, r_hist_r, 0, histImage.rows, NORM_MINMAX, -1, Mat());
   
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist_r.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(b_hist_r.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist_r.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(g_hist_r.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist_r.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(r_hist_r.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }
    imshow("Source image", img);
    imshow("calcHist Demo", histImage);
    
    waitKey(0);
    destroyAllWindows();
    return 0;    
}*/


int main(int argc, char** argv)
{
    Mat src = imread("F:/Jesus/UNSA/Maestria/Cursos/VisionArtificial/Tareas/Tarea2Ecualizar/kodim08_grayscale.png");
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    cvtColor(src, src, COLOR_BGR2GRAY);

    Mat dst;
    equalizeHist(src, dst);

    imshow("Source image", src);
    imshow("Equalized Image", dst);

    vector<Mat> bgr_planes;
    split(dst, bgr_planes);
    int histSize = 256;
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange[] = { range };
    bool uniform = true, accumulate = false;
    Mat b_hist, g_hist, r_hist, main_hist;
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);

    std::cout << "BLUE HISTOGRAM" << endl;
    std::cout << b_hist << endl;

    waitKey();

    return 0;

}