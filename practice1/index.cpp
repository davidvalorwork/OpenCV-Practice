// FUNCTIONS THAT EVERYONE SHOULD NOW

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
  string path = "../readImg/starry_night.jpg";
  Mat img = imread(path);
  Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;

  cvtColor(img,imgGray,COLOR_BGR2GRAY);
  GaussianBlur(img,imgBlur,Size(7,7),5,0);
  Canny(imgBlur,imgCanny,50,150);

  Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
  dilate(imgCanny, imgDia, kernel);
  erode(imgDia, imgErode, kernel);

  imshow("Image",img);
  imshow("Image Gray",imgGray);
  imshow("Image Blur",imgBlur);
  imshow("Image Canny",imgCanny);
  imshow("Image Dilate",imgDia);
  imshow("Image Erode",imgErode);
  waitKey(0);
}
