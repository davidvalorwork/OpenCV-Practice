// Resize and crop

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
  string path = "../readImg/starry_night.jpg";
  Mat img = imread(path);
  Mat imgResize, imgScale, imgCrop;

  cout << img.size() << endl;
  resize(img,imgResize,Size(600,200));
  resize(img,imgScale,Size(),0.5,0.5);

  Rect roi(100,100,300,250);
  imgCrop = img(roi);

  imshow("Image",img);
  imshow("Image Resize",imgResize);
  imshow("Image Scale",imgScale);
  imshow("Image Crop", imgCrop);

  waitKey(0);
}
