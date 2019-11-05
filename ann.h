#ifndef ANN
#define ANN

#include <random>
#include "connection_ann.h"
#include "net.h"
#include "neuron.h"
#include "simple_ann.h"

class ann_simple {
 public:
  ann_simple(){;};
  void runNet(QString fname) {
    SimpleAnn trainData(fname.toStdString());
    rerror.clear();
    error.clear();
    exData.clear();
    // e.g., { 3, 2, 1 }
    std::vector<unsigned> topology;
    trainData.getTopology(topology);

    // Net myNet(topology);
    NNet = new Net(topology);
    t_vals inputVals, targetVals, resultVals;
    int trainingPass = 0, x = 0;

    while (!trainData.isEof()) {
      ++trainingPass;
      exData.push_back(x);
      x++;
      qDebug() << "Pass " << trainingPass;

      // Get new input data and feed it forward:
      if (trainData.getNextInputs(inputVals) != topology[0]) break;

      showVectorVals("Inputs:", inputVals);
      NNet->feedForward(inputVals);

      // Collect the net's actual output results:
      NNet->getResults(resultVals);
      showVectorVals("Outputs:", resultVals);

      // Train the net what the outputs should have been:
      trainData.getTargetOutputs(targetVals);
      showVectorVals("Targets:", targetVals);
      assert(targetVals.size() == topology.back());

      NNet->backProp(targetVals);

      // Report how well the training is working, average over recent samples:
      qDebug() << "Net current error: " << NNet->getError();
      error.push_back(NNet->getError());
      qDebug() << "Net recent average error: " << NNet->getRecentAverageError();
      rerror.push_back(NNet->getRecentAverageError());

      if (trainingPass > 5000 /*&& pt->NNet->getRecentAverageError() < 0.01*/) {
        qDebug() << "average error acceptable -> break";
        break;
      }
    }

    qDebug() << "Training Done";
    qDebug() << "Net recent average error: " << NNet->getRecentAverageError();
  }
  void Test() {
    for (int i = 0; i < 10; i++) rxData.push_back(i);

    sample = rxData;
    unfolded = rxData, NNunfolded = rxData;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<double> neu_multi[6];
    neu_multi[0] = {1286,  15189, 67133, 133887, 139461,
                    78378, 26272, 5091,  574,    34};
    neu_multi[1] = {1286,  15189, 67133, 133887, 139461,
                    78378, 26272, 5091,  574,    34};
    neu_multi[2] = {0, 160, 1584, 5489, 8633, 7707, 4144, 1312, 281, 53};
    neu_multi[3] = {0, 11, 107, 434, 829, 819, 572, 243, 81, 12};
    neu_multi[4] = {0, 0, 7, 28, 34, 45, 39, 22, 10, 1};
    neu_multi[5] = {0, 1, 0, 1, 3, 4, 2, 2, 3, 0};
    static std::discrete_distribution<> neu_enrgy_dis[6];
    for (int i = 0; i < 6; i++) {
      std::discrete_distribution<> _tmp(neu_multi[i].begin(),
                                        neu_multi[i].end());
      neu_enrgy_dis[i] = _tmp;
    }

    double detected[5] = {0, 21060, 16000, 1000, 1};
    std::vector<double> vdet(detected,
                             detected + sizeof detected / sizeof detected[0]);
    std::discrete_distribution<> _det(vdet.begin(), vdet.end());

    for (int i = 5000; i >= 0; --i) {
      double _sample = _det(gen) / 10.0;
      sample[(int)(_sample * 10)]++;

      double _unfolded = neu_enrgy_dis[(int)_sample](gen) / 10.0;
      unfolded[(int)(_unfolded * 10)]++;

      t_vals inputVals, resultVals;
      inputVals.push_back(_sample);
      NNet->feedForward(inputVals);
      NNet->getResults(resultVals);
      NNunfolded[(int)(resultVals[0] * 10)]++;
      showVectorVals("Inputs:", inputVals);
      showVectorVals("Outputs:", resultVals);
    }
  }
  void showVectorVals(QString label, t_vals &v) {
    QString debugString = label;
    debugString += " ";
    for (unsigned i = 0; i < v.size(); ++i)
      debugString += (QString::number(v[i]) + " ");

    qDebug() << debugString;
  }

  void PlotData(int id, QList<QCustomPlot*>* plots)
  {
	QPen pen;
	pen.setWidthF(1.2);
	if (id == 0)
	{
		
		plots->at(id)->clearGraphs();
		
		plots->at(id)->addGraph();
		plots->at(id)->graph()->setName("Detected");
		pen.setColor(QColor(255, 131, 0));
		plots->at(id)->graph()->setLineStyle(QCPGraph::lsStepRight);
		plots->at(id)->graph()->setPen(pen);
		plots->at(id)->graph()->setBrush(QColor(255, 131, 0, 150));
		plots->at(id)->graph()->setData(rxData, sample);

		plots->at(id)->addGraph();
		plots->at(id)->graph()->setName("PDF");
		pen.setColor(QColor(255, 0, 0));
		plots->at(id)->graph()->setLineStyle(QCPGraph::lsStepRight);
		plots->at(id)->graph()->setPen(pen);
		plots->at(id)->graph()->setBrush(QColor(255, 0, 0, 150));
		plots->at(id)->graph()->setData(rxData, unfolded);
		
		plots->at(id)->addGraph();
		plots->at(id)->graph()->setName("Neural Network");
		pen.setColor(QColor(0, 131, 0));
		plots->at(id)->graph()->setLineStyle(QCPGraph::lsStepRight);
		plots->at(id)->graph()->setPen(pen);
		plots->at(id)->graph()->setBrush(QColor(0, 131, 0, 150));
		plots->at(id)->graph()->setData(rxData, NNunfolded);

		
		plots->at(id)->xAxis->setLabel("Order");
		plots->at(id)->yAxis->setLabel("Count");
		plots->at(id)->yAxis->rescale();
		plots->at(id)->xAxis->rescale();
		plots->at(id)->replot();
	}
	else
	{
		plots->at(id)->clearGraphs();
		plots->at(id)->addGraph();

		plots->at(id)->graph()->setName("Current error");
		pen.setColor(QColor(255, 131, 0));
		plots->at(id)->graph()->setLineStyle(QCPGraph::lsStepRight);
		plots->at(id)->graph()->setPen(pen);
		plots->at(id)->graph()->setBrush(QColor(255, 131, 0, 150));
		plots->at(id)->graph()->setData(exData, error);

		plots->at(id)->addGraph();

		plots->at(id)->graph()->setName("Average error");
		pen.setColor(QColor(0, 131, 0));
		plots->at(id)->graph()->setLineStyle(QCPGraph::lsStepRight);
		plots->at(id)->graph()->setPen(pen);
		plots->at(id)->graph()->setBrush(QColor(0, 131, 0, 150));
		plots->at(id)->graph()->setData(exData, rerror);
		plots->at(id)->yAxis->rescale();
		plots->at(id)->xAxis->rescale();									   // make sure the axis rect and color scale synchronize their bottom and top margins (so they line u
		plots->at(id)->xAxis->setLabel("Pass");
		plots->at(id)->yAxis->setLabel("Error");
		plots->at(id)->replot();
	}
  
  
  }
  QVector<int> result;
  QVector<double> error, rerror;
  QVector<double> sample, unfolded, NNunfolded;
  QVector<double> rxData;
  QVector<double> exData;

  Net *NNet;
};
#endif

