/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btn_z;
    QPushButton *btn_s;
    QPushButton *btn_d;
    QPushButton *btn_q;
    QPushButton *btn_left;
    QPushButton *btn_up;
    QPushButton *btn_down;
    QPushButton *btn_right;
    QPushButton *btn_quit;
    QPushButton *btn_tkoff;
    QPushButton *btn_ctrl;
    QPushButton *btn_alt;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(451, 231);
        btn_z = new QPushButton(Dialog);
        btn_z->setObjectName(QStringLiteral("btn_z"));
        btn_z->setGeometry(QRect(90, 30, 61, 27));
        btn_z->setCheckable(false);
        btn_z->setDefault(false);
        btn_z->setFlat(false);
        btn_s = new QPushButton(Dialog);
        btn_s->setObjectName(QStringLiteral("btn_s"));
        btn_s->setGeometry(QRect(90, 60, 61, 27));
        btn_s->setCheckable(false);
        btn_s->setDefault(false);
        btn_s->setFlat(false);
        btn_d = new QPushButton(Dialog);
        btn_d->setObjectName(QStringLiteral("btn_d"));
        btn_d->setGeometry(QRect(160, 60, 61, 27));
        btn_d->setCheckable(false);
        btn_d->setDefault(false);
        btn_d->setFlat(false);
        btn_q = new QPushButton(Dialog);
        btn_q->setObjectName(QStringLiteral("btn_q"));
        btn_q->setGeometry(QRect(20, 60, 61, 27));
        btn_q->setCheckable(false);
        btn_q->setDefault(false);
        btn_q->setFlat(false);
        btn_left = new QPushButton(Dialog);
        btn_left->setObjectName(QStringLiteral("btn_left"));
        btn_left->setGeometry(QRect(240, 60, 61, 27));
        btn_left->setCheckable(false);
        btn_left->setDefault(false);
        btn_left->setFlat(false);
        btn_up = new QPushButton(Dialog);
        btn_up->setObjectName(QStringLiteral("btn_up"));
        btn_up->setGeometry(QRect(310, 30, 61, 27));
        btn_up->setCheckable(false);
        btn_up->setDefault(false);
        btn_up->setFlat(false);
        btn_down = new QPushButton(Dialog);
        btn_down->setObjectName(QStringLiteral("btn_down"));
        btn_down->setGeometry(QRect(310, 60, 61, 27));
        btn_down->setCheckable(false);
        btn_down->setDefault(false);
        btn_down->setFlat(false);
        btn_right = new QPushButton(Dialog);
        btn_right->setObjectName(QStringLiteral("btn_right"));
        btn_right->setGeometry(QRect(380, 60, 61, 27));
        btn_right->setCheckable(false);
        btn_right->setDefault(false);
        btn_right->setFlat(false);
        btn_quit = new QPushButton(Dialog);
        btn_quit->setObjectName(QStringLiteral("btn_quit"));
        btn_quit->setGeometry(QRect(326, 190, 111, 27));
        btn_quit->setCheckable(false);
        btn_quit->setDefault(false);
        btn_quit->setFlat(false);
        btn_tkoff = new QPushButton(Dialog);
        btn_tkoff->setObjectName(QStringLiteral("btn_tkoff"));
        btn_tkoff->setGeometry(QRect(20, 110, 421, 27));
        btn_tkoff->setCheckable(false);
        btn_tkoff->setDefault(false);
        btn_tkoff->setFlat(false);
        btn_ctrl = new QPushButton(Dialog);
        btn_ctrl->setObjectName(QStringLiteral("btn_ctrl"));
        btn_ctrl->setGeometry(QRect(20, 180, 61, 27));
        btn_ctrl->setCheckable(false);
        btn_ctrl->setDefault(false);
        btn_ctrl->setFlat(false);
        btn_alt = new QPushButton(Dialog);
        btn_alt->setObjectName(QStringLiteral("btn_alt"));
        btn_alt->setGeometry(QRect(130, 180, 61, 27));
        btn_alt->setCheckable(false);
        btn_alt->setDefault(false);
        btn_alt->setFlat(false);

        retranslateUi(Dialog);
        QObject::connect(btn_quit, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        btn_z->setText(QApplication::translate("Dialog", "Z", 0));
        btn_s->setText(QApplication::translate("Dialog", "S", 0));
        btn_d->setText(QApplication::translate("Dialog", "D", 0));
        btn_q->setText(QApplication::translate("Dialog", "Q", 0));
        btn_left->setText(QApplication::translate("Dialog", "<", 0));
        btn_up->setText(QApplication::translate("Dialog", "^", 0));
        btn_down->setText(QApplication::translate("Dialog", "v", 0));
        btn_right->setText(QApplication::translate("Dialog", ">", 0));
        btn_quit->setText(QApplication::translate("Dialog", "Quitter(Echap)", 0));
        btn_tkoff->setText(QApplication::translate("Dialog", "Decoller/ Atterir (Space)", 0));
        btn_ctrl->setText(QApplication::translate("Dialog", "Ctrl", 0));
        btn_alt->setText(QApplication::translate("Dialog", "Alt", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
