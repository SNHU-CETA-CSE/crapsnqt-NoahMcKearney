#include "crapsgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CrapsGui w;
	w.show();
	return a.exec();
}
