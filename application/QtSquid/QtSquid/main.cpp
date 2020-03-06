#include "QtSquid.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtSquid w;
	w.show();
	return a.exec();
}
