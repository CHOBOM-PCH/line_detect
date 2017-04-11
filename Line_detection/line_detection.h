#ifndef LINE_DETECTION_H
#define LINE_DETECTION_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <math.h>

#ifdef _DEBUG
        #pragma comment(lib,"opencv_core2413d.lib")
        #pragma comment(lib,"opencv_highgui2413d.lib")
        #pragma comment(lib,"opencv_imgproc2413d.lib")
#else
        #pragma comment(lib,"opencv_core2413.lib")
        #pragma comment(lib,"opencv_highgui2413.lib")
        #pragma comment(lib,"opencv_imgproc2413.lib")
#endif

#define PI 3.1415926
using namespace cv;


//void Line_Detect(InputArray _src, OutputArray _dst,
//	int* distance, double* degree);//distance of center to line
int Line_Detect(const char* route,// 읽어올 그림 파일 루트
	int* distance,// pixel단위 중심선과의 거리
	int* roi,// 측정할 선들의 떨어질거리(pixel) 제한
	double* degree);//degree값으로 각도 반환

#endif