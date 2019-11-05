#ifndef MULTIUNFOLD_H
#define MULTIUNFOLD_H

#include <QtWidgets/QMainWindow>
#include "ui_multiunfold.h"
#include <QMainWindow>
#include <QFutureWatcher>
#include "ann.h"//#include <QtConcurrent>
class MultiUnfold : public QMainWindow
{
	Q_OBJECT

public:
	MultiUnfold(QWidget *parent = 0);
	~MultiUnfold();

private:
	Ui::MultiUnfoldClass ui;
	void showVectorVals(QString label, t_vals &v); 
	void PreparePlots(int id /*,QString title*/);
	static void runNet(MultiUnfold* pt);
	void Test();

	QList<QCustomPlot*>* plots;
	ann * NNet;
	QFutureWatcher<void> *fwatcher;
private slots:
	void on_pbTrain_clicked();
	void on_pbExecute_clicked();
	void on_readytoPlot(int id);

signals:
	void readytoPlot(int id);
};

#endif // MULTIUNFOLD_H
