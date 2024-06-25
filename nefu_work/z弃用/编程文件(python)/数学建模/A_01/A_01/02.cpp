#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//绘制直线;
void DrawLine(Mat img, Point startPoint, Point endPoint)
{
	line(img, startPoint, endPoint, Scalar(0, 0, 0), 2, 8);
}

//绘制多边形;
void DrawPolygon(Mat inputImage, vector<Point> polygonPoint, bool bIsFill, bool bIsClosed = true)
{
	vector<vector<Point>> contours;
	contours.push_back(polygonPoint);

	if (bIsFill)
		fillPoly(inputImage, contours, Scalar(255, 255, 255), 8);
	else
		polylines(inputImage, polygonPoint, bIsClosed, Scalar(255, 255, 255), 2, 8);
}

int main()
{
	//1.创建显示图片
	Mat imgDraw = Mat::zeros(600, 600, CV_8UC3);

	//2.绘制多边形 -- 封闭不填充
	vector<Point> vPolygonPoint;
	vPolygonPoint.push_back(Point(150, 50));
	vPolygonPoint.push_back(Point(250, 200));
	vPolygonPoint.push_back(Point(150, 350));
	vPolygonPoint.push_back(Point(50, 200));
	DrawPolygon(imgDraw, vPolygonPoint, false);

	//3.绘制多边形 -- 不封闭不填充
	vPolygonPoint.clear();
	vPolygonPoint.push_back(Point(160, 50));
	vPolygonPoint.push_back(Point(260, 200));
	vPolygonPoint.push_back(Point(160, 350));
	DrawPolygon(imgDraw, vPolygonPoint, false, false);

	//4.绘制多边形 -- 内填充
	vPolygonPoint.clear();
	vPolygonPoint.push_back(Point(350, 100));
	vPolygonPoint.push_back(Point(550, 100));
	vPolygonPoint.push_back(Point(450, 200));
	vPolygonPoint.push_back(Point(300, 200));
	DrawPolygon(imgDraw, vPolygonPoint, true);

	//5.绘制矩形
	int nHeight = imgDraw.cols;
	int nWidth = imgDraw.rows;
	rectangle(imgDraw, Point(0, 6 * nHeight / 8), Point(nWidth, nHeight), Scalar(255, 255, 255), -1);
	rectangle(imgDraw, Point(10, 10), Point(nWidth - 10, 6 * nHeight / 8 - 10), Scalar(255, 255, 255), 2);

	//6.绘制直线
	DrawLine(imgDraw, Point(0, 7 * nHeight / 8), Point(nWidth, 7 * nHeight / 8));
	DrawLine(imgDraw, Point(0, 6 * nHeight / 8), Point(nWidth, nHeight));
	DrawLine(imgDraw, Point(0, nHeight), Point(nWidth, 6 * nHeight / 8));
	DrawLine(imgDraw, Point(nWidth / 2, 6 * nHeight / 8), Point(nWidth / 2, nHeight));

	//7.显示图片
	imshow("imgDraw", imgDraw);
	waitKey(0);
	destroyAllWindows();

	return 0;
}

