﻿#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// 描述：将视频帧转成图片输出
int main()
{
	// 获取视频文件
	VideoCapture cap("E:\\cell_count_picture\\1.avi");

	// 获取视频总帧数
	long totalFrameNumber = (int)cap.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "total frames: " << totalFrameNumber << endl;

	Mat frame;
	bool flags = true;
	long currentFrame = 0;

	while (flags) {
		// 读取视频每一帧
		cap.read(frame);

		stringstream str;
		str << "cqh" << currentFrame << ".jpg";
		cout << "正在处理第" << currentFrame << "帧" << endl;
		printf("\n");

		// 设置每30帧获取一次帧
		if (currentFrame % 1 == 0) {
			// 将帧转成图片输出
			imwrite("E:\\cell_count_picture\\1\\" + str.str(), frame);
		}
		// 结束条件
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	return 0;
}
