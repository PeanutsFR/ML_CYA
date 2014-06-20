/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTest2;
    QAction *actionTest4;
    QAction *actionAbout;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_cam;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame_4;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QProgressBar *progressBar;
    QLabel *label_6;
    QLCDNumber *lcd_alt;
    QLabel *label_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_rendu;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_anim;
    QSpinBox *txt_anim;
    QPushButton *btn_keyctrl;
    QWidget *tab_7;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_takeoff;
    QPushButton *btn_land;
    QPushButton *btn_goup;
    QPushButton *btn_godown;
    QPushButton *btn_rotleft;
    QPushButton *btn_rotright;
    QPushButton *btn_chgCam;
    QPushButton *btn_drone_disconnect;
    QPushButton *btn_drone_connect;
    QWidget *tab_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QFrame *frame_5;
    QGridLayout *gridLayout_5;
<<<<<<< HEAD
    QLineEdit *txt_path;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label_7;
    QPushButton *btn_load;
    QLabel *label_8;
    QPushButton *btn_parcourir;
    QTabWidget *tabWidget_3;
    QWidget *tab_14;
    QWidget *tab_15;
=======
    QLabel *label_7;
    QPushButton *btn_creer;
    QPushButton *btn_load;
    QLineEdit *txt_path;
    QLabel *label_8;
    QPushButton *btn_parcourir;
    QComboBox *comboBox;
    QTabWidget *tabWidget_3;
    QWidget *tab;
    QWidget *tab_2;
>>>>>>> ff1037eb03b7b86a4e0a920f262d95dda3b9b141
    QMenuBar *menuBar;
    QMenu *menuBar_2;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(886, 799);
        MainWindow->setMaximumSize(QSize(16777215, 800));
        actionTest2 = new QAction(MainWindow);
        actionTest2->setObjectName(QStringLiteral("actionTest2"));
        actionTest4 = new QAction(MainWindow);
        actionTest4->setObjectName(QStringLiteral("actionTest4"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(label, 2, 0, 1, 1);

        frame = new QFrame(tab_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbl_cam = new QLabel(frame);
        lbl_cam->setObjectName(QStringLiteral("lbl_cam"));
        lbl_cam->setMinimumSize(QSize(400, 280));
        lbl_cam->setMaximumSize(QSize(400, 280));
        lbl_cam->setAutoFillBackground(true);
        lbl_cam->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbl_cam);


        gridLayout_3->addWidget(frame, 3, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 4, 1, 1, 1);

        frame_4 = new QFrame(tab_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        progressBar = new QProgressBar(frame_4);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 1, 1, 1, 1);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lcd_alt = new QLCDNumber(frame_4);
        lcd_alt->setObjectName(QStringLiteral("lcd_alt"));
        lcd_alt->setMaximumSize(QSize(16777215, 30));
        lcd_alt->setProperty("intValue", QVariant(0));

        gridLayout_2->addWidget(lcd_alt, 0, 1, 1, 1);


        gridLayout_3->addWidget(frame_4, 5, 1, 1, 1);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 2, 1, 1, 1);

        frame_2 = new QFrame(tab_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_rendu = new QLabel(frame_2);
        lbl_rendu->setObjectName(QStringLiteral("lbl_rendu"));
        lbl_rendu->setMinimumSize(QSize(400, 280));
        lbl_rendu->setMaximumSize(QSize(400, 280));
        lbl_rendu->setAutoFillBackground(true);
        lbl_rendu->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lbl_rendu);


        gridLayout_3->addWidget(frame_2, 3, 1, 1, 1);

        frame_3 = new QFrame(tab_3);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget_2 = new QTabWidget(frame_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_2 = new QVBoxLayout(tab_6);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_anim = new QPushButton(tab_6);
        btn_anim->setObjectName(QStringLiteral("btn_anim"));

        verticalLayout_2->addWidget(btn_anim);

        txt_anim = new QSpinBox(tab_6);
        txt_anim->setObjectName(QStringLiteral("txt_anim"));

        verticalLayout_2->addWidget(txt_anim);

        btn_keyctrl = new QPushButton(tab_6);
        btn_keyctrl->setObjectName(QStringLiteral("btn_keyctrl"));

        verticalLayout_2->addWidget(btn_keyctrl);

        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        verticalLayout_3 = new QVBoxLayout(tab_7);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btn_takeoff = new QPushButton(tab_7);
        btn_takeoff->setObjectName(QStringLiteral("btn_takeoff"));

        verticalLayout_3->addWidget(btn_takeoff);

        btn_land = new QPushButton(tab_7);
        btn_land->setObjectName(QStringLiteral("btn_land"));

        verticalLayout_3->addWidget(btn_land);

        btn_goup = new QPushButton(tab_7);
        btn_goup->setObjectName(QStringLiteral("btn_goup"));

        verticalLayout_3->addWidget(btn_goup);

        btn_godown = new QPushButton(tab_7);
        btn_godown->setObjectName(QStringLiteral("btn_godown"));

        verticalLayout_3->addWidget(btn_godown);

        btn_rotleft = new QPushButton(tab_7);
        btn_rotleft->setObjectName(QStringLiteral("btn_rotleft"));

        verticalLayout_3->addWidget(btn_rotleft);

        btn_rotright = new QPushButton(tab_7);
        btn_rotright->setObjectName(QStringLiteral("btn_rotright"));

        verticalLayout_3->addWidget(btn_rotright);

        btn_chgCam = new QPushButton(tab_7);
        btn_chgCam->setObjectName(QStringLiteral("btn_chgCam"));

        verticalLayout_3->addWidget(btn_chgCam);

        tabWidget_2->addTab(tab_7, QString());

        verticalLayout->addWidget(tabWidget_2);


        gridLayout_3->addWidget(frame_3, 5, 0, 1, 1);

        btn_drone_disconnect = new QPushButton(tab_3);
        btn_drone_disconnect->setObjectName(QStringLiteral("btn_drone_disconnect"));

        gridLayout_3->addWidget(btn_drone_disconnect, 1, 1, 1, 1);

        btn_drone_connect = new QPushButton(tab_3);
        btn_drone_connect->setObjectName(QStringLiteral("btn_drone_connect"));

        gridLayout_3->addWidget(btn_drone_connect, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        frame_4->raise();
        frame->raise();
        label_3->raise();
        frame_3->raise();
        label_4->raise();
        label->raise();
        label_2->raise();
        frame_2->raise();
        btn_drone_disconnect->raise();
        btn_drone_connect->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame_5 = new QFrame(tab_5);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
<<<<<<< HEAD
        txt_path = new QLineEdit(frame_5);
        txt_path->setObjectName(QStringLiteral("txt_path"));

        gridLayout_5->addWidget(txt_path, 2, 2, 1, 1);
=======
        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        btn_creer = new QPushButton(frame_5);
        btn_creer->setObjectName(QStringLiteral("btn_creer"));

        gridLayout_5->addWidget(btn_creer, 1, 2, 1, 1);

        btn_load = new QPushButton(frame_5);
        btn_load->setObjectName(QStringLiteral("btn_load"));

        gridLayout_5->addWidget(btn_load, 3, 0, 1, 3);

        txt_path = new QLineEdit(frame_5);
        txt_path->setObjectName(QStringLiteral("txt_path"));

        gridLayout_5->addWidget(txt_path, 2, 1, 1, 1);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 2, 0, 1, 1);
>>>>>>> ff1037eb03b7b86a4e0a920f262d95dda3b9b141

        comboBox = new QComboBox(frame_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_5->addWidget(comboBox, 1, 2, 1, 1);

<<<<<<< HEAD
        pushButton = new QPushButton(frame_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_5->addWidget(pushButton, 1, 3, 1, 1);

        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 2, 0, 1, 1);
=======
        gridLayout_5->addWidget(btn_parcourir, 2, 2, 1, 1);
>>>>>>> ff1037eb03b7b86a4e0a920f262d95dda3b9b141

        comboBox = new QComboBox(frame_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));

<<<<<<< HEAD
        gridLayout_5->addWidget(btn_load, 3, 0, 1, 4);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 1, 0, 1, 1);

        btn_parcourir = new QPushButton(frame_5);
        btn_parcourir->setObjectName(QStringLiteral("btn_parcourir"));

        gridLayout_5->addWidget(btn_parcourir, 2, 3, 1, 1);
=======
        gridLayout_5->addWidget(comboBox, 1, 1, 1, 1);
>>>>>>> ff1037eb03b7b86a4e0a920f262d95dda3b9b141


        gridLayout_4->addWidget(frame_5, 0, 0, 1, 2);

        tabWidget_3 = new QTabWidget(tab_5);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
<<<<<<< HEAD
        tabWidget_3->setDocumentMode(false);
        tabWidget_3->setTabsClosable(true);
        tabWidget_3->setMovable(true);
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        tabWidget_3->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        tabWidget_3->addTab(tab_15, QString());
=======
        tabWidget_3->setTabsClosable(true);
        tabWidget_3->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_3->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_3->addTab(tab_2, QString());
>>>>>>> ff1037eb03b7b86a4e0a920f262d95dda3b9b141

        gridLayout_4->addWidget(tabWidget_3, 1, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 25));
        menuBar_2 = new QMenu(menuBar);
        menuBar_2->setObjectName(QStringLiteral("menuBar_2"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMouseTracking(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuBar_2->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar_2->addAction(actionTest2);
        menuBar_2->addAction(actionTest4);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Interface Drone v0.1", 0));
        actionTest2->setText(QApplication::translate("MainWindow", "Save", 0));
        actionTest4->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        label->setText(QApplication::translate("MainWindow", "Camera view :", 0));
        lbl_cam->setText(QApplication::translate("MainWindow", "Connexion to the drone required", 0));
        label_3->setText(QApplication::translate("MainWindow", "Drone commands :", 0));
        label_4->setText(QApplication::translate("MainWindow", "Informations :", 0));
        label_5->setText(QApplication::translate("MainWindow", "Battery : ", 0));
        label_6->setText(QApplication::translate("MainWindow", "Altitude (m) : ", 0));
        label_2->setText(QApplication::translate("MainWindow", "Grayscale : ", 0));
        lbl_rendu->setText(QApplication::translate("MainWindow", "Connexion to the drone required", 0));
        btn_anim->setText(QApplication::translate("MainWindow", "Drone animation", 0));
        btn_keyctrl->setText(QApplication::translate("MainWindow", "Keyboard control", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Anim/Keyboard ctrl", 0));
        btn_takeoff->setText(QApplication::translate("MainWindow", "Take off", 0));
        btn_land->setText(QApplication::translate("MainWindow", "Land", 0));
        btn_goup->setText(QApplication::translate("MainWindow", "Lift", 0));
        btn_godown->setText(QApplication::translate("MainWindow", "Descendre", 0));
        btn_rotleft->setText(QApplication::translate("MainWindow", "Rotate Left", 0));
        btn_rotright->setText(QApplication::translate("MainWindow", "Rotate Right", 0));
        btn_chgCam->setText(QApplication::translate("MainWindow", "Change camera", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Drone commands", 0));
        btn_drone_disconnect->setText(QApplication::translate("MainWindow", "Disconnect from the drone", 0));
        btn_drone_connect->setText(QApplication::translate("MainWindow", "Connect to the Drone", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Drone controls", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Algorithms", 0));
<<<<<<< HEAD
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_7->setText(QApplication::translate("MainWindow", "Chemin du fichier : ", 0));
        btn_load->setText(QApplication::translate("MainWindow", "Charger le fichier", 0));
        label_8->setText(QApplication::translate("MainWindow", "Choix de l'Algorithme :", 0));
        btn_parcourir->setText(QApplication::translate("MainWindow", "Parcourir", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_14), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_15), QApplication::translate("MainWindow", "Tab 2", 0));
=======
        label_7->setText(QApplication::translate("MainWindow", "Choix de l'Algorithme :", 0));
        btn_creer->setText(QApplication::translate("MainWindow", "Creer", 0));
        btn_load->setText(QApplication::translate("MainWindow", "Ouvrir le fichier", 0));
        label_8->setText(QApplication::translate("MainWindow", "Donn\303\251es :", 0));
        btn_parcourir->setText(QApplication::translate("MainWindow", "Parcourir", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
>>>>>>> ff1037eb03b7b86a4e0a920f262d95dda3b9b141
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Learning", 0));
        menuBar_2->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
#ifndef QT_NO_TOOLTIP
        statusBar->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Barre de status</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
