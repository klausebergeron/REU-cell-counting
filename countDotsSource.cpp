#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include<fstream>

using namespace std;
using namespace cv;
String infile = "C:/Users/klaus/Documents/Visual Studio 2017/Projects/count_dots/dots/1image_version1.png";

int main(){
Mat gray, binary, input;

//system("mkdir Output");
int count = 1; ofstream outfile; int contours_max = 0; int contours_min = 1000; int contours_new; 
int x; int y;
//outfile.open("C:/Users/klaus/Desktop");
// Outer loop to read each image
for (int i = 1; i <= 4000; i++)
{
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		Mat input = imread("C:/Users/klaus/Downloads/Dots/Dots/dot" + to_string(count) + ".png");
		
		cvtColor(input, gray, CV_BGR2GRAY);
		//imwrite("C:/Users/klaus/Documents/Visual Studio 2017/Projects/count_dots/GDOT" + to_string(count) + ".png", gray);
		threshold(gray, binary, 30, 255, THRESH_BINARY);

		//imwrite("C:/Users/klaus/Documents/Visual Studio 2017/Projects/count_dots/BDOT" + to_string(count) + ".png", binary);
		findContours(binary, contours, hierarchy, 
			CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

		contours_new = contours.size();
		if (contours_new > contours_max)
		{
			cout << contours_new << " ";
			contours_max = contours_new;
			y = i;
		}
		if (contours_new < contours_min)
		{
			cout << contours_new << " ";
			contours_min = contours_new;
			x = i;
		}
		count++;
	}
cout << "\n\nMax: " << contours_max << "cell" << y << endl;
cout << "\nMin: " << contours_min << "cell" << x << endl;
}

