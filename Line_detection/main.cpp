#include "line_detection.h"



int main()
{
	cv::Mat image = cv::imread("image/6.png",-1);
	cv::Mat O_img;
	int dist = 0;
	double radian = 0;
	
	Line_Detect(image, O_img, &dist, &radian);
	
	
	if (!O_img.empty()){
	
		cv::imshow("���",O_img);

	}
	
	printf("�Ÿ� %d \n",dist);
	printf("������ ���� %lf \n",radian);
	cv::waitKey(0);
	//system("pause");
}