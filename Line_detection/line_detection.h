#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <math.h>
#define PI 3.1415926
using namespace cv;


void Line_Detect(InputArray _src, OutputArray _dst,
	int* distance, double* radian);//distance of center to line