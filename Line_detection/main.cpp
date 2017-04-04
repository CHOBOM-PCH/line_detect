#include "line_detection.h"



int main()
{
	
	const char* k = "image/7.png";
	int dist = 0;
	double degree = 0;
	//cv::Mat image = cv::imread("image/7.png", -1);
	//cv::Mat O_img;
	//Line_Detect(image, O_img, &dist, &degree);
	Line_Detect(k, &dist, &degree);
	
	//if (!O_img.empty()){
	//
	//	cv::imshow("출력",O_img);

	//}
	
	printf("거리 %d \n", dist);
	printf("기울어진 각도 %lf \n", degree);
	cv::waitKey(0);
	//system("pause");
}