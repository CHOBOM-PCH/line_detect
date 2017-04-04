#include "line_detection.h"



int main()
{
	
	const char* k = "image/7.png";
	int dist = 0;
	double degree = 0;
	Line_Detect(k, &dist, &degree);
	
	
	printf("거리 %d \n", dist);
	printf("기울어진 각도 %lf \n", degree);
	cv::waitKey(0);
	
}