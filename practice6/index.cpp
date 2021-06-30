// Making contours
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil, Mat img){

  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
  drawContours(img,contours,-1,Scalar(255,0,255),2);

}

int main(){
  string path = "./example.jpg";
  Mat img = imread(path);

  // Preprocessing
  cvtColor(img,imgGray,COLOR_BGR2GRAY);
  GaussianBlur(imgGray, imgBlur, Size(3,3), 3, 0);
  Canny(imgBlur,imgCanny,25,75);
  Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
  dilate(imgCanny,imgDil,kernel);

  getContours(imgDil,img);

  imshow("image",img);
//   imshow("imageGray",imgGray);
//   imshow("imageBlur",imgBlur);
//   imshow("imageCanny",imgCanny);
//   imshow("imageDil",imgDil);

  waitKey(0);
  return 0;
}
