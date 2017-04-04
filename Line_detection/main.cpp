#include "line_detection.h"



int main()
{
	cv::Mat image = cv::imread("image/3.png", -1);
	cv::Mat O_img;
	int dist = 0;
	double degree = 0;
	
	Line_Detect(image, O_img, &dist, &degree);
	
	
	if (!O_img.empty()){
	
		cv::imshow("���",O_img);

	}
	
	printf("�Ÿ� %d \n", dist);
	printf("������ ���� %lf \n", degree);
	cv::waitKey(0);
	//system("pause");
}