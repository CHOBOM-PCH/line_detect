#include "line_detection.h"



int main()
{
	
	const char* k = "image/7.png";
	int dist = 0;
	double degree = 0;
	Line_Detect(k, &dist, &degree);
	
	
	printf("�Ÿ� %d \n", dist);
	printf("������ ���� %lf \n", degree);
	cv::waitKey(0);
	
}