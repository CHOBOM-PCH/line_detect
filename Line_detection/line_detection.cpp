#include "line_detection.h"
#include "RANSAC_LineFittingAlgorithm.h"


int Line_Detect(const char* route, int* distance, double* degree)
{
	using namespace cv;
	Mat read_img = imread (route);
	if(read_img.empty())
		return -1;

	Mat input_img = read_img(Rect(10, 10, read_img.cols - 20, read_img.rows - 20));
	Mat gray_img;
	Mat blur_img;
	Mat threshOutput_img;
	Mat edge_img;
	vector<Vec4i>lines;
	int length = 0;
	
	Mat output_img;
	output_img = input_img.clone();
	cvtColor(input_img, gray_img, CV_BGR2GRAY);
	GaussianBlur(gray_img, blur_img, cv::Size(5,5), 10);
	adaptiveThreshold(blur_img, threshOutput_img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 2);
	//imshow("img", threshOutput_img);
	//line detect
	HoughLinesP(threshOutput_img, lines, 1, (PI / 180), 100, 100, 5);

	//save line
	Vec4d params;//, avgparams;
	sPoint *data = new sPoint[lines.size() * 2];
	sLine sline;

	int x1, y1, x2, y2;
	int xe1 = 0, ye1 = 0, xe2 = 0, ye2 = 0;
	int e1 = 0, e2 = 0;
	int j = 0;
	double angle = 0;
	for (int k = 0; k < lines.size(); k++){
		params = lines[k];
		x1 = params[0];
		y1 = params[1];
		x2 = params[2];
		y2 = params[3];
		angle = abs(atan2f(((float)(y1 - y2)), abs((float)(x2 - x1))) * 180 / PI);
		if(angle > 80 && angle < 100){
			j ++;
		}else{
			int i = (k + 1 - j) * 2;
			data[i - 2].x = params[0];
			data[i - 2].y = params[1];
			data[i - 1].x = params[2];
			data[i - 1].y = params[3];
		}
		
		Point pt1(x1, y1),pt2(x2, y2);
		line(output_img, pt1, pt2, Scalar(255, 0, 255), 1);
		//printf("시작점 %d, %d  끝점 %d %d  각도 %lf \n", x1, y1, x2, y2, angle);
	}
	
	double cost = ransac_line_fitting (data, ((lines.size() * 2) - (j * 2)), sline, 30);

	if (sline.sx < 2){
		delete data;
		return -1;
	}else {
		xe1 = sline.sx - 500 * sline.mx;
		ye1 = sline.sy - 500 * sline.my;
		xe2 = sline.sx + 500 * sline.mx;
		ye2 = sline.sy + 500 * sline.my;
		e1 = xe1, e2 = xe2;
		Point ept1(xe1, ye1),ept2(xe2, ye2);
		line(output_img, ept1, ept2, Scalar(255, 255, 0), 2);//평균선
		circle(output_img, Point(sline.sx, sline.sy), 2, Scalar(0,0,255), 3, 8, 0);

		//Point ct1((input_img.cols / 2), 0),ct2((input_img.cols / 2), input_img.rows);//수직 중심
		Point ct1(0, (input_img.rows / 2)),ct2(input_img.cols, (input_img.rows / 2));
		line(output_img, ct1, ct2, Scalar(0, 255, 255), 2);//중심선

		//length = - (input_img.cols / 2) + sline.sx;//(xe1 + xe2) / 2 ;//수직일때 거리 측정
		length = (input_img.rows / 2) - sline.sy;
		*degree = (atan2f(((float)(ye1 - ye2)), abs((float)(xe2 - xe1))) * 180 / PI);
		*distance = length;
		
		string te;
		std::stringstream ste;
		ste << "distance:" << *distance << "pixel" << std::endl;
		te=ste.str();
		putText(output_img, te, Point(sline.sx, sline.sy), 3, 1.2, Scalar(0,255,0));
		//imshow ("출력",output_img);
		delete data;
		return 1;
	}
	
}