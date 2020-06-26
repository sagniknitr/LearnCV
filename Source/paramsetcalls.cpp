#include "learncv.h"
#include "parameters.h"
#include "setparameters.h"
#include "ui_learncv.h"
#include "ui_setparameters.h"
#define junk -1001

extern vector<parameters> paramlist[4]; // This stores parameter value
extern int pWinBindImageIndex;
extern int pWinBindOperationIndex;
extern bool paramWindowOpen;

void ImageProc::initializeGUI() {

  functionList.push_back("Original");         // 0 shows only original
  functionList.push_back("Threshold");        // 1 uses binary Threshold
  functionList.push_back("Auto-Theshold");    // 2 OTSU based autothreshold
  functionList.push_back("Cartesian Rotate"); // 3 Cartesian rotation
  functionList.push_back("Mirror");           // 4 Mirror x or mirror y
  functionList.push_back("Median Blur");   // 5 Removing salt and pepper noise
  functionList.push_back("Blur");          // 6 Kernel Blurring
  functionList.push_back("Gaussian Blur"); // 7 Gaussian blur
  functionList.push_back("Canny Edge Detection"); // 8 2nd order edge filter
  functionList.push_back("In Range"); // 9 Range type threshold with color
                                      // images
  functionList.push_back("Grayscale");      // 10 Grayscale
  functionList.push_back("HSV domain");     // 11 Hue Saturation Value
  functionList.push_back("BGR domain");     // 12 Blue Green Red
  functionList.push_back("Draw Histogram"); // 13 Histogram drawing
  functionList.push_back("Split Channels"); // 14 Split Channels
  /*    functionList.push_back("Gamma Correction");     //14 Gamma Correction
      functionList.push_back("Erode");                //15 Erode
      functionList.push_back("Dilate");               //16 Dilate
      functionList.push_back("Split Channels");       //17 Split Channels
      functionList.push_back("Detect face");          //18 Face detection by
     haar cascades functionList.push_back("Detect hands");         //19 Hand
     detection by haar cascades*/

  ui->ddl_OpBox1->addItems(functionList);
  ui->ddl_OpBox2->addItems(functionList);
  ui->ddl_OpBox3->addItems(functionList);
  ui->ddl_OpBox4->addItems(functionList);

  for (int i = 0; i < 4; i++)
    paramlist[i].clear();
}

void ImageProc::addParam(int index, int operation) {
  int set = processingList[index][operation];
  switch (set) {
  case 0:
    paramlist[index].push_back(parameters()); // Original
    break;
  case 1:
    paramlist[index].push_back(parameters(128)); // Thresh
    break;
  case 2:
    paramlist[index].push_back(parameters()); // Auto Thresh
    break;
  case 3:
    paramlist[index].push_back(parameters(0)); // Rotate
    break;
  case 4:
    paramlist[index].push_back(parameters(0)); // Mirror
    break;
  case 5:
    paramlist[index].push_back(parameters(3)); // Median Blur
    break;
  case 6:
    paramlist[index].push_back(parameters(3, 3)); // Blur
    break;
  case 7:
    paramlist[index].push_back(parameters(3, 3, 1, 0)); // Gaussian Blur
    break;
  case 8:
    paramlist[index].push_back(parameters(100, 200)); // Canny
    break;
  case 9:
    paramlist[index].push_back(
        parameters(100, 100, 100, 200, 200, 200)); // In Range
    break;
  case 10:
    paramlist[index].push_back(parameters()); // Grayscale
    break;
  case 11:
    paramlist[index].push_back(parameters()); // HSV
    break;
  case 12:
    paramlist[index].push_back(parameters()); // BGR
    break;
  case 13:
    paramlist[index].push_back(parameters()); // Histogram
    break;
  case 14:
    paramlist[index].push_back(parameters(1)); // Split
    break;
  default:
    paramlist[index].push_back(parameters());
    break;
  }
}

void ImageProc::process() {
  for (int i = 0; i < 4; i++) {
    if (processingList[i].empty()) {
      baseImage[i].release();
      continue;
    }
    // Base image selection
    switch (i) {
    case 0:
      if (ui->rbt_Base1_Orig->isChecked())
        baseImage[i] = originalImage;
      else if (ui->rbt_Base1_2->isChecked())
        baseImage[i] = displayedImages[1];
      else if (ui->rbt_Base1_4->isChecked())
        baseImage[i] = displayedImages[2];
      else if (ui->rbt_Base1_4->isChecked())
        baseImage[i] = displayedImages[3];
      break;
    case 1:
      if (ui->rbt_Base2_Orig->isChecked())
        baseImage[i] = originalImage;
      else if (ui->rbt_Base2_1->isChecked())
        baseImage[i] = displayedImages[0];
      else if (ui->rbt_Base2_3->isChecked())
        baseImage[i] = displayedImages[2];
      else if (ui->rbt_Base2_4->isChecked())
        baseImage[i] = displayedImages[3];
      break;
    case 2:
      if (ui->rbt_Base3_Orig->isChecked())
        baseImage[i] = originalImage;
      else if (ui->rbt_Base3_1->isChecked())
        baseImage[i] = displayedImages[0];
      else if (ui->rbt_Base3_2->isChecked())
        baseImage[i] = displayedImages[1];
      else if (ui->rbt_Base3_4->isChecked())
        baseImage[i] = displayedImages[3];
      break;
    case 3:
      if (ui->rbt_Base4_Orig->isChecked())
        baseImage[i] = originalImage;
      else if (ui->rbt_Base4_1->isChecked())
        baseImage[i] = displayedImages[0];
      else if (ui->rbt_Base4_2->isChecked())
        baseImage[i] = displayedImages[1];
      else if (ui->rbt_Base4_3->isChecked())
        baseImage[i] = displayedImages[2];
      break;
    }
    if (baseImage[i].empty())
      continue;
    processedImage[i] = baseImage[i];

    // Processing selection
    for (int j = 0; j < processingList[i].size(); j++) {
      paramIndex[0] = i;
      paramIndex[1] = j;
      switch (processingList[i][j]) {
      case 0:
        processedImage[i] = originalImage.clone();
        break;
      case 1:
        processedImage[i] =
            threshBinary(processedImage[i], paramlist[i][j].track1);
        break;
      case 2:
        processedImage[i] = threshAuto(processedImage[i]);
        break;
      case 3:
        processedImage[i] =
            cartesianRotate(processedImage[i], paramlist[i][j].track1);
        break;
      case 4:
        processedImage[i] =
            mirrorImage(processedImage[i], paramlist[i][j].track1);
        break;
      case 5:
        processedImage[i] =
            doMedianBlur(processedImage[i], paramlist[i][j].track1);
        break;
      case 6:
        processedImage[i] = doBlur(processedImage[i], paramlist[i][j].track1,
                                   paramlist[i][j].track2);
        break;
      case 7:
        processedImage[i] = doGaussianBlur(
            processedImage[i], paramlist[i][j].track1, paramlist[i][j].track2,
            paramlist[i][j].track3, paramlist[i][j].track4);
        break;
      case 8:
        processedImage[i] = cannyEdgeDetection(
            processedImage[i], paramlist[i][j].track1, paramlist[i][j].track2);
        break;
      case 9:
        processedImage[i] = threshInRange(
            processedImage[i], paramlist[i][j].track1, paramlist[i][j].track2,
            paramlist[i][j].track3, paramlist[i][j].track4,
            paramlist[i][j].track5, paramlist[i][j].track6);
        break;
      case 10:
        processedImage[i] = toGrayscale(processedImage[i]);
        break;
      case 11:
        processedImage[i] = toHSV(processedImage[i]);
        break;
      case 12:
        processedImage[i] = toBGR(processedImage[i]);
        break;
      case 13:
        processedImage[i] = drawHistogram(processedImage[i]);
        break;
        //  case 14: processedImage[i] =
        //  correctGamma(processedImage[i],paramlist[i][j].track1);
        //        break;
      case 14:
        processedImage[i] =
            splitChannels(processedImage[i], paramlist[i][j].track1);
        break;
      default:
        processedImage[i] = originalImage.clone();
        break;
      }
    }
  }
}

void ImageProc::on_btn_SetParam_clicked() {
  if (paramWindowOpen)
    return;
  clearParametersWindow();
  if (opListIndex == junk || selectedListIndex == junk)
    return;
  pWinBindImageIndex = opListIndex;
  pWinBindOperationIndex = selectedListIndex;
  setParam = processingList[opListIndex][selectedListIndex];
  //  cout << opListIndex << " " << selectedListIndex << endl;
  switch (setParam) {
  case 0:
    break; // 0 is Original
  case 1:
    paramWindowSet(1, "Threshold", 0, 255); // 1 is Threshold
    break;
  case 2:
    break; // 2 is Auto Threshold
  case 3:
    paramWindowSet(1, "Rotation Axis", -1, 1); // 3 is Cartesian Rotate
    break;
  case 4:
    paramWindowSet(1, "Mirror Axis", 0, 1); // 4 is Mirror
    break;
  case 5:
    paramWindowSet(1, "Kernel Size", 3, 25); // 5 is Median Blur
    break;
  case 6:
    paramWindowSet(1, "Kernel X", 1, 25); // 6 is Normal Blur
    paramWindowSet(2, "Kernel Y", 1, 25);
    break;
  case 7:
    paramWindowSet(1, "Kernel X", 1, 25); // 7 is Gaussian Blur
    paramWindowSet(2, "Kernel Y", 1, 25);
    paramWindowSet(3, "Sigma X", 0, 100);
    paramWindowSet(4, "Sigma Y", 0, 100);
    break;
  case 8:
    paramWindowSet(1, "Lower Limit", 0, 254); // 8 is Canny
    paramWindowSet(2, "Upper Limit", 1, 255);
    break;

  case 9:
    paramWindowSet(1, "Channel 1 Low", 0, 255); // 9 is Inrange
    paramWindowSet(2, "Channel 2 Low", 0, 255);
    paramWindowSet(3, "Channel 3 Low", 0, 255);
    paramWindowSet(4, "Channel 1 High", 0, 255);
    paramWindowSet(5, "Channel 2 High", 0, 255);
    paramWindowSet(6, "Channel 3 High", 0, 255);
  case 10:
    break; // 10 is Grayscale
  case 11:
    break; // 11 is HSV
  case 12:
    break; // 12 is BGR
  case 13:
    break; // 13 is Histogram
    // case 14: break;                                                   //14 is
    // CorrectGamma
  case 16:
    break; // 16 is Contours
  case 14:
    paramWindowSet(1, "Channel", 1, 3); // 24 is Split
    break;
  default:
    break;
  }
  paramWindow->show();
  paramWindowOpen = true;
}
void ImageProc::paramWindowSet(int slidernum, QString Text, int lowerlimit,
                               int upperlimit) {
  switch (slidernum) {
  case 1:
    paramWindow->paramui->slider1->setEnabled(true);
    paramWindow->paramui->valueset1->setEnabled(true);
    paramWindow->paramui->lblparamname1->setText(Text);
    paramWindow->paramui->lbl_lowerlim1->setText(QString::number(lowerlimit));
    paramWindow->paramui->lbl_upperlim1->setText(QString::number(upperlimit));
    paramWindow->paramui->slider1->setRange(lowerlimit, upperlimit);
    paramWindow->paramui->slider1->setValue(
        paramlist[opListIndex][selectedListIndex].track1);
    paramWindow->paramui->valueset1->setText(
        QString::number(paramlist[opListIndex][selectedListIndex].track1));
    break;
  case 2:
    paramWindow->paramui->slider2->setEnabled(true);
    paramWindow->paramui->valueset2->setEnabled(true);
    paramWindow->paramui->lblparamname2->setText(Text);
    paramWindow->paramui->lbl_lowerlim2->setText(QString::number(lowerlimit));
    paramWindow->paramui->lbl_upperlim2->setText(QString::number(upperlimit));
    paramWindow->paramui->slider2->setRange(lowerlimit, upperlimit);
    paramWindow->paramui->slider2->setValue(
        paramlist[opListIndex][selectedListIndex].track2);
    paramWindow->paramui->valueset2->setText(
        QString::number(paramlist[opListIndex][selectedListIndex].track2));
    break;
  case 3:
    paramWindow->paramui->slider3->setEnabled(true);
    paramWindow->paramui->valueset3->setEnabled(true);
    paramWindow->paramui->lblparamname3->setText(Text);
    paramWindow->paramui->lbl_lowerlim3->setText(QString::number(lowerlimit));
    paramWindow->paramui->lbl_upperlim3->setText(QString::number(upperlimit));
    paramWindow->paramui->slider3->setRange(lowerlimit, upperlimit);
    paramWindow->paramui->slider3->setValue(
        paramlist[opListIndex][selectedListIndex].track3);
    paramWindow->paramui->valueset3->setText(
        QString::number(paramlist[opListIndex][selectedListIndex].track3));
    break;
  case 4:
    paramWindow->paramui->slider4->setEnabled(true);
    paramWindow->paramui->valueset4->setEnabled(true);
    paramWindow->paramui->lblparamname4->setText(Text);
    paramWindow->paramui->lbl_lowerlim4->setText(QString::number(lowerlimit));
    paramWindow->paramui->lbl_upperlim4->setText(QString::number(upperlimit));
    paramWindow->paramui->slider4->setRange(lowerlimit, upperlimit);
    paramWindow->paramui->slider4->setValue(
        paramlist[opListIndex][selectedListIndex].track4);
    paramWindow->paramui->valueset4->setText(
        QString::number(paramlist[opListIndex][selectedListIndex].track4));
    break;

  case 5:
    paramWindow->paramui->slider5->setEnabled(true);
    paramWindow->paramui->valueset5->setEnabled(true);
    paramWindow->paramui->lblparamname5->setText(Text);
    paramWindow->paramui->lbl_lowerlim5->setText(QString::number(lowerlimit));
    paramWindow->paramui->lbl_upperlim5->setText(QString::number(upperlimit));
    paramWindow->paramui->slider5->setRange(lowerlimit, upperlimit);
    paramWindow->paramui->slider5->setValue(
        paramlist[opListIndex][selectedListIndex].track5);
    paramWindow->paramui->valueset5->setText(
        QString::number(paramlist[opListIndex][selectedListIndex].track5));
    break;
  case 6:
    paramWindow->paramui->slider6->setEnabled(true);
    paramWindow->paramui->valueset6->setEnabled(true);
    paramWindow->paramui->lblparamname6->setText(Text);
    paramWindow->paramui->lbl_lowerlim6->setText(QString::number(lowerlimit));
    paramWindow->paramui->lbl_upperlim6->setText(QString::number(upperlimit));
    paramWindow->paramui->slider6->setRange(lowerlimit, upperlimit);
    paramWindow->paramui->slider6->setValue(
        paramlist[opListIndex][selectedListIndex].track6);
    paramWindow->paramui->valueset6->setText(
        QString::number(paramlist[opListIndex][selectedListIndex].track6));
    break;
  default:
    break;
  }
}
