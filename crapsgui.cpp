#include "crapsgui.h"
#include "die.h"
#include "ui_crapsgui.h"
#include "Player.h"

#include <iostream>

Player user(0, 0);

CrapsGui::CrapsGui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

/*void CrapsGui::updateUI() {
    //    printf("Inside updateUI()\n");
    Die die1(0,0,0), die2(0, 0, 0);
    std::string die1ImageName = ":/dieImages/Resources/" + std::to_string(die1.getValue());
    std::string die2ImageName = ":/dieImages/Resources/" + std::to_string(die2.getValue());
    ui.die1UI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
    ui.die2UI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));

    //ui.currentBankValueUI->setText(QString::fromStdString("100"));
}*/

void CrapsGui::on_rollButton_clicked()
{
    int bid = ui.userBid->value();
    int bank = ui.currentBankValueUI->value();
    user.setBet(bid);

    // updateUI();
}