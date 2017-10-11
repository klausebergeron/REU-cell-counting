#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
	String sourcefolder = "C:/Users/klaus/Documents/Visual Studio 2017/Projects/cropAndRotate/input_cells/";
	String destfolder = "C:/Users/klaus/Documents/Visual Studio 2017/Projects/cropAndRotate/output_cells_small/";
	vector<String> filenames;
	glob(sourcefolder, filenames);

	int currInput = 1;
	int version = 1;

	// Gets one input image at a time from source folder
	for (unsigned int i = 0; i < filenames.size(); i++)
	{
			Mat input = imread(filenames[i]);

			int roix = 0, roiy = 0, roiwidth = 32, roiheight = 32;

			// Loops through Y axis first
			for (roiy = 0; roiy <= 128; roiy += 8)
			{
				for (roix = 0; roix <= 128; roix += 8)
				{
					Mat temp = input(Rect(roix, roiy, roiwidth, roiheight));
					imwrite(destfolder + "cell" + to_string(version) + ".png", temp);
					version++;
				}
			}

			Mat rotated, crop;
			Point2f pivot(input.cols / 2., input.rows / 2.);


			// This loop handles rotating and cropping the input image
			for (int angle = 30; angle <= 330; angle += 30)
			{
				Mat m = getRotationMatrix2D(pivot, angle, 1.0);
				warpAffine(input, rotated, m, Size(input.cols, input.rows));
				crop = rotated(Rect(16, 16, 32, 32));
				imwrite(destfolder + "cell" + to_string(version) + ".png", crop);
				version++;
			}
	}
	waitKey(0);
}