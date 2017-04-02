#include "line_detection.h"

void Line_Detect(InputArray _src, OutputArray _dst, int* distance, double* degree)
{
	using namespace cv;
	Mat input_image = _src.getMat();
	Mat gray_img;
	Mat blur_img;
	Mat threshOutput_image;
	Mat edge_img;
	vector<Vec4i>lines;
	int length = 0;
		
	Mat output_image;
	output_image = input_image.clone();
	_dst.getMatRef() = output_image;
	//imshow("image",input_image);
	/////pre processing
	cvtColor(input_image, gray_img, CV_BGR2GRAY);
	GaussianBlur(gray_img, blur_img, cv::Size(5,5), 10);
	adaptiveThreshold(blur_img, threshOutput_image, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 2);
	//Canny(blur_img, edge_img, 10, 100, 3);
	//imshow("image", threshOutput_image);
	//imshow("image", edge_img);
	//line detect
	HoughLinesP(threshOutput_image, lines, 1, (PI / 45), 100, 200, 5);
	//HoughLinesP(edge_img, lines, 1, (PI / 180), 120, 30, 0);
	//save line
	Vec4d params,eparams;
	int x1, y1, x2, y2;
	int xe1 = 0, ye1 = 0, xe2 = 0, ye2 = 0;
	int e1 = 0, e2 = 0;
	for (int k = 0; k < lines.size(); k++){
		params = lines[k];
		x1 = params[0];
		y1 = params[1];
		x2 = params[2];
		y2 = params[3];

		eparams[0] = eparams[0] + params[0];
		eparams[1] = eparams[1] + params[1];
		eparams[2] = eparams[2] + params[2];
		eparams[3] = eparams[3] + params[3];
		xe1 = (eparams[0]) / (k + 1);
		ye1 = (eparams[1]) / (k + 1);
		xe2 = (eparams[2]) / (k + 1);
		ye2 = (eparams[3]) / (k + 1);
		Point pt1(x1, y1),pt2(x2, y2);
		line(output_image, pt1, pt2, Scalar(255, 0, 255), 1);
		printf("선들의 좌표값 시작 x:%d y:%d 끝 x:%d y:%d \n",x1, y1, x2, y2);
	}
	//print line and distance
	if (xe1 == 0){
		xe1 = e1, xe2 = e2;
	}
	else {
		e1 = xe1, e2 = xe2;
		Point ept1(xe1,ye1),ept2(xe2,ye2);
		line(output_image, ept1, ept2, Scalar(255, 255, 0), 2);//평균선

		Point ct1((input_image.cols / 2), 0),ct2((input_image.cols / 2), input_image.rows);
		line(output_image, ct1, ct2, Scalar(0, 255, 255), 2);//중심선

		length = (input_image.cols / 2) - (xe1 + xe2) / 2 ;
		*degree = (atan2f(((float)(ye1 - ye2)), abs((float)(xe2 - xe1))) * 180/PI);
		*distance = length;
		Point dp1((xe1 + xe2) / 2, 300),dp2(((input_image.cols) / 2), 300);
		//line(output_image,dp1,dp2, Scalar(255,0,255),1);
		string te;
		std::stringstream ste;
		ste << "distance:" << *distance << "pixel" << std::endl;
		te=ste.str();
		//putText(output_image,te,dp1,3,1.2,Scalar(0,255,0));
	}
	//imshow ("출력",output_image);
	return ;
}