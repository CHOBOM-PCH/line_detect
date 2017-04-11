#include "line_detection.h"



int main()
{
	
	//for (int ang = 0; ang < 355; ang = ang +5){
		//std::string te;
		//std::stringstream ste;
		//ste << "muffler_vision/ang_" << ang << ".000.bmp" << std::endl;
		//te = ste.str();
		const char* k = "muffler_vision/ang_115.000.bmp";//te.c_str();
		int dist = 0;
		double degree = 0;
		int roi = 40;

		int detect = Line_Detect(k, &dist, &roi, &degree);

		if (detect == 1){
			printf("거리 %d \n", dist);
			printf("기울어진 각도 %lf \n", degree);
			cv::waitKey(0);
			//system("pause");
		}else{
			printf("찾지 못함 %s \n",k);
			system("pause");
		//}
	}
}