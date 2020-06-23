#include "imageproc.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  // setWindowIcon(QIcon(":/icons/images/icon.png"));
  QApplication a(argc, argv);
  ImageProc w;
  w.show();

  return a.exec();
}
