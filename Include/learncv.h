#ifndef IMAGEPROC_H
#define IMAGEPROC_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QtCore>

#include <vector>

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <parameters.h>
#include <setparameters.h>

#define junk -1001

using namespace cv;
using namespace std;

namespace Ui {
class ImageProc;
}

class ImageProc : public QMainWindow {
  Q_OBJECT

public:
  explicit ImageProc(QWidget *parent = 0);
  ~ImageProc();

protected:
  //--------------------------Global containers-------------------------------
  Mat read_Frame;
  Mat originalImage;
  Mat displayedImages[4];
  Mat capturedImage;
  VideoCapture capVideo;

  QImage Q_originalImage;
  QImage Q_displayedImages[4];
  QImage Q_temp;

  QTimer *GUI_Clock;

  QList<QString> functionList; // List of image processing functions ... DO NOT
                               // CHANGE THE ORDER
  vector<int>
      processingList[4]; // Stores the list of processing functions in stack

  int setParam;

  Mat processedImage[4];
  Mat baseImage[4];
  Mat tempImage;

  int paramIndex[2];

  int selectedListIndex;
  int opListIndex;
  enum OpticalFlowParam {
    LK = 0,
    TVL1,
    DIS,
    BM
  };


protected:
  //---------------------------Fuction protoypes------------------------------
  void initializeGUI();
  void updateGUI_Images();
  void enableControls();
  void process();
  void addParam(int, int);
  void clearParametersWindow();
  void paramWindowSet(int slidernum, QString Text, int lowerlimit,
                      int upperlimit);
  //---------------------------Image processing Fuctions----------------------
  void readFrame();

  Mat threshBinary(Mat, int);
  Mat threshAuto(Mat);
  Mat cartesianRotate(Mat, int);
  Mat mirrorImage(Mat, int);
  Mat doMedianBlur(Mat, int);
  Mat doBlur(Mat src, int xsize, int ysize);
  Mat doGaussianBlur(Mat src, int xsize, int ysize, int sigmaX, int sigmaY);
  Mat cannyEdgeDetection(Mat, int, int);
  Mat threshInRange(Mat, int, int, int, int, int, int);
  Mat toGrayscale(Mat);
  Mat toHSV(Mat);
  Mat toBGR(Mat);
  Mat drawHistogram(Mat);
  Mat cropImage(Mat, int, int, int, int);
  Mat splitChannels(Mat, int);
  Mat erodeIm(Mat src, int erodex, int erodey);
  Mat detectface(Mat src);
  Mat detecthands(Mat src);
  Mat correctGamma(Mat &img, double gamma);
  Mat dilateIm(Mat src, int dilatex, int dilatey);
  Mat opticalFlow(Mat frame_p, Mat frame_r, OpticalFlowParam params = LK);

  //--------------------------------------------------------------------------
public slots:
  void main_();

private slots:
  void on_btn_StartWebcam_clicked();

  void on_btn_PausePlay_clicked();

  void on_btn_Reset_clicked();

  void on_ddl_OpBox1_activated(int index);

  void on_btn_Add_clicked();

  void on_ddl_OpBox2_activated(int index);

  void on_ddl_OpBox3_activated(int index);

  void on_ddl_OpBox4_activated(int index);

  void on_btnRemove_clicked();

  void on_list_OpList1_itemClicked(QListWidgetItem *item);

  void on_list_OpList2_itemClicked(QListWidgetItem *item);

  void on_list_OpList3_itemClicked(QListWidgetItem *item);

  void on_list_OpList4_itemClicked(QListWidgetItem *item);

  void on_btn_SetParam_clicked();

  void on_chk_WinEn2_clicked(bool checked);

  void on_chk_WinEn3_clicked(bool checked);

  void on_chk_WinEn4_clicked(bool checked);

  void on_btn_SwitchCam_clicked();

  void on_btn_LoadVid_clicked();

  void on_btn_LoadImage_clicked();

public:
  Ui::ImageProc *ui;
  setparameters *paramWindow;
};

#endif // IMAGEPROC_H
