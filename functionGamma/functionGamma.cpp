#include <iostream>
#include<opencv2/opencv.hpp>
#include<cmath>

using namespace std;
using namespace cv;

int main()
{
	//设置矫正系数
	float gamma = 0.6;
	//建立查询表数组
	unsigned char Lut[256];
	for (int i = 0; i < 256; i++)
	{
		Lut[i] = pow((float)(i / 255.0), gamma) * 255;
	}



	//读取图像
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\Files\\face.jpg",0);
	//检测读取成功性
	if (srcMat.empty())
	{
		std::cout << "Fail to open" << std::endl;
		return -1;
	}



	//进行Gamma矫正
	for (int m = 0; m < srcMat.rows; m++)
	{
		for (int n = 0; n < srcMat.cols; n++)
		{
			dstMat.at<uchar>(m, n) = Lut[srcMat.at<uchar>(m, n)];
		}
	}


	//输出图像
	cv::imshow("dst", dstMat);
	waitKey(0);
}

