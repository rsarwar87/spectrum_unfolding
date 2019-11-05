#include "multiunfold.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MultiUnfold w;
	w.show();
	return a.exec();
}
