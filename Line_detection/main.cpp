#include "line_detection.h"



int main()
{
	
	const char* k = "image/13.jpg";
	int dist = 0;
	double degree = 0;
	int detect = Line_Detect(k, &dist, &degree);
	
	if (detect == 1){
		printf("거리 %d \n", dist);
		printf("기울어진 각도 %lf \n", degree);
		cv::waitKey(0);
		system("pause");
	}else{
		printf("찾지 못함 %d\n");
		system("pause");
	}

}