#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

int main()
{
  std::string image_path = samples::findFile("starry_night.jpg");
  Mat img = imread(image_path, IMREAD_COLOR);
  if(img.empty()){
    std::cout << "Could not read the image: " << image_path << std::endl;
    return 1;
  }

  // imshow("Display window", img);
  std::cout << img << std::endl;
  // int k = waitKey(0); // WAIT FOR A KEYSTROKE IN THE WINDOW
  imwrite("starry_night.png",img);

  return 0;
}
