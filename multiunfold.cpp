#include "multiunfold.h"
#include <QtConcurrent/QtConcurrent>
#include <QFileDialog>

MultiUnfold::MultiUnfold(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pbExecute, SIGNAL(released()), this, SLOT(on_pbExecute_clicked()));
	connect(this, SIGNAL(readytoPlot(int)), this, SLOT(on_readytoPlot(int)));
	plots = new QList<QCustomPlot*>();
	plots->append(ui.qcpOutput);
	plots->append(ui.qcpError);
	ui.pbExecute->setEnabled(false);
	PreparePlots(0);
	PreparePlots(1);
}

MultiUnfold::~MultiUnfold()
{

}
void MultiUnfold::on_pbTrain_clicked()
{
	QString file1Name = QFileDialog::getOpenFileName(this,
		tr("Open Trainer File"), QDir::homePath(), tr("Txt Files (*.txt)"));
	if (file1Name != "") ui.pbExecute->setEnabled(true);

	ui.lineEdit->setText(file1Name);

	NNet = new ann_simple();
	NNet->runNet(file1Name);
  emit readytoPlot(1);
	//QtConcurrent::run(&MultiUnfold::runNet, this);
}
void MultiUnfold::on_pbExecute_clicked()
{
	NNet->Test();
	emit readytoPlot(0);
}

void MultiUnfold::on_readytoPlot(int id)
{
  NNet->PlotData(id, this->plots);
}

void MultiUnfold::PreparePlots(int id /*,QString title*/) 
{
	plots->at(id)->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	plots->at(id)->xAxis->setRange(0, 8);
	plots->at(id)->yAxis->setRange(0, 8);
	plots->at(id)->axisRect()->setupFullAxesBox();
	plots->at(id)->setContextMenuPolicy(Qt::CustomContextMenu);
	//plots->at(id)->plotLayout()->insertRow(0);
	//plots->at(id)->plotLayout()->addElement(0, 0, new QCPPlotTitle(plots->at(id), title));

	plots->at(id)->xAxis->setLabel("X");
	plots->at(id)->yAxis->setLabel("Y");
	plots->at(id)->legend->setVisible(true);
	//plots->at(id)->setOpenGl(true, plots->at(0)->getOGLcontext(), 16);
	QFont legendFont = font();
	legendFont.setPointSize(8);
	plots->at(id)->legend->setFont(legendFont);
	plots->at(id)->legend->setSelectedFont(legendFont);
	plots->at(id)->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items

	plots->at(id)->replot();

}
