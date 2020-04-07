#pragma once
#include <QDialog>
#include "StyleSheetCache.h"
#include "ui_StyleSheetWnd.h"


class StyleSheetWindow : public QDialog
{
	Q_OBJECT

public:
	explicit StyleSheetWindow(QWidget* parent = 0);
	~StyleSheetWindow();

	void setContent(StyleSheetCache* cache);

	void setStyleSheet(QString styleSheet);

private:
	StyleSheetCache* cache;
	QString currentStyleSheet;

	Ui::Dialog ui;

signals:
	void pickStyleSheet(QString styleSheet);

private slots:
	void changeStyleSheet(int currentIndex);
};