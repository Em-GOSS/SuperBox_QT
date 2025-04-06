/********************************************************************************
** Form generated from reading UI file 'superbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERBOX_H
#define UI_SUPERBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuperBoxClass
{
public:
    QAction *actionGame;
    QWidget *centralWidget;
    QPushButton *startButton;
    QGraphicsView *Bag_BackGround;
    QFrame *slot4;
    QFrame *slot3;
    QFrame *slot8;
    QFrame *slot2;
    QFrame *slot9;
    QFrame *slot6;
    QFrame *slot1;
    QFrame *slot5;
    QFrame *slot7;
    QFrame *slot0;
    QPushButton *Fox;
    QGraphicsView *SelectUI;
    QPushButton *Select_Button2;
    QPushButton *Select_Button3;
    QPushButton *Select_Button1;
    QPushButton *SlectButton;
    QLabel *SelectLabel;
    QGraphicsView *PropertiesUI;
    QGraphicsView *Property_Attack;
    QLabel *Property_AttackLabel;
    QLabel *Property_DefenceLabel;
    QGraphicsView *Property_Defence;
    QLabel *Property_HPLabel;
    QGraphicsView *Property_HP;
    QLabel *DesCriptonBox;
    QGraphicsView *BattleWindow;
    QGraphicsView *Player;

    void setupUi(QMainWindow *SuperBoxClass)
    {
        if (SuperBoxClass->objectName().isEmpty())
            SuperBoxClass->setObjectName(QString::fromUtf8("SuperBoxClass"));
        SuperBoxClass->resize(960, 480);
        SuperBoxClass->setMinimumSize(QSize(960, 480));
        SuperBoxClass->setMaximumSize(QSize(960, 480));
        SuperBoxClass->setMouseTracking(false);
        actionGame = new QAction(SuperBoxClass);
        actionGame->setObjectName(QString::fromUtf8("actionGame"));
        actionGame->setShortcutContext(Qt::WindowShortcut);
        actionGame->setAutoRepeat(true);
        actionGame->setVisible(true);
        centralWidget = new QWidget(SuperBoxClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/image/myfirstscene1.bmp);"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setEnabled(true);
        startButton->setGeometry(QRect(100, 200, 96, 64));
        startButton->setMouseTracking(true);
        startButton->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/image/mfc_Button2.bmp);"));
        Bag_BackGround = new QGraphicsView(centralWidget);
        Bag_BackGround->setObjectName(QString::fromUtf8("Bag_BackGround"));
        Bag_BackGround->setGeometry(QRect(620, 0, 280, 121));
        Bag_BackGround->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Bag.bmp);"));
        slot4 = new QFrame(centralWidget);
        slot4->setObjectName(QString::fromUtf8("slot4"));
        slot4->setGeometry(QRect(840, 18, 40, 42));
        slot4->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot4->setFrameShape(QFrame::StyledPanel);
        slot4->setFrameShadow(QFrame::Raised);
        slot3 = new QFrame(centralWidget);
        slot3->setObjectName(QString::fromUtf8("slot3"));
        slot3->setGeometry(QRect(790, 18, 40, 42));
        slot3->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot3->setFrameShape(QFrame::StyledPanel);
        slot3->setFrameShadow(QFrame::Raised);
        slot8 = new QFrame(centralWidget);
        slot8->setObjectName(QString::fromUtf8("slot8"));
        slot8->setGeometry(QRect(790, 63, 40, 42));
        slot8->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot8->setFrameShape(QFrame::StyledPanel);
        slot8->setFrameShadow(QFrame::Raised);
        slot2 = new QFrame(centralWidget);
        slot2->setObjectName(QString::fromUtf8("slot2"));
        slot2->setGeometry(QRect(739, 18, 41, 42));
        slot2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot2->setFrameShape(QFrame::StyledPanel);
        slot2->setFrameShadow(QFrame::Raised);
        slot9 = new QFrame(centralWidget);
        slot9->setObjectName(QString::fromUtf8("slot9"));
        slot9->setGeometry(QRect(840, 63, 40, 42));
        slot9->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);\n"
""));
        slot9->setFrameShape(QFrame::StyledPanel);
        slot9->setFrameShadow(QFrame::Raised);
        slot6 = new QFrame(centralWidget);
        slot6->setObjectName(QString::fromUtf8("slot6"));
        slot6->setGeometry(QRect(689, 63, 40, 42));
        slot6->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot6->setFrameShape(QFrame::StyledPanel);
        slot6->setFrameShadow(QFrame::Raised);
        slot1 = new QFrame(centralWidget);
        slot1->setObjectName(QString::fromUtf8("slot1"));
        slot1->setGeometry(QRect(689, 18, 40, 42));
        slot1->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot1->setFrameShape(QFrame::StyledPanel);
        slot1->setFrameShadow(QFrame::Raised);
        slot5 = new QFrame(centralWidget);
        slot5->setObjectName(QString::fromUtf8("slot5"));
        slot5->setGeometry(QRect(639, 63, 40, 42));
        slot5->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot5->setFrameShape(QFrame::StyledPanel);
        slot5->setFrameShadow(QFrame::Raised);
        slot7 = new QFrame(centralWidget);
        slot7->setObjectName(QString::fromUtf8("slot7"));
        slot7->setGeometry(QRect(739, 63, 41, 42));
        slot7->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot7->setFrameShape(QFrame::StyledPanel);
        slot7->setFrameShadow(QFrame::Raised);
        slot0 = new QFrame(centralWidget);
        slot0->setObjectName(QString::fromUtf8("slot0"));
        slot0->setGeometry(QRect(639, 18, 40, 42));
        slot0->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Inventory_Slot2.bmp);"));
        slot0->setFrameShape(QFrame::StyledPanel);
        slot0->setFrameShadow(QFrame::Raised);
        Fox = new QPushButton(centralWidget);
        Fox->setObjectName(QString::fromUtf8("Fox"));
        Fox->setGeometry(QRect(580, 10, 35, 35));
        Fox->setStyleSheet(QString::fromUtf8("background-image: url(:/image/24_bagICON.bmp);"));
        Fox->setAutoDefault(false);
        Fox->setFlat(false);
        SelectUI = new QGraphicsView(centralWidget);
        SelectUI->setObjectName(QString::fromUtf8("SelectUI"));
        SelectUI->setGeometry(QRect(240, 130, 491, 251));
        SelectUI->setStyleSheet(QString::fromUtf8("border-image: url(:/image/SelectUI.bmp);"));
        Select_Button2 = new QPushButton(centralWidget);
        Select_Button2->setObjectName(QString::fromUtf8("Select_Button2"));
        Select_Button2->setGeometry(QRect(449, 210, 64, 64));
        Select_Button2->setStyleSheet(QString::fromUtf8("background-image: url(:/image/cake1.bmp);"));
        Select_Button2->setIconSize(QSize(16, 16));
        Select_Button2->setAutoDefault(true);
        Select_Button2->setFlat(true);
        Select_Button3 = new QPushButton(centralWidget);
        Select_Button3->setObjectName(QString::fromUtf8("Select_Button3"));
        Select_Button3->setGeometry(QRect(530, 210, 64, 64));
        Select_Button3->setStyleSheet(QString::fromUtf8("background-image: url(:/image/cake1.bmp);"));
        Select_Button3->setIconSize(QSize(16, 16));
        Select_Button3->setAutoDefault(true);
        Select_Button3->setFlat(true);
        Select_Button1 = new QPushButton(centralWidget);
        Select_Button1->setObjectName(QString::fromUtf8("Select_Button1"));
        Select_Button1->setGeometry(QRect(368, 210, 64, 64));
        Select_Button1->setStyleSheet(QString::fromUtf8("background-image: url(:/image/cake1.bmp);"));
        Select_Button1->setIconSize(QSize(16, 16));
        Select_Button1->setAutoDefault(true);
        Select_Button1->setFlat(true);
        SlectButton = new QPushButton(centralWidget);
        SlectButton->setObjectName(QString::fromUtf8("SlectButton"));
        SlectButton->setEnabled(true);
        SlectButton->setGeometry(QRect(630, 320, 75, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Terminal"));
        font.setPointSize(20);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStyleStrategy(QFont::NoAntialias);
        SlectButton->setFont(font);
        SlectButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Bag.bmp);"));
        SelectLabel = new QLabel(centralWidget);
        SelectLabel->setObjectName(QString::fromUtf8("SelectLabel"));
        SelectLabel->setGeometry(QRect(432, 170, 100, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe Script"));
        font1.setBold(true);
        font1.setWeight(75);
        SelectLabel->setFont(font1);
        SelectLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/image/UILabel.bmp);"));
        SelectLabel->setTextFormat(Qt::RichText);
        SelectLabel->setAlignment(Qt::AlignCenter);
        PropertiesUI = new QGraphicsView(centralWidget);
        PropertiesUI->setObjectName(QString::fromUtf8("PropertiesUI"));
        PropertiesUI->setGeometry(QRect(0, 130, 48, 196));
        PropertiesUI->setStyleSheet(QString::fromUtf8("border-image: url(:/image/PropertiesUI.bmp);\n"
""));
        Property_Attack = new QGraphicsView(centralWidget);
        Property_Attack->setObjectName(QString::fromUtf8("Property_Attack"));
        Property_Attack->setGeometry(QRect(8, 140, 32, 32));
        Property_Attack->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Property_Attack.bmp);"));
        Property_AttackLabel = new QLabel(centralWidget);
        Property_AttackLabel->setObjectName(QString::fromUtf8("Property_AttackLabel"));
        Property_AttackLabel->setEnabled(true);
        Property_AttackLabel->setGeometry(QRect(4, 180, 40, 12));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Black"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        Property_AttackLabel->setFont(font2);
        Property_AttackLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Property_Text.bmp);"));
        Property_AttackLabel->setText(QString::fromUtf8(""));
        Property_AttackLabel->setTextFormat(Qt::AutoText);
        Property_AttackLabel->setScaledContents(true);
        Property_AttackLabel->setAlignment(Qt::AlignCenter);
        Property_DefenceLabel = new QLabel(centralWidget);
        Property_DefenceLabel->setObjectName(QString::fromUtf8("Property_DefenceLabel"));
        Property_DefenceLabel->setGeometry(QRect(4, 240, 40, 12));
        Property_DefenceLabel->setFont(font2);
        Property_DefenceLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Property_Text.bmp);"));
        Property_DefenceLabel->setText(QString::fromUtf8(""));
        Property_DefenceLabel->setTextFormat(Qt::AutoText);
        Property_DefenceLabel->setAlignment(Qt::AlignCenter);
        Property_Defence = new QGraphicsView(centralWidget);
        Property_Defence->setObjectName(QString::fromUtf8("Property_Defence"));
        Property_Defence->setGeometry(QRect(8, 200, 32, 32));
        Property_Defence->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Property_Denfence.bmp);"));
        Property_HPLabel = new QLabel(centralWidget);
        Property_HPLabel->setObjectName(QString::fromUtf8("Property_HPLabel"));
        Property_HPLabel->setGeometry(QRect(4, 300, 40, 12));
        Property_HPLabel->setFont(font2);
#ifndef QT_NO_TOOLTIP
        Property_HPLabel->setToolTip(QString::fromUtf8("Health"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Property_HPLabel->setStatusTip(QString::fromUtf8(""));
#endif // QT_NO_STATUSTIP
        Property_HPLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Property_Text.bmp);"));
        Property_HPLabel->setText(QString::fromUtf8(""));
        Property_HPLabel->setTextFormat(Qt::AutoText);
        Property_HPLabel->setAlignment(Qt::AlignCenter);
        Property_HP = new QGraphicsView(centralWidget);
        Property_HP->setObjectName(QString::fromUtf8("Property_HP"));
        Property_HP->setGeometry(QRect(8, 260, 32, 32));
        Property_HP->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Property_HP.bmp);"));
        DesCriptonBox = new QLabel(centralWidget);
        DesCriptonBox->setObjectName(QString::fromUtf8("DesCriptonBox"));
        DesCriptonBox->setGeometry(QRect(360, 280, 240, 80));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DesCriptonBox->sizePolicy().hasHeightForWidth());
        DesCriptonBox->setSizePolicy(sizePolicy);
        DesCriptonBox->setMinimumSize(QSize(240, 80));
        DesCriptonBox->setMaximumSize(QSize(240, 80));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        DesCriptonBox->setFont(font3);
        DesCriptonBox->setContextMenuPolicy(Qt::NoContextMenu);
        DesCriptonBox->setAcceptDrops(false);
        DesCriptonBox->setStyleSheet(QString::fromUtf8("border-image: url(:/image/Description_Box.bmp);"));
        DesCriptonBox->setFrameShape(QFrame::Box);
        DesCriptonBox->setFrameShadow(QFrame::Plain);
        DesCriptonBox->setTextFormat(Qt::AutoText);
        DesCriptonBox->setScaledContents(true);
        DesCriptonBox->setAlignment(Qt::AlignCenter);
        DesCriptonBox->setWordWrap(true);
        DesCriptonBox->setMargin(9);
        DesCriptonBox->setIndent(2);
        BattleWindow = new QGraphicsView(centralWidget);
        BattleWindow->setObjectName(QString::fromUtf8("BattleWindow"));
        BattleWindow->setGeometry(QRect(60, 60, 850, 380));
        BattleWindow->setStyleSheet(QString::fromUtf8("border-image: url(:/image/BattleWindow.bmp);\n"
""));
        Player = new QGraphicsView(centralWidget);
        Player->setObjectName(QString::fromUtf8("Player"));
        Player->setGeometry(QRect(170, 210, 96, 64));
        Player->setStyleSheet(QString::fromUtf8("border-image: url(:/image/mfc_Button2.bmp);"));
        SuperBoxClass->setCentralWidget(centralWidget);
        Fox->raise();
        SelectUI->raise();
        Select_Button2->raise();
        Select_Button3->raise();
        Select_Button1->raise();
        SlectButton->raise();
        SelectLabel->raise();
        PropertiesUI->raise();
        Property_Attack->raise();
        Property_AttackLabel->raise();
        Property_DefenceLabel->raise();
        Property_Defence->raise();
        Property_HPLabel->raise();
        Property_HP->raise();
        startButton->raise();
        DesCriptonBox->raise();
        BattleWindow->raise();
        Bag_BackGround->raise();
        slot0->raise();
        slot4->raise();
        slot6->raise();
        slot2->raise();
        slot7->raise();
        slot5->raise();
        slot8->raise();
        slot9->raise();
        slot1->raise();
        slot3->raise();
        Player->raise();
#ifndef QT_NO_SHORTCUT
        Property_AttackLabel->setBuddy(Property_Attack);
        Property_DefenceLabel->setBuddy(Property_Defence);
        Property_HPLabel->setBuddy(Property_HP);
#endif // QT_NO_SHORTCUT

        retranslateUi(SuperBoxClass);

        Fox->setDefault(false);
        Select_Button2->setDefault(false);
        Select_Button3->setDefault(false);
        Select_Button1->setDefault(false);


        QMetaObject::connectSlotsByName(SuperBoxClass);
    } // setupUi

    void retranslateUi(QMainWindow *SuperBoxClass)
    {
        SuperBoxClass->setWindowTitle(QApplication::translate("SuperBoxClass", "SuperBox", nullptr));
        actionGame->setText(QApplication::translate("SuperBoxClass", "Game", nullptr));
        startButton->setText(QString());
        Fox->setText(QString());
        Select_Button2->setText(QString());
        Select_Button3->setText(QString());
        Select_Button1->setText(QString());
        SlectButton->setText(QApplication::translate("SuperBoxClass", "Select", nullptr));
        SelectLabel->setText(QApplication::translate("SuperBoxClass", "Choose One", nullptr));
#ifndef QT_NO_TOOLTIP
        Property_AttackLabel->setToolTip(QApplication::translate("SuperBoxClass", "Attack", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        Property_DefenceLabel->setToolTip(QApplication::translate("SuperBoxClass", "Defence", nullptr));
#endif // QT_NO_TOOLTIP
        DesCriptonBox->setText(QApplication::translate("SuperBoxClass", "(\342\227\217'\342\227\241'\342\227\217)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperBoxClass: public Ui_SuperBoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERBOX_H
