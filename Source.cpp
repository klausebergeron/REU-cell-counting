#include<iostream>
#include<fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include<fstream>
#include<cstring>

using namespace std;


int main() {
	string file = "C:/Users/klaus/Documents/Visual Studio 2017/Projects/count_dots/dots/1image_version1.png";
	ifstream infile = fopen(file);
	int count = 1; ofstream outfile; int contours_max = 0; int contours_min = 1000; int contours_new;
	int x; int y;
	//outfile.open("C:/Users/klaus/Desktop");
	// Outer loop to read each image
	for (int i = 1; i <= 4000; i++)
	{
		("C:/Users/klaus/Downloads/Dots/Dots/dot" + to_string(count) + ".png");

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

