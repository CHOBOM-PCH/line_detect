#include "line_detection.h"



int main()
{
	cv::Mat image = cv::imread("image/image3.png",-1);
	cv::Mat O_img;
	int dist = 0;
	double radian = 0;
	
	Line_Detect(image, O_img, &dist, &radian);
	
	
	if (!O_img.empty()){
	
		cv::imshow("출력",O_img);

	}
	
	printf("거리 %d \n",dist);
	printf("기울어진 각도 %lf \n",radian);
	cv::waitKey(0);
	//system("pause");
}