#include "learncv.h"
#include "ui_learncv.h"

Mat ImageProc::threshBinary(
    Mat src,
    int thresh) // Input can be in BGR or Grayscale. Output is binary image
{
  Mat temp, dst;
  temp = src.clone();
  if (temp.channels() == 3)
    cvtColor(temp, temp, COLOR_BGR2GRAY);
  threshold(temp, dst, thresh, 255, THRESH_BINARY);
  return dst;
}
Mat ImageProc::threshAuto(
    Mat src) // Input can be in BGR or Grayscal. Output is binary image
{
  Mat temp, dst;

  temp = src.clone();
  if (temp.channels() == 3)
    cvtColor(temp, temp, COLOR_BGR2GRAY);
  threshold(temp, dst, 100, 255, THRESH_OTSU);
  return dst;
}

Mat ImageProc::cartesianRotate(
    Mat src, int method) // Input can be 0 , positive or negative integers
{
  Mat temp, rotated;
  temp = src.clone();
  if (method < 0)
    transpose(temp, temp);
  rotated =
      Mat(temp.rows, temp.cols, CV_MAKETYPE(CV_8U, temp.channels()));
  flip(temp, rotated, 1);
  if (method > 0)
    transpose(rotated, rotated);
  if (method == 0)
    flip(rotated, rotated, 0);
  return rotated;
}

Mat ImageProc::mirrorImage(Mat src, int method) // Input can be 0 or non zero
{
  Mat image, mirrored;
  image = src.clone();

  mirrored = image.clone(); // Mat(image.rows, image.cols,
                            // COLOR_MAKETYPE(COLOR_8U, image.channels()));
  if (method == 0)
    flip(image, mirrored, 1);
  else
    flip(image, mirrored, 0);
  return mirrored;
}
Mat ImageProc::doMedianBlur(Mat src, int ksize) {
  Mat temp, blurred;
  temp = src.clone();
  if (ksize > (temp.rows - 2))
    ksize = temp.rows - 2;
  if (ksize > (temp.cols - 2))
    ksize = (temp.cols - 2);
  ksize = ksize + (ksize % 2) - 1;
  medianBlur(temp, blurred, ksize);
  return blurred;
}
Mat ImageProc::doBlur(Mat src, int xsize, int ysize) {
  Mat temp, blurred;
  temp = src.clone();
  if (ysize > (temp.rows - 2))
    ysize = temp.rows - 2;
  if (xsize > (temp.cols - 2))
    xsize = (temp.cols - 2);
  ysize = ysize + (ysize % 2) - 1;
  xsize = xsize + (xsize % 2) - 1;
  blur(temp, blurred, Size(xsize, ysize));
  return blurred;
}
Mat ImageProc::doGaussianBlur(Mat src, int xsize, int ysize, int sigmaX,
                              int sigmaY) {
  Mat temp, blurred;
  temp = src.clone();
  if (ysize > (temp.rows - 2))
    ysize = temp.rows - 2;
  if (xsize > (temp.cols - 2))
    xsize = (temp.cols - 2);
  ysize = ysize + (ysize % 2) - 1;
  xsize = xsize + (xsize % 2) - 1;
  GaussianBlur(temp, blurred, Size(xsize, ysize), sigmaX, sigmaY);
  return blurred;
}
Mat ImageProc::cannyEdgeDetection(Mat src, int thresh1, int thresh2) {
  Mat temp, edges;
  temp = src.clone();
  Canny(temp, edges, thresh1, thresh2);
  return edges;
}
Mat ImageProc::threshInRange(Mat src, int low1, int low2, int low3, int high1,
                             int high2, int high3) {
  Mat temp, inrange;
  temp = src.clone();
  if (temp.channels() == 1)
    inRange(temp, Scalar(low1), Scalar(high1), inrange);
  if (temp.channels() == 3) {
    Scalar lowerLim = Scalar(low1, low2, low3);
    Scalar upperLim = Scalar(high1, high2, high3);
    inRange(temp, lowerLim, upperLim, inrange);
  }
  return inrange;
}
Mat ImageProc::toGrayscale(Mat src) // Can only convert BGR to Gray
{
  Mat temp, gray = src.clone();
  temp = src.clone();
  if (temp.channels() == 3) {
    gray = Mat::zeros(src.size(), CV_8UC1);
    cvtColor(temp, gray, COLOR_BGR2GRAY);
  }
  return gray;
}
Mat ImageProc::toHSV(Mat src) // Can only convert BGR to HSV
{
  Mat temp, hsv = src.clone();
  temp = src.clone();
  if (temp.channels() == 3) {
    cvtColor(temp, hsv, COLOR_BGR2HSV);
  }
  return hsv;
}
Mat ImageProc::toBGR(Mat src) // Can only convert HSV to BGR
{
  Mat temp, bgr = src.clone();
  temp = src.clone();
  if (temp.channels() == 3) {
    cvtColor(temp, bgr, COLOR_HSV2BGR);
  }
  return bgr;
}
Mat ImageProc::drawHistogram(Mat src) {
  Mat temp = src.clone();
  Mat histogram;

  vector<Mat> splitPlanes;
  split(temp, splitPlanes);

  /// Establish the number of bins
  int histSize = 256;

  /// Set the ranges ( for B,G,R) )
  float range[] = {0, 256};
  const float *histRange = {range};
  int hist_w = 512;
  int hist_h = 400;
  int bin_w = cvRound((double)hist_w / histSize);
  histogram = Mat::zeros(Size(hist_w, hist_w), CV_8UC3);

  bool uniform = true;
  bool accumulate = false;
  int imChannels = temp.channels();
  if (imChannels == 1) {
    Mat hist;
    calcHist(&splitPlanes[0], 1, 0, Mat(), hist, 1, &histSize, &histRange,
             uniform, accumulate);
    cv::normalize(hist, hist, 0, histogram.rows, NORM_MINMAX, -1, Mat());
    for (int i = 1; i < histSize; i++) {
      line(histogram,
           Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
           Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
           Scalar(0, 255, 255), 2, 8, 0);
    }
  }
  if (imChannels == 3) {
    Mat b_hist, g_hist, r_hist;

    /// Compute the histograms:
    calcHist(&splitPlanes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange,
             uniform, accumulate);
    calcHist(&splitPlanes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange,
             uniform, accumulate);
    calcHist(&splitPlanes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange,
             uniform, accumulate);

    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histogram.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histogram.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histogram.rows, NORM_MINMAX, -1, Mat());

    /// Draw for each channel
    for (int i = 1; i < histSize; i++) {
      line(histogram,
           Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
           Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
           Scalar(255, 0, 0), 2, 8, 0);
      line(histogram,
           Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
           Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
           Scalar(0, 255, 0), 2, 8, 0);
      line(histogram,
           Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
           Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
           Scalar(0, 0, 255), 2, 8, 0);
    }
  }

  return histogram;
}
Mat ImageProc::cropImage(Mat src, int x1, int y1, int x2, int y2) {
  Mat temp = src.clone();
  if (x1 >= x2 || y1 >= y2)
    return temp;
  Mat cropped = temp(Rect(x1, y1, (x2 - x1), (y2 - y1)));
  return cropped;
}
Mat ImageProc::splitChannels(Mat src, int channel) {
  Mat temp = src.clone();
  if (temp.channels() < channel)
    return temp;
  vector<Mat> imageChannels;
  split(temp, imageChannels);
  return imageChannels[channel - 1];
}
Mat ImageProc::erodeIm(Mat src, int erodex, int erodey) {
  Mat temp = src.clone();
  Mat erodingelement = getStructuringElement(MORPH_RECT, Size(erodex, erodey));
  erode(temp, temp, erodingelement);
  return temp;
}
Mat ImageProc::dilateIm(Mat src, int dilatex, int dilatey) {
  Mat temp = src.clone();
  Mat erodingelement =
      getStructuringElement(MORPH_RECT, Size(dilatex, dilatey));
  dilate(temp, temp, erodingelement);
  return temp;
}
Mat ImageProc::correctGamma(Mat &img, double gamma) {
  double inverse_gamma = 1.0 / gamma;

  Mat lut_matrix(1, 256, CV_8UC1);
  uchar *ptr = lut_matrix.ptr();
  for (int i = 0; i < 256; i++)
    ptr[i] = (int)(pow((double)i / 255.0, inverse_gamma) * 255.0);

  Mat result;
  LUT(img, lut_matrix, result);

  return result;
}
/*Mat ImageProc::detecthands(Mat src)
{
    Mat image = src.clone();
    String hand_cascade_name = "palm.xml";
    //String face_cascade_name =
"D:/Local/haarcascade/haarcascade_frontalface_alt2.xml"; CascadeClassifier
hand_cascade; hand_cascade.load( hand_cascade_name ); Mat image_gray;

        cvtColor( image, image_gray, COLOR_BGR2GRAY );
        equalizeHist( image_gray, image_gray );

        //hand_cascade.detectMultiScale( image_gray, hands, 1.1, 2,
0|COLOR_HAAR_SCALE_IMAGE, Size(30, 30),Size(400,400) );
        hand_cascade.detectMultiScale(image_gray,hands,1.1,3,0,Size(100,100));//,Size(640,480));

    //	int hmax,hmin,smax,smin,


        for(int i=0;i<hands.size();i++)
        {
            Point center(hands[i].x + hands[i].width/2, hands[i].y +
hands[i].height*4/5);
            rectangle(image,Point(hands[i].x,hands[i].y),Point(hands[i].x+hands[i].width,hands[i].y+hands[i].height*3/2),Scalar(255,255,0));
            int h = hands[i].height;
            circle(image,center,2,Scalar(255,0,255),COLOR_FILLED);
        }
    //CascadeClassifier face_cascade;
    return image;
}
Mat ImageProc::detectface(Mat src)
{
    Mat image = src.clone();
    //String hand_cascade_name = "palm.xml";
    String face_cascade_name = "haarcascade_frontalface_alt2.xml";
    CascadeClassifier face_cascade;
    face_cascade.load( face_cascade_name );
    Mat image_gray;
    cvtColor( image, image_gray, COLOR_BGR2GRAY );
    equalizeHist( image_gray, image_gray );

    //hand_cascade.detectMultiScale( image_gray, hands, 1.1, 2,
0|COLOR_HAAR_SCALE_IMAGE, Size(30, 30),Size(400,400) );
    face_cascade.detectMultiScale(image_gray,hands,1.1,3,0,Size(100,100));//,Size(640,480));

    //	int hmax,hmin,smax,smin,


        for(int i=0;i<hands.size();i++)
        {
            Point center(hands[i].x + hands[i].width/2, hands[i].y +
hands[i].height*4/5);
            rectangle(image,Point(hands[i].x,hands[i].y),Point(hands[i].x+hands[i].width,hands[i].y+hands[i].height*3/2),Scalar(255,255,0));
            int h = hands[i].height;
            circle(image,center,2,Scalar(255,0,255),COLOR_FILLED);
        }
    //CascadeClassifier face_cascade;
    return image;
}*/
