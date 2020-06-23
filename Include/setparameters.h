#ifndef SETPARAMETERS_H
#define SETPARAMETERS_H

#include <QDialog>

namespace Ui {
class setparameters;
}

class setparameters : public QDialog {
  Q_OBJECT

public:
  explicit setparameters(QWidget *parent = 0);
  ~setparameters();
  Ui::setparameters *paramui;
private slots:
  void on_valueset1_textEdited(const QString &arg1);
  void on_setparameters_rejected();
  //  void on_slider1_valuechanged(int value);
  void on_slider1_sliderMoved(int value);
  void on_slider2_sliderMoved(int value);
  void on_slider3_sliderMoved(int position);
  void on_slider4_sliderMoved(int position);
  void on_slider5_sliderMoved(int position);
  void on_slider6_sliderMoved(int position);
  void on_valueset2_textEdited(const QString &arg1);
  void on_valueset3_textEdited(const QString &arg1);
  void on_valueset4_textEdited(const QString &arg1);
  void on_valueset5_textEdited(const QString &arg1);
  void on_valueset6_textEdited(const QString &arg1);
};

#endif // SETPARAMETERS_H
