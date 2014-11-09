#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	private:
		Ui::MainWindow ui;

	public:
		MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
