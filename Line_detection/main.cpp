#include "line_detection.h"



int main()
{
	
	const char* k = "image/13.jpg";
	int dist = 0;
	double degree = 0;
	int detect = Line_Detect(k, &dist, &degree);
	
	if (detect == 1){
		printf("�Ÿ� %d \n", dist);
		printf("������ ���� %lf \n", degree);
		cv::waitKey(0);
		system("pause");
	}else{
		printf("ã�� ���� %d\n");
		system("pause");
	}

}