#pragma once

#include <QtWidgets/QMainWindow>
#include "die.h"
#include "Player.h"
#include "ui_crapsgui.h"

class CrapsGui : public QMainWindow
{
	Q_OBJECT

public:
	CrapsGui(QWidget *parent = Q_NULLPTR);

private slots:
	void updateUI();
	void on_rollButton_clicked();
	Die die1, die2;
	Player user;

private:
	Ui::CrapsGuiClass ui;

};
