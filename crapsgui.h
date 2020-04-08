#pragma once

#include <QtWidgets/QMainWindow>
#include "die.h"
#include "ui_crapsgui.h"

class CrapsGui : public QMainWindow
{
	Q_OBJECT

public:
	CrapsGui(QWidget *parent = Q_NULLPTR);

private slots:
	//void updateUI();
	void on_rollButton_clicked();

private:
	Ui::CrapsGuiClass ui;
};
