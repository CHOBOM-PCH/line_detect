#include "line_detection.h"



int main()
{
	cv::Mat image = cv::imread("image/4.png",-1);
	cv::Mat O_img;
	int dist;
	
	Line_Detect(image, O_img, &dist);
	
	
	if (!O_img.empty()){
	
		cv::imshow("출력",O_img);

	}
	
	printf("거리 %d \n",dist);
	cv::waitKey(0);
	//system("pause");
}