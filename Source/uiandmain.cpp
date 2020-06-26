#include "learncv.h"
#include "parameters.h"
#include "setparameters.h"
#include "ui_learncv.h"
#include "ui_setparameters.h"
#define junk -1001

#include <QFileDialog>
//#include <QMessageBox>

bool camstarted = false; // if start camera is pressed or video is loaded
bool imageloaded = false;
bool videoloaded = false;
bool replayset = false;
bool origEmptyFlag = true; // data exception handling
bool paused = false;       // if paused is pressed

string loadedFile = "";

int cameraNumber = 0; // for switching cameras
int selectedOperationIndex = junk;
int OpBoxIndex = junk;

QImage::Format imgformat;

int pWinBindImageIndex;
int pWinBindOperationIndex;
bool paramWindowOpen;

vector<parameters> paramlist[4]; // This stores parameter value

// QMessageBox msgBox;

ImageProc::ImageProc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ImageProc) {
  // setWindowIcon(QIcon(":/icons/images/icon.png"));
  ui->setupUi(this);

  paramWindow = new setparameters();
  paramWindowOpen = false;
  selectedListIndex = junk;
  opListIndex = junk;
  initializeGUI();

  GUI_Clock = new QTimer(this);
  connect(GUI_Clock, SIGNAL(timeout()), this, SLOT(main_()));
  GUI_Clock->start(20);
}

ImageProc::~ImageProc() { delete ui; }

void ImageProc::readFrame() {
  if (!camstarted && !imageloaded)
    return;
  if (camstarted) {
    if (!(videoloaded && paused))
      capVideo.read(read_Frame);
    else
      return;
    if (videoloaded) {
      capVideo.read(read_Frame);
      if (capVideo.get(CAP_PROP_POS_FRAMES) ==
              capVideo.get(CAP_PROP_POS_FRAMES) &&
          !replayset) // Video stream  ended
      {
        paused = true;
        ui->btn_PausePlay->setText("Replay");
        replayset = true;
      }
    }
  }
  if (read_Frame.empty()) {
    origEmptyFlag = true;
    return;
  }
  if (!paused)
    originalImage =
        read_Frame
            .clone(); // frames will still be read but image processing not done
  origEmptyFlag = false;
}

void ImageProc::main_() {
  readFrame(); // Read frame from video or cam feed .. change later

  enableControls(); // Enable controls only if frame is read

  process(); // base image selection and processing calls

  updateGUI_Images(); // Update the images on the GUI .. do something else for
                      // paused
}

void ImageProc::updateGUI_Images() {
  // if(paused)
  //  return;
  tempImage.release();

  if (!processedImage[0].empty()) {
    if (processedImage[0].channels() == 3) {
      cvtColor(processedImage[0], tempImage, COLOR_BGR2RGB);
      imgformat = QImage::Format_RGB888;
    } else if (processedImage[0].channels() == 1) {
      tempImage = processedImage[0].clone();
      imgformat = QImage::Format_Indexed8;
    }
    displayedImages[0] = processedImage[0];
    cv::resize(tempImage, tempImage,
               Size(ui->Image1->width() - 2,
                    ui->Image1->height() -
                        2)); // size formatting .. -2 for the borders
    QImage Q_temp((uchar *)tempImage.data, tempImage.cols, tempImage.rows,
                  tempImage.step, imgformat); // convert to Qimage
    Q_displayedImages[0] = Q_temp;
    ui->Image1->setPixmap(
        QPixmap::fromImage(Q_displayedImages[0])); // Set qimage onto the label
  }

  if (!processedImage[1].empty()) {

    if (processedImage[1].channels() == 3) {
      cvtColor(processedImage[1], tempImage, COLOR_BGR2RGB);
      imgformat = QImage::Format_RGB888;
    } else if (processedImage[1].channels() == 1) {
      tempImage = processedImage[1].clone();
      imgformat = QImage::Format_Indexed8;
    }
    displayedImages[1] = processedImage[1].clone();
    cv::resize(tempImage, tempImage,
               Size(ui->Image2->width() - 2,
                    ui->Image2->height() -
                        2)); // size formatting .. -2 for the borders
    QImage Q_temp((uchar *)tempImage.data, tempImage.cols, tempImage.rows,
                  tempImage.step, imgformat); // convert to Qimage
    Q_displayedImages[1] = Q_temp;
    ui->Image2->setPixmap(
        QPixmap::fromImage(Q_displayedImages[1])); // Set qimage onto the label
  }

  if (!processedImage[2].empty()) {
    if (processedImage[2].channels() == 3) {
      cvtColor(processedImage[2], tempImage, COLOR_BGR2RGB);
      imgformat = QImage::Format_RGB888;
    } else if (processedImage[2].channels() == 1) {
      tempImage = processedImage[2].clone();
      imgformat = QImage::Format_Indexed8;
    }
    displayedImages[2] = processedImage[2];
    cv::resize(tempImage, tempImage,
               Size(ui->Image3->width() - 2,
                    ui->Image3->height() -
                        2)); // size formatting .. -2 for the borders
    QImage Q_temp((uchar *)tempImage.data, tempImage.cols, tempImage.rows,
                  tempImage.step, imgformat); // convert to Qimage
    Q_displayedImages[2] = Q_temp;
    ui->Image3->setPixmap(
        QPixmap::fromImage(Q_displayedImages[2])); // Set qimage onto the label
  }

  if (!processedImage[3].empty()) {
    if (processedImage[3].channels() == 3) {
      cvtColor(processedImage[3], tempImage, COLOR_BGR2RGB);
      imgformat = QImage::Format_RGB888;
    } else if (processedImage[3].channels() == 1) {
      tempImage = processedImage[3].clone();
      imgformat = QImage::Format_Indexed8;
    }
    displayedImages[3] = processedImage[3];
    cv::resize(tempImage, tempImage,
               Size(ui->Image4->width() - 2,
                    ui->Image4->height() -
                        2)); // size formatting .. -2 for the borders
    QImage Q_temp((uchar *)tempImage.data, tempImage.cols, tempImage.rows,
                  tempImage.step, imgformat); // convert to Qimage
    Q_displayedImages[3] = Q_temp;
    ui->Image4->setPixmap(
        QPixmap::fromImage(Q_displayedImages[3])); // Set qimage onto the label
  }

  bool showorig = false;
  if (processingList[0].empty())
    showorig = true;
  /*   else if(processingList[0].size() == 1)
     {    if(processingList[0][0] == 0)
             showorig=true; }*/
  else
    showorig = false;
  if (showorig) {
    if (originalImage.channels() == 3) {
      cvtColor(originalImage, tempImage, COLOR_BGR2RGB);
      imgformat = QImage::Format_RGB888;
    } else if (originalImage.channels() == 1) {
      tempImage = originalImage.clone();
      imgformat = QImage::Format_Indexed8;
    }
    if (origEmptyFlag)
      return;
    displayedImages[0] = originalImage;
    cvtColor(displayedImages[0], tempImage,
             COLOR_BGR2RGB); // opencv stores in BGR and Qt in RGB
    cv::resize(tempImage, tempImage,
               Size(ui->Image1->width() - 2,
                    ui->Image1->height() -
                        2)); // size formatting .. -2 for the borders
    QImage Q_originalImage((uchar *)tempImage.data, tempImage.cols,
                           tempImage.rows, tempImage.step,
                           imgformat); // convert to Qimage
    Q_displayedImages[0] = Q_originalImage;
    ui->Image1->setPixmap(
        QPixmap::fromImage(Q_displayedImages[0])); // Set qimage onto the label
  }

  /*    if(!processedImage[1].empty())
      {
          cv::resize(processedImage[1],tempImage,Size(ui->Image2->width()-2,ui->Image2->height()-2));
     // size formatting .. -2 for the borders QImage
     Q_temp((uchar*)tempImage.data,tempImage.cols,tempImage.rows,tempImage.step,QImage::Format_Indexed8);
     // convert to Qimage Q_displayedImages[1] = Q_temp;
          ui->Image2->setPixmap(QPixmap::fromImage(Q_displayedImages[1])); //
     Set qimage onto the label
      }*/
  // imshow("Named",originalImage);
}
void ImageProc::on_btn_StartWebcam_clicked() {
  imageloaded = false;
  videoloaded = false;
  if (camstarted) {
    camstarted = false;
    capVideo.release();
    ui->btn_StartWebcam->setText("Start Webcam");

    //  msgBox.setText("Error,Camera already open");
    //  msgBox.exec();
    //  QMessageBox("Error","Camera already open");
    return;
  }
  capVideo.open(cameraNumber);
  if (capVideo.isOpened() == false) {
    // msgBox.setText("Error,Camera cannot open");
    //  msgBox.exec();
    return;
  }
  camstarted = true;
  //  msgBox.setText("Success,Camera opened");
  // QMessageBox("Success","Camera opened");
  //  msgBox.exec();
  ui->btn_StartWebcam->setText(
      "Stop Webcam"); // once open,change the button to release capture
}
void ImageProc::on_btn_SwitchCam_clicked() {
  ui->btn_SwitchCam->setEnabled(false);
  if (camstarted) {
    capVideo.release();
  }
  cameraNumber++;
  // bool opensuccess = false;
  capVideo.open(cameraNumber);
  if (capVideo.isOpened() == false) {
    cameraNumber = 0;
    capVideo.open(cameraNumber);
    if (capVideo.isOpened() == false) {
      ui->btn_SwitchCam->setEnabled(true);
      ui->btn_SwitchCam->setText("No camera");
      camstarted = false;
      return;
    }
  }
  ui->btn_SwitchCam->setEnabled(true);
  return;
}
void ImageProc::on_btn_LoadVid_clicked() {
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open Video"), "C:/",
      tr("Video files (*.mp4 *.3gp *.avi *mkv *.flv *.divx *.mov *.wmv)"));
  if (camstarted) {
    capVideo.release();
    ui->btn_StartWebcam->setText("Start Webcam");
  }
  loadedFile = fileName.toStdString();
  capVideo.open(loadedFile);
  if (capVideo.isOpened() == false) {
    // capVideo.open(cameraNumber);
    // if(capVideo.isOpened() == false)
    //{
    camstarted = false;
    return;
    //}
  }
  cout << loadedFile << endl;
  videoloaded = true;
  camstarted = true;
  imageloaded = false;
  //    cout << file << endl;
}
void ImageProc::on_btn_LoadImage_clicked() {
  videoloaded = false;
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open Image"), "C:/",
      tr("Image files (*.jpg *.jpeg *.bmp *.png)"));
  if (camstarted) {
    capVideo.release();
    ui->btn_StartWebcam->setText("Start Webcam");
    camstarted = false;
  }
  loadedFile = fileName.toStdString();
  read_Frame = imread(loadedFile);
  if (!read_Frame.empty())
    imageloaded = true;
}
void ImageProc::enableControls() {
  bool origEmptyFlag = true;
  bool oFlagToggled = origEmptyFlag ^ originalImage.empty();
  origEmptyFlag = originalImage.empty();
  bool dispEmptyFlag[4] = {true, true, true, true};
  bool dFlagToggled[4];
  for (int i = 0; i < 4; i++) {
    dFlagToggled[i] = (dispEmptyFlag[i] ^ displayedImages[i].empty());
    dispEmptyFlag[i] = displayedImages[i].empty();
  }
  ui->btn_PausePlay->setEnabled(camstarted);

  if (oFlagToggled) {
    ui->chk_WinEn1->setEnabled(!origEmptyFlag);
    ui->chk_WinEn2->setEnabled(!origEmptyFlag);
    ui->chk_WinEn3->setEnabled(!origEmptyFlag);
    ui->chk_WinEn4->setEnabled(!origEmptyFlag);

    ui->chk_WinEn1->setChecked(!origEmptyFlag);

    ui->rbt_Base1_Orig->setEnabled(!origEmptyFlag);
    ui->rbt_Base2_Orig->setEnabled(!origEmptyFlag);
    ui->rbt_Base3_Orig->setEnabled(!origEmptyFlag);
    ui->rbt_Base4_Orig->setEnabled(!origEmptyFlag);
  }

  // Buttons for selecting base image

  if (dFlagToggled[0]) {
    ui->rbt_Base2_1->setEnabled(!dispEmptyFlag[0]);
    ui->rbt_Base3_1->setEnabled(!dispEmptyFlag[0]);
    ui->rbt_Base4_1->setEnabled(!dispEmptyFlag[0]);
  }
  if (dFlagToggled[1]) {
    ui->rbt_Base1_2->setEnabled(!dispEmptyFlag[1]);
    ui->rbt_Base3_2->setEnabled(!dispEmptyFlag[1]);
    ui->rbt_Base4_2->setEnabled(!dispEmptyFlag[1]);
  }
  if (dFlagToggled[2]) {
    ui->rbt_Base1_3->setEnabled(!dispEmptyFlag[2]);
    ui->rbt_Base2_3->setEnabled(!dispEmptyFlag[2]);
    ui->rbt_Base4_3->setEnabled(!dispEmptyFlag[2]);
  }
  if (dFlagToggled[3]) {
    ui->rbt_Base1_4->setEnabled(!dispEmptyFlag[3]);
    ui->rbt_Base2_4->setEnabled(!dispEmptyFlag[3]);
    ui->rbt_Base3_4->setEnabled(!dispEmptyFlag[3]);
  }

  ui->ddl_OpBox1->setEnabled(ui->chk_WinEn1->checkState());
  ui->ddl_OpBox2->setEnabled(ui->chk_WinEn2->checkState());
  ui->ddl_OpBox3->setEnabled(ui->chk_WinEn3->checkState());
  ui->ddl_OpBox4->setEnabled(ui->chk_WinEn4->checkState());
  // ui->btn_
}

void ImageProc::on_btn_PausePlay_clicked() {
  if (replayset) {
    cout << " Loaded " << loadedFile << endl;
    ui->btn_PausePlay->setText("Pause");
    replayset = false;
    capVideo.release();
    capVideo.open(loadedFile);
    paused = false;
    return;
  }
  paused = !paused;
  if (paused)
    ui->btn_PausePlay->setText("Resume");
  else
    ui->btn_PausePlay->setText("Pause");
}

void ImageProc::on_btn_Reset_clicked() {
  if (camstarted) {
    capVideo.release();
    ui->btn_StartWebcam->setText("Start Webcam");
  }

  origEmptyFlag = true;
  originalImage.release();

  ui->Image1->clear(); // Clear the image boxes
  ui->Image2->clear();
  ui->Image3->clear();
  ui->Image4->clear();

  ui->list_OpList1->clear(); // Clear the operation lists
  ui->list_OpList2->clear();
  ui->list_OpList3->clear();
  ui->list_OpList4->clear();

  ui->chk_WinEn1->setChecked(false); // Clear the window enable checks
  ui->chk_WinEn2->setChecked(false);
  ui->chk_WinEn3->setChecked(false);
  ui->chk_WinEn4->setChecked(false);

  ui->rbt_Base1_2->setEnabled(false);
  ui->rbt_Base1_3->setEnabled(false);
  ui->rbt_Base1_4->setEnabled(false);

  ui->rbt_Base2_1->setEnabled(false);
  ui->rbt_Base2_3->setEnabled(false);
  ui->rbt_Base2_4->setEnabled(false);

  ui->rbt_Base3_1->setEnabled(false);
  ui->rbt_Base3_2->setEnabled(false);
  ui->rbt_Base3_4->setEnabled(false);

  ui->rbt_Base4_1->setEnabled(false);
  ui->rbt_Base4_2->setEnabled(false);
  ui->rbt_Base4_3->setEnabled(false);

  ui->rbt_Base1_Orig->setEnabled(false);
  ui->rbt_Base2_Orig->setEnabled(false);
  ui->rbt_Base3_Orig->setEnabled(false);
  ui->rbt_Base4_Orig->setEnabled(false);

  ui->rbt_Base1_Orig->setChecked(true);
  ui->rbt_Base2_Orig->setChecked(true);
  ui->rbt_Base3_Orig->setChecked(true);
  ui->rbt_Base4_Orig->setChecked(true);

  for (int i = 0; i < 4; i++) {
    processingList[i].clear();
    displayedImages[i].release();
    baseImage[i].release();
    processedImage[i].release();
  }

  camstarted = false;
  imageloaded = false;
  replayset = false;
  videoloaded = false;
  paused = false;
  ui->btn_PausePlay->setText("Pause");
}

void ImageProc::on_ddl_OpBox1_activated(int index) {
  selectedOperationIndex = index;
  OpBoxIndex = 0;
}

void ImageProc::on_ddl_OpBox2_activated(int index) {
  selectedOperationIndex = index;
  OpBoxIndex = 1;
}

void ImageProc::on_ddl_OpBox3_activated(int index) {
  selectedOperationIndex = index;
  OpBoxIndex = 2;
}

void ImageProc::on_ddl_OpBox4_activated(int index) {
  selectedOperationIndex = index;
  OpBoxIndex = 3;
}

void ImageProc::on_btn_Add_clicked() {
  if (OpBoxIndex == junk || selectedOperationIndex == junk)
    return;
  switch (OpBoxIndex) {
  case 0:
    ui->list_OpList1->addItem(functionList[selectedOperationIndex]);
    processingList[OpBoxIndex].push_back(selectedOperationIndex);
    addParam(OpBoxIndex, processingList[OpBoxIndex].size() - 1);
    break;
  case 1:
    ui->list_OpList2->addItem(functionList[selectedOperationIndex]);
    processingList[OpBoxIndex].push_back(selectedOperationIndex);
    addParam(OpBoxIndex, processingList[OpBoxIndex].size() - 1);
    break;
  case 2:
    ui->list_OpList3->addItem(functionList[selectedOperationIndex]);
    processingList[OpBoxIndex].push_back(selectedOperationIndex);
    addParam(OpBoxIndex, processingList[OpBoxIndex].size() - 1);
    break;
  case 3:
    ui->list_OpList4->addItem(functionList[selectedOperationIndex]);
    processingList[OpBoxIndex].push_back(selectedOperationIndex);
    addParam(OpBoxIndex, processingList[OpBoxIndex].size() - 1);
    break;
  default:
    return;
  }
  selectedListIndex = processingList[OpBoxIndex].size() - 1;
  opListIndex = OpBoxIndex;
}

void ImageProc::on_btnRemove_clicked() {
  if (opListIndex == junk || selectedListIndex == junk)
    return;
  switch (opListIndex) {
  case 0:
    ui->list_OpList1->takeItem(selectedListIndex);
    processingList[0].erase(processingList[0].begin() + selectedListIndex);
    paramlist[0].erase(paramlist[0].begin() + selectedListIndex);
    if (paramlist[opListIndex].size() == 0) {
      baseImage[opListIndex].release();
      processedImage[opListIndex].release();
      displayedImages[opListIndex].release();
      ui->Image1->clear();
    }
    break;
  case 1:
    ui->list_OpList2->takeItem(selectedListIndex);
    processingList[1].erase(processingList[1].begin() + selectedListIndex);
    paramlist[1].erase(paramlist[1].begin() + selectedListIndex);
    if (paramlist[opListIndex].size() == 0) {
      baseImage[opListIndex].release();
      processedImage[opListIndex].release();
      displayedImages[opListIndex].release();
      ui->Image2->clear();
    }
    break;
  case 2:
    ui->list_OpList3->takeItem(selectedListIndex);
    processingList[2].erase(processingList[2].begin() + selectedListIndex);
    paramlist[2].erase(paramlist[2].begin() + selectedListIndex);
    if (paramlist[opListIndex].size() == 0) {
      baseImage[opListIndex].release();
      processedImage[opListIndex].release();
      displayedImages[opListIndex].release();
      ui->Image3->clear();
    }
    break;
  case 3:
    ui->list_OpList4->takeItem(selectedListIndex);
    processingList[3].erase(processingList[3].begin() + selectedListIndex);
    paramlist[3].erase(paramlist[3].begin() + selectedListIndex);
    if (paramlist[opListIndex].size() == 0) {
      baseImage[opListIndex].release();
      processedImage[opListIndex].release();
      displayedImages[opListIndex].release();
      ui->Image4->clear();
    }
    break;
  }
  opListIndex = junk;
  selectedListIndex = junk;
}

void ImageProc::on_list_OpList1_itemClicked(QListWidgetItem *item) {
  selectedListIndex = ui->list_OpList1->row(item);
  opListIndex = 0;
  // ui->btnRemove->setText(QString::number(selectedListIndex));
}

void ImageProc::on_list_OpList2_itemClicked(QListWidgetItem *item) {
  selectedListIndex = ui->list_OpList2->row(item);
  opListIndex = 1;
}

void ImageProc::on_list_OpList3_itemClicked(QListWidgetItem *item) {
  selectedListIndex = ui->list_OpList3->row(item);
  opListIndex = 2;
}

void ImageProc::on_list_OpList4_itemClicked(QListWidgetItem *item) {
  selectedListIndex = ui->list_OpList4->row(item);
  opListIndex = 3;
}

void ImageProc::clearParametersWindow() {
  paramWindow->paramui->slider1->setEnabled(false);
  paramWindow->paramui->slider2->setEnabled(false);
  paramWindow->paramui->slider3->setEnabled(false);
  paramWindow->paramui->slider4->setEnabled(false);
  paramWindow->paramui->slider5->setEnabled(false);
  paramWindow->paramui->slider6->setEnabled(false);

  paramWindow->paramui->lblparamname1->clear();
  paramWindow->paramui->lblparamname2->clear();
  paramWindow->paramui->lblparamname3->clear();
  paramWindow->paramui->lblparamname4->clear();
  paramWindow->paramui->lblparamname5->clear();
  paramWindow->paramui->lblparamname6->clear();

  paramWindow->paramui->valueset1->setEnabled(false);
  paramWindow->paramui->valueset2->setEnabled(false);
  paramWindow->paramui->valueset3->setEnabled(false);
  paramWindow->paramui->valueset4->setEnabled(false);
  paramWindow->paramui->valueset5->setEnabled(false);
  paramWindow->paramui->valueset6->setEnabled(false);

  paramWindow->paramui->valueset1->clear();
  paramWindow->paramui->valueset2->clear();
  paramWindow->paramui->valueset3->clear();
  paramWindow->paramui->valueset4->clear();
  paramWindow->paramui->valueset5->clear();
  paramWindow->paramui->valueset6->clear();
}
void ImageProc::on_chk_WinEn2_clicked(bool checked) {
  if (checked)
    ui->ddl_OpBox2->setEnabled(true);
  else {
    ui->list_OpList2->clear();
    paramlist[1].clear();
    processingList[1].clear();
    ui->ddl_OpBox2->setEnabled(false);
    baseImage[1].release();
    processedImage[1].release();
    displayedImages[1].release();
    ui->Image2->clear();
  }
}

void ImageProc::on_chk_WinEn3_clicked(bool checked) {
  if (checked)
    ui->ddl_OpBox3->setEnabled(true);
  else {
    ui->list_OpList3->clear();
    paramlist[2].clear();
    processingList[2].clear();
    ui->ddl_OpBox3->setEnabled(false);
    baseImage[2].release();
    processedImage[2].release();
    displayedImages[2].release();
    ui->Image3->clear();
  }
}

void ImageProc::on_chk_WinEn4_clicked(bool checked) {
  if (checked)
    ui->ddl_OpBox4->setEnabled(true);
  else {
    ui->list_OpList4->clear();
    paramlist[3].clear();
    processingList[3].clear();

    ui->ddl_OpBox4->setEnabled(false);
    baseImage[3].release();
    processedImage[3].release();
    displayedImages[3].release();
    ui->Image4->clear();
  }
}
