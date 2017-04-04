#include "line_detection.h"



int main()
{
	
	const char* k = "image/7.png";
	int dist = 0;
	double degree = 0;
	Line_Detect(k, &dist, &degree);
	
	printf("°Å¸® %d \n", dist);
	printf("±â¿ï¾îÁø °¢µµ %lf \n", degree);
	cv::waitKey(0);
	//system("pause");
}
