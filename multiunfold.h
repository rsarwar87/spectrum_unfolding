#ifndef MULTIUNFOLD_H
#define MULTIUNFOLD_H

#include <QtWidgets/QMainWindow>
#include "ui_multiunfold.h"
#include <QMainWindow>
#include <QFutureWatcher>
//#include <QtConcurrent>
#include "connection.h"
#include "neuron.h"
#include <random>
#include "net.h"
#include "trainingdata.h"

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

	QVector<int> result;
	QVector<double> error, rerror;
	QVector<double> sample, unfolded, NNunfolded;
	QVector<double> rxData;
	QVector<double> exData;
	QList<QCustomPlot*>* plots;
	Net * NNet;
	QFutureWatcher<void> *fwatcher;
private slots:
	void on_pbTrain_clicked();
	void on_pbExecute_clicked();
	void on_readytoPlot(int id);

signals:
	void readytoPlot(int id);
};

#endif // MULTIUNFOLD_H
