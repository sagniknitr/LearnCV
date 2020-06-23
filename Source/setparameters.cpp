#include "setparameters.h"
#include "imageproc.h"
#include "parameters.h"
#include "ui_imageproc.h"
#include "ui_setparameters.h"
#define junk -1001

extern vector<parameters> paramlist[4]; // This stores parameter value
extern int pWinBindImageIndex;
extern int pWinBindOperationIndex;
extern bool paramWindowOpen;

setparameters::setparameters(QWidget *parent)
    : QDialog(parent), paramui(new Ui::setparameters) {
  paramui->setupUi(this);
}

setparameters::~setparameters() { delete paramui; }

void setparameters::on_setparameters_rejected() { paramWindowOpen = false; }

/*void setparameters::on_slider1_valuechanged(int value)
{
    int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
    paramlist[bind_im][bind_op].track1 = value;
    paramui->valueset1->setText(QString::number(value));
}*/

void setparameters::on_slider1_sliderMoved(int value) {
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track1 = value;
  paramui->valueset1->setText(QString::number(value));
}

void setparameters::on_slider2_sliderMoved(int value) {
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track2 = value;
  paramui->valueset2->setText(QString::number(value));
}

void setparameters::on_slider3_sliderMoved(int value) {
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track3 = value;
  paramui->valueset3->setText(QString::number(value));
}

void setparameters::on_slider4_sliderMoved(int value) {
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track4 = value;
  paramui->valueset4->setText(QString::number(value));
}

void setparameters::on_slider5_sliderMoved(int value) {
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track5 = value;
  paramui->valueset5->setText(QString::number(value));
}

void setparameters::on_slider6_sliderMoved(int value) {
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track6 = value;
  paramui->valueset6->setText(QString::number(value));
}

void setparameters::on_valueset1_textEdited(const QString &arg1) {
  int value = arg1.toInt();
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track1 = value;
  paramui->slider1->setValue(value);
}

void setparameters::on_valueset2_textEdited(const QString &arg1) {
  int value = arg1.toInt();
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track2 = value;
  paramui->slider2->setValue(value);
}

void setparameters::on_valueset3_textEdited(const QString &arg1) {
  int value = arg1.toInt();
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track3 = value;
  paramui->slider3->setValue(value);
}

void setparameters::on_valueset4_textEdited(const QString &arg1) {
  int value = arg1.toInt();
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track4 = value;
  paramui->slider4->setValue(value);
}

void setparameters::on_valueset5_textEdited(const QString &arg1) {
  int value = arg1.toInt();
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track5 = value;
  paramui->slider5->setValue(value);
}

void setparameters::on_valueset6_textEdited(const QString &arg1) {
  int value = arg1.toInt();
  int bind_im = pWinBindImageIndex, bind_op = pWinBindOperationIndex;
  paramlist[bind_im][bind_op].track6 = value;
  paramui->slider6->setValue(value);
}
