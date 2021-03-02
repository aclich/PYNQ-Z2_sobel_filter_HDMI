#include<opencv2/opencv.hpp>

#include "sobel.h"

AXIS_T input;//[MAX_HIGHT*MAX_WIDTH];
AXIS_T output;//[MAX_HIGHT*MAX_WIDTH];

int main(int argc,char *argv[]){

	cv::Mat srcImg = cv::imread("ex.png",CV_8UC1); int h=srcImg.rows, w=srcImg.cols;
	cv::Mat outImg = cv::Mat(h,w,CV_8UC1);

	for(int i=0 ; i < h*w ; i++){
		DATA_PACK datapack;
		datapack.data = srcImg.at<uchar>( i/w , i%w );
		datapack.last = (i==h*w-1);
		input.write(datapack);
	}

	std::cout<<"start sobel"<<std::endl;
	sobel(input, output, h, w);
	std::cout<<"end sobel"<<std::endl;

	for(int i=0 ; i < h*w ; i++)
		outImg.data[i] = output.read().data;
	cv::imwrite("./out_sobel.png",outImg);
	cv::imwrite("./out.png",srcImg);

}
