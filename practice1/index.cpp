#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
  string path = "../readImg/starry_night.jpg";
  Mat img = imread(path);
  Mat imgGray, imgBlur, imgCanny;

  cvtColor(img,imgGray,COLOR_BGR2GRAY);
  GaussianBlur(img,imgBlur,Size(7,7),5,0);
  Canny(imgBlur,imgCanny,50,150);

  imshow("Image",img);
  imshow("Image Gray",imgGray);
  imshow("Image Blur",imgBlur);
  imshow("Image Canny",imgCanny);
  waitKey(0);
}
