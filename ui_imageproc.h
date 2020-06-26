/********************************************************************************
** Form generated from reading UI file 'learncv.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROC_H
#define UI_IMAGEPROC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProc
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QLabel *TextLabel1;
    QWidget *layoutWidget;
    QHBoxLayout *WinEn;
    QCheckBox *chk_WinEn1;
    QCheckBox *chk_WinEn2;
    QCheckBox *chk_WinEn3;
    QCheckBox *chk_WinEn4;
    QPushButton *btn_Up;
    QPushButton *btn_Down;
    QPushButton *btnRemove;
    QPushButton *btn_Add;
    QPushButton *btn_SetParam;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *btn_StartWebcam;
    QPushButton *btn_SwitchCam;
    QPushButton *btn_PausePlay;
    QPushButton *btn_LoadVid;
    QPushButton *btn_LoadImage;
    QPushButton *btn_Reset;
    QWidget *layoutWidget2;
    QGridLayout *Images;
    QLabel *Image1;
    QLabel *Image2;
    QLabel *Image3;
    QLabel *Image4;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *Base1;
    QRadioButton *rbt_Base1_Orig;
    QRadioButton *rbt_Base1_2;
    QRadioButton *rbt_Base1_4;
    QRadioButton *rbt_Base1_3;
    QGroupBox *Base2;
    QRadioButton *rbt_Base2_Orig;
    QRadioButton *rbt_Base2_3;
    QRadioButton *rbt_Base2_1;
    QRadioButton *rbt_Base2_4;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *list_OpList1;
    QListWidget *list_OpList2;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *ddl_OpBox1;
    QComboBox *ddl_OpBox2;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *Base3;
    QRadioButton *rbt_Base3_Orig;
    QRadioButton *rbt_Base3_1;
    QRadioButton *rbt_Base3_2;
    QRadioButton *rbt_Base3_4;
    QGroupBox *Base4;
    QRadioButton *rbt_Base4_Orig;
    QRadioButton *rbt_Base4_1;
    QRadioButton *rbt_Base4_2;
    QRadioButton *rbt_Base4_3;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *ddl_OpBox3;
    QComboBox *ddl_OpBox4;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *list_OpList3;
    QListWidget *list_OpList4;
    QLabel *label;
    QWidget *stackedWidgetPage2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageProc)
    {
        if (ImageProc->objectName().isEmpty())
            ImageProc->setObjectName(QString::fromUtf8("ImageProc"));
        ImageProc->setWindowModality(Qt::NonModal);
        ImageProc->resize(1004, 706);
        ImageProc->setCursor(QCursor(Qt::ArrowCursor));
        ImageProc->setAutoFillBackground(true);
        centralWidget = new QWidget(ImageProc);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1652, 681));
        stackedWidget->setMinimumSize(QSize(1652, 637));
        stackedWidget->setAutoFillBackground(true);
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QString::fromUtf8("stackedWidgetPage1"));
        TextLabel1 = new QLabel(stackedWidgetPage1);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        TextLabel1->setGeometry(QRect(650, 10, 433, 21));
        layoutWidget = new QWidget(stackedWidgetPage1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(670, 30, 311, 25));
        WinEn = new QHBoxLayout(layoutWidget);
        WinEn->setSpacing(6);
        WinEn->setContentsMargins(11, 11, 11, 11);
        WinEn->setObjectName(QString::fromUtf8("WinEn"));
        WinEn->setContentsMargins(0, 0, 0, 0);
        chk_WinEn1 = new QCheckBox(layoutWidget);
        chk_WinEn1->setObjectName(QString::fromUtf8("chk_WinEn1"));

        WinEn->addWidget(chk_WinEn1);

        chk_WinEn2 = new QCheckBox(layoutWidget);
        chk_WinEn2->setObjectName(QString::fromUtf8("chk_WinEn2"));

        WinEn->addWidget(chk_WinEn2);

        chk_WinEn3 = new QCheckBox(layoutWidget);
        chk_WinEn3->setObjectName(QString::fromUtf8("chk_WinEn3"));

        WinEn->addWidget(chk_WinEn3);

        chk_WinEn4 = new QCheckBox(layoutWidget);
        chk_WinEn4->setObjectName(QString::fromUtf8("chk_WinEn4"));

        WinEn->addWidget(chk_WinEn4);

        chk_WinEn2->raise();
        chk_WinEn1->raise();
        chk_WinEn3->raise();
        chk_WinEn4->raise();
        btn_Up = new QPushButton(stackedWidgetPage1);
        btn_Up->setObjectName(QString::fromUtf8("btn_Up"));
        btn_Up->setGeometry(QRect(510, 560, 61, 45));
        btn_Down = new QPushButton(stackedWidgetPage1);
        btn_Down->setObjectName(QString::fromUtf8("btn_Down"));
        btn_Down->setGeometry(QRect(570, 560, 71, 45));
        btnRemove = new QPushButton(stackedWidgetPage1);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setGeometry(QRect(570, 500, 80, 45));
        btn_Add = new QPushButton(stackedWidgetPage1);
        btn_Add->setObjectName(QString::fromUtf8("btn_Add"));
        btn_Add->setGeometry(QRect(506, 500, 61, 45));
        btn_SetParam = new QPushButton(stackedWidgetPage1);
        btn_SetParam->setObjectName(QString::fromUtf8("btn_SetParam"));
        btn_SetParam->setEnabled(true);
        btn_SetParam->setGeometry(QRect(670, 560, 311, 45));
        layoutWidget1 = new QWidget(stackedWidgetPage1);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 500, 481, 111));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_StartWebcam = new QPushButton(layoutWidget1);
        btn_StartWebcam->setObjectName(QString::fromUtf8("btn_StartWebcam"));
        btn_StartWebcam->setMinimumSize(QSize(140, 49));

        gridLayout->addWidget(btn_StartWebcam, 0, 0, 1, 1);

        btn_SwitchCam = new QPushButton(layoutWidget1);
        btn_SwitchCam->setObjectName(QString::fromUtf8("btn_SwitchCam"));
        btn_SwitchCam->setMinimumSize(QSize(140, 49));

        gridLayout->addWidget(btn_SwitchCam, 0, 1, 1, 1);

        btn_PausePlay = new QPushButton(layoutWidget1);
        btn_PausePlay->setObjectName(QString::fromUtf8("btn_PausePlay"));
        btn_PausePlay->setEnabled(false);
        btn_PausePlay->setMinimumSize(QSize(181, 49));
        btn_PausePlay->setCursor(QCursor(Qt::ArrowCursor));
        btn_PausePlay->setAutoFillBackground(true);
        btn_PausePlay->setFlat(false);

        gridLayout->addWidget(btn_PausePlay, 0, 2, 1, 1);

        btn_LoadVid = new QPushButton(layoutWidget1);
        btn_LoadVid->setObjectName(QString::fromUtf8("btn_LoadVid"));
        btn_LoadVid->setMinimumSize(QSize(140, 49));

        gridLayout->addWidget(btn_LoadVid, 1, 0, 1, 1);

        btn_LoadImage = new QPushButton(layoutWidget1);
        btn_LoadImage->setObjectName(QString::fromUtf8("btn_LoadImage"));
        btn_LoadImage->setMinimumSize(QSize(140, 49));

        gridLayout->addWidget(btn_LoadImage, 1, 1, 1, 1);

        btn_Reset = new QPushButton(layoutWidget1);
        btn_Reset->setObjectName(QString::fromUtf8("btn_Reset"));
        btn_Reset->setEnabled(true);
        btn_Reset->setMinimumSize(QSize(181, 49));
        btn_Reset->setCursor(QCursor(Qt::ArrowCursor));
        btn_Reset->setAutoFillBackground(true);
        btn_Reset->setFlat(false);

        gridLayout->addWidget(btn_Reset, 1, 2, 1, 1);

        layoutWidget2 = new QWidget(stackedWidgetPage1);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(5, 5, 648, 488));
        Images = new QGridLayout(layoutWidget2);
        Images->setSpacing(6);
        Images->setContentsMargins(11, 11, 11, 11);
        Images->setObjectName(QString::fromUtf8("Images"));
        Images->setContentsMargins(0, 0, 0, 0);
        Image1 = new QLabel(layoutWidget2);
        Image1->setObjectName(QString::fromUtf8("Image1"));
        Image1->setEnabled(true);
        Image1->setMinimumSize(QSize(320, 240));
        Image1->setAutoFillBackground(true);
        Image1->setFrameShape(QFrame::Box);

        Images->addWidget(Image1, 0, 0, 1, 1);

        Image2 = new QLabel(layoutWidget2);
        Image2->setObjectName(QString::fromUtf8("Image2"));
        Image2->setMinimumSize(QSize(320, 240));
        Image2->setAutoFillBackground(true);
        Image2->setFrameShape(QFrame::Box);

        Images->addWidget(Image2, 0, 1, 1, 1);

        Image3 = new QLabel(layoutWidget2);
        Image3->setObjectName(QString::fromUtf8("Image3"));
        Image3->setAutoFillBackground(true);
        Image3->setFrameShape(QFrame::Box);

        Images->addWidget(Image3, 1, 0, 1, 1);

        Image4 = new QLabel(layoutWidget2);
        Image4->setObjectName(QString::fromUtf8("Image4"));
        Image4->setMinimumSize(QSize(320, 240));
        Image4->setAutoFillBackground(true);
        Image4->setFrameShape(QFrame::Box);

        Images->addWidget(Image4, 1, 1, 1, 1);

        layoutWidget3 = new QWidget(stackedWidgetPage1);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(671, 60, 311, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Base1 = new QGroupBox(layoutWidget3);
        Base1->setObjectName(QString::fromUtf8("Base1"));
        Base1->setEnabled(true);
        rbt_Base1_Orig = new QRadioButton(Base1);
        rbt_Base1_Orig->setObjectName(QString::fromUtf8("rbt_Base1_Orig"));
        rbt_Base1_Orig->setEnabled(false);
        rbt_Base1_Orig->setGeometry(QRect(16, 48, 79, 23));
        rbt_Base1_Orig->setChecked(true);
        rbt_Base1_2 = new QRadioButton(Base1);
        rbt_Base1_2->setObjectName(QString::fromUtf8("rbt_Base1_2"));
        rbt_Base1_2->setEnabled(false);
        rbt_Base1_2->setGeometry(QRect(9, 13, 29, 23));
        rbt_Base1_4 = new QRadioButton(Base1);
        rbt_Base1_4->setObjectName(QString::fromUtf8("rbt_Base1_4"));
        rbt_Base1_4->setEnabled(false);
        rbt_Base1_4->setGeometry(QRect(79, 13, 29, 23));
        rbt_Base1_3 = new QRadioButton(Base1);
        rbt_Base1_3->setObjectName(QString::fromUtf8("rbt_Base1_3"));
        rbt_Base1_3->setEnabled(false);
        rbt_Base1_3->setGeometry(QRect(44, 13, 29, 23));

        horizontalLayout->addWidget(Base1);

        Base2 = new QGroupBox(layoutWidget3);
        Base2->setObjectName(QString::fromUtf8("Base2"));
        Base2->setEnabled(true);
        rbt_Base2_Orig = new QRadioButton(Base2);
        rbt_Base2_Orig->setObjectName(QString::fromUtf8("rbt_Base2_Orig"));
        rbt_Base2_Orig->setEnabled(false);
        rbt_Base2_Orig->setGeometry(QRect(16, 48, 79, 23));
        rbt_Base2_Orig->setChecked(true);
        rbt_Base2_3 = new QRadioButton(Base2);
        rbt_Base2_3->setObjectName(QString::fromUtf8("rbt_Base2_3"));
        rbt_Base2_3->setEnabled(false);
        rbt_Base2_3->setGeometry(QRect(47, 13, 32, 23));
        rbt_Base2_1 = new QRadioButton(Base2);
        rbt_Base2_1->setObjectName(QString::fromUtf8("rbt_Base2_1"));
        rbt_Base2_1->setEnabled(false);
        rbt_Base2_1->setGeometry(QRect(9, 13, 32, 23));
        rbt_Base2_4 = new QRadioButton(Base2);
        rbt_Base2_4->setObjectName(QString::fromUtf8("rbt_Base2_4"));
        rbt_Base2_4->setEnabled(false);
        rbt_Base2_4->setGeometry(QRect(85, 13, 32, 23));

        horizontalLayout->addWidget(Base2);

        layoutWidget4 = new QWidget(stackedWidgetPage1);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(670, 180, 311, 121));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        list_OpList1 = new QListWidget(layoutWidget4);
        list_OpList1->setObjectName(QString::fromUtf8("list_OpList1"));

        horizontalLayout_2->addWidget(list_OpList1);

        list_OpList2 = new QListWidget(layoutWidget4);
        list_OpList2->setObjectName(QString::fromUtf8("list_OpList2"));

        horizontalLayout_2->addWidget(list_OpList2);

        layoutWidget5 = new QWidget(stackedWidgetPage1);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(670, 150, 311, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ddl_OpBox1 = new QComboBox(layoutWidget5);
        ddl_OpBox1->setObjectName(QString::fromUtf8("ddl_OpBox1"));
        ddl_OpBox1->setEnabled(false);

        horizontalLayout_3->addWidget(ddl_OpBox1);

        ddl_OpBox2 = new QComboBox(layoutWidget5);
        ddl_OpBox2->setObjectName(QString::fromUtf8("ddl_OpBox2"));
        ddl_OpBox2->setEnabled(false);

        horizontalLayout_3->addWidget(ddl_OpBox2);

        layoutWidget6 = new QWidget(stackedWidgetPage1);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(670, 310, 311, 71));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Base3 = new QGroupBox(layoutWidget6);
        Base3->setObjectName(QString::fromUtf8("Base3"));
        Base3->setEnabled(true);
        rbt_Base3_Orig = new QRadioButton(Base3);
        rbt_Base3_Orig->setObjectName(QString::fromUtf8("rbt_Base3_Orig"));
        rbt_Base3_Orig->setEnabled(false);
        rbt_Base3_Orig->setGeometry(QRect(16, 48, 79, 23));
        rbt_Base3_Orig->setChecked(true);
        rbt_Base3_1 = new QRadioButton(Base3);
        rbt_Base3_1->setObjectName(QString::fromUtf8("rbt_Base3_1"));
        rbt_Base3_1->setEnabled(false);
        rbt_Base3_1->setGeometry(QRect(9, 13, 32, 23));
        rbt_Base3_2 = new QRadioButton(Base3);
        rbt_Base3_2->setObjectName(QString::fromUtf8("rbt_Base3_2"));
        rbt_Base3_2->setEnabled(false);
        rbt_Base3_2->setGeometry(QRect(47, 13, 32, 23));
        rbt_Base3_4 = new QRadioButton(Base3);
        rbt_Base3_4->setObjectName(QString::fromUtf8("rbt_Base3_4"));
        rbt_Base3_4->setEnabled(false);
        rbt_Base3_4->setGeometry(QRect(85, 13, 32, 23));

        horizontalLayout_4->addWidget(Base3);

        Base4 = new QGroupBox(layoutWidget6);
        Base4->setObjectName(QString::fromUtf8("Base4"));
        Base4->setEnabled(true);
        rbt_Base4_Orig = new QRadioButton(Base4);
        rbt_Base4_Orig->setObjectName(QString::fromUtf8("rbt_Base4_Orig"));
        rbt_Base4_Orig->setEnabled(false);
        rbt_Base4_Orig->setGeometry(QRect(16, 48, 79, 23));
        rbt_Base4_Orig->setChecked(true);
        rbt_Base4_1 = new QRadioButton(Base4);
        rbt_Base4_1->setObjectName(QString::fromUtf8("rbt_Base4_1"));
        rbt_Base4_1->setEnabled(false);
        rbt_Base4_1->setGeometry(QRect(9, 13, 29, 23));
        rbt_Base4_2 = new QRadioButton(Base4);
        rbt_Base4_2->setObjectName(QString::fromUtf8("rbt_Base4_2"));
        rbt_Base4_2->setEnabled(false);
        rbt_Base4_2->setGeometry(QRect(44, 13, 29, 23));
        rbt_Base4_3 = new QRadioButton(Base4);
        rbt_Base4_3->setObjectName(QString::fromUtf8("rbt_Base4_3"));
        rbt_Base4_3->setEnabled(false);
        rbt_Base4_3->setGeometry(QRect(79, 13, 29, 23));

        horizontalLayout_4->addWidget(Base4);

        layoutWidget7 = new QWidget(stackedWidgetPage1);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(670, 390, 311, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        ddl_OpBox3 = new QComboBox(layoutWidget7);
        ddl_OpBox3->setObjectName(QString::fromUtf8("ddl_OpBox3"));
        ddl_OpBox3->setEnabled(false);

        horizontalLayout_5->addWidget(ddl_OpBox3);

        ddl_OpBox4 = new QComboBox(layoutWidget7);
        ddl_OpBox4->setObjectName(QString::fromUtf8("ddl_OpBox4"));
        ddl_OpBox4->setEnabled(false);

        horizontalLayout_5->addWidget(ddl_OpBox4);

        layoutWidget8 = new QWidget(stackedWidgetPage1);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(670, 420, 311, 131));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        list_OpList3 = new QListWidget(layoutWidget8);
        list_OpList3->setObjectName(QString::fromUtf8("list_OpList3"));

        horizontalLayout_6->addWidget(list_OpList3);

        list_OpList4 = new QListWidget(layoutWidget8);
        list_OpList4->setObjectName(QString::fromUtf8("list_OpList4"));

        horizontalLayout_6->addWidget(list_OpList4);

        label = new QLabel(stackedWidgetPage1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 620, 1011, 41));
        stackedWidget->addWidget(stackedWidgetPage1);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        TextLabel1->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        btn_Up->raise();
        btn_Down->raise();
        btnRemove->raise();
        btn_Add->raise();
        btn_SetParam->raise();
        label->raise();
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QString::fromUtf8("stackedWidgetPage2"));
        stackedWidget->addWidget(stackedWidgetPage2);
        ImageProc->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageProc);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1004, 21));
        ImageProc->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageProc);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImageProc->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageProc);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageProc->setStatusBar(statusBar);

        retranslateUi(ImageProc);

        QMetaObject::connectSlotsByName(ImageProc);
    } // setupUi

    void retranslateUi(QMainWindow *ImageProc)
    {
        ImageProc->setWindowTitle(QApplication::translate("ImageProc", "LearnCV", nullptr));
        TextLabel1->setText(QApplication::translate("ImageProc", "<html><head/><body><p align=\"center\">Active Image Boxes</p></body></html>", nullptr));
        chk_WinEn1->setText(QApplication::translate("ImageProc", "1", nullptr));
        chk_WinEn2->setText(QApplication::translate("ImageProc", "2", nullptr));
        chk_WinEn3->setText(QApplication::translate("ImageProc", "3", nullptr));
        chk_WinEn4->setText(QApplication::translate("ImageProc", "4", nullptr));
        btn_Up->setText(QApplication::translate("ImageProc", "Up", nullptr));
        btn_Down->setText(QApplication::translate("ImageProc", "Down", nullptr));
        btnRemove->setText(QApplication::translate("ImageProc", "Remove", nullptr));
        btn_Add->setText(QApplication::translate("ImageProc", "Add", nullptr));
        btn_SetParam->setText(QApplication::translate("ImageProc", "Set Parameters", nullptr));
        btn_StartWebcam->setText(QApplication::translate("ImageProc", "Start Webcam", nullptr));
        btn_SwitchCam->setText(QApplication::translate("ImageProc", "Switch Camera", nullptr));
        btn_PausePlay->setText(QApplication::translate("ImageProc", "Pause", nullptr));
        btn_LoadVid->setText(QApplication::translate("ImageProc", "Load Video", nullptr));
        btn_LoadImage->setText(QApplication::translate("ImageProc", "Load Image", nullptr));
        btn_Reset->setText(QApplication::translate("ImageProc", "Reset", nullptr));
        Image1->setText(QString());
        Image2->setText(QString());
        Image3->setText(QString());
        Image4->setText(QString());
        Base1->setTitle(QString());
        rbt_Base1_Orig->setText(QApplication::translate("ImageProc", "Original", nullptr));
        rbt_Base1_2->setText(QApplication::translate("ImageProc", "2", nullptr));
        rbt_Base1_4->setText(QApplication::translate("ImageProc", "4", nullptr));
        rbt_Base1_3->setText(QApplication::translate("ImageProc", "3", nullptr));
        Base2->setTitle(QString());
        rbt_Base2_Orig->setText(QApplication::translate("ImageProc", "Original", nullptr));
        rbt_Base2_3->setText(QApplication::translate("ImageProc", "3", nullptr));
        rbt_Base2_1->setText(QApplication::translate("ImageProc", "1", nullptr));
        rbt_Base2_4->setText(QApplication::translate("ImageProc", "4", nullptr));
        Base3->setTitle(QString());
        rbt_Base3_Orig->setText(QApplication::translate("ImageProc", "Original", nullptr));
        rbt_Base3_1->setText(QApplication::translate("ImageProc", "1", nullptr));
        rbt_Base3_2->setText(QApplication::translate("ImageProc", "2", nullptr));
        rbt_Base3_4->setText(QApplication::translate("ImageProc", "4", nullptr));
        Base4->setTitle(QString());
        rbt_Base4_Orig->setText(QApplication::translate("ImageProc", "Original", nullptr));
        rbt_Base4_1->setText(QApplication::translate("ImageProc", "1", nullptr));
        rbt_Base4_2->setText(QApplication::translate("ImageProc", "2", nullptr));
        rbt_Base4_3->setText(QApplication::translate("ImageProc", "3", nullptr));
        label->setText(QApplication::translate("ImageProc", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">LEARNCV</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageProc: public Ui_ImageProc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROC_H
