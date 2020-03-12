#include "StyleSheetWindow.h"

StyleSheetWindow::StyleSheetWindow(QWidget* parent)
	: QDialog(parent), ui(new Ui::Dialog),
	currentStyleSheet("")
{
	ui->setupUi(this);

	connect(ui->style_dropdownMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(changeStyleSheet(int)));
}

StyleSheetWindow::~StyleSheetWindow()
{
	delete ui;
}

void StyleSheetWindow::setContent(StyleSheetCache* cache)
{
	this->cache = cache;
	ui->style_dropdownMenu->clear();
	ui->style_dropdownMenu->addItem("---", "");
	foreach (QString styleSheet, cache->AllStyleSheets())
		ui->style_dropdownMenu->addItem(styleSheet.left(styleSheet.lastIndexOf(QChar('.'))), styleSheet);
}

void StyleSheetWindow::setStyleSheet(QString styleSheet)
{
	QStringList sheets = cache->AllStyleSheets();
	const int size = sheets.size();
	for (int ii = 0; ii < size; ++ii)
		if (sheets[ii] == styleSheet)
		{
			this->ui->style_dropdownMenu->setCurrentIndex(ii + 1);
			return;
		}
}

void StyleSheetWindow::changeStyleSheet(int currentIndex)
{
	if (currentIndex == 0)
		return;

	currentStyleSheet = ui->style_dropdownMenu->itemData(currentIndex).toString();
	cache->Set(this, currentStyleSheet);

	emit pickStyleSheet(currentStyleSheet);
}