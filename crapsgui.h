#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_crapsgui.h"

class CrapsGui : public QMainWindow
{
	Q_OBJECT

public:
	CrapsGui(QWidget *parent = Q_NULLPTR);

private slots:
	void updateUI(bool bWonGame);
	void on_rollButton_clicked();

private:
	Ui::CrapsGuiClass ui;
};
