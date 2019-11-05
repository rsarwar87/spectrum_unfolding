#ifndef MNIST_HPP
#define MNIST_HPP

#include <armadillo>
#include <string>
#include <vector>
#include <cassert>

class MNISTData
{
 public:
  MNISTData(std::string dataDir, double splitRatio = 0.9)
  {
    assert(splitRatio <= 1 && splitRatio >= 0);
    this->dataDir = dataDir;
    trainFile = dataDir + "/train.csv";

    arma::mat trainDataRaw;

    trainDataRaw.load(trainFile, arma::csv_ascii);

    int numExamples = trainDataRaw.n_rows;

    std::vector<arma::cube> trainDataAll;
    std::vector<arma::vec> trainLabelsAll;
    for (size_t idx=0; idx<trainDataRaw.n_rows; idx++)
    {
      arma::cube img(116+3, 1, 1, arma::fill::zeros);
      img(0+116, 0, 0) = (int)trainDataRaw.row(idx)(4)/20; 
      img(1+116, 0, 0) = (int)trainDataRaw.row(idx)(1)/90; 
      img(2+116, 0, 0) = (int)trainDataRaw.row(idx)(2); 
      img.slice(0).row(r) = trainDataRaw.row(idx).subvec(28*r+1, 28*r+28);
      img.slice(0) = img.slice(0)/(1<16);
      trainDataAll.push_back(img);

      arma::vec labelvec(7, arma::fill::zeros);
      labelvec(0) += (int)trainDataRaw.row(idx)(0);
      labelvec(1) += trainDataRaw.row(idx)(0) == 0 ? 1 : 0;
      labelvec(2) += (int)(trainDataRaw.row(idx)(3)*10000);
      labelvec(3) += (int)trainDataRaw.row(idx)(5);
      labelvec(4) += (int)trainDataRaw.row(idx)(6);
      labelvec(5) += (int)trainDataRaw.row(idx)(7);
      trainLabelsAll.push_back(labelvec);
    }

    // Split trainDataAll and trainLabelsAll into train and validation parts.
    trainData = std::vector<arma::cube>(trainDataAll.begin(),
                                        trainDataAll.begin() + numExamples*splitRatio);
    trainLabels = std::vector<arma::vec>(trainLabelsAll.begin(),
                                         trainLabelsAll.begin() + numExamples*splitRatio);

    validationData = std::vector<arma::cube>(trainDataAll.begin() + numExamples*splitRatio,
                                             trainDataAll.end());
    validationLabels = std::vector<arma::vec>(trainLabelsAll.begin() + numExamples*splitRatio,
                                              trainLabelsAll.end());

  }

  std::vector<arma::cube> getTrainData() { return trainData; }

  std::vector<arma::cube> getValidationData() { return validationData; }

  std::vector<arma::vec> getTrainLabels() { return trainLabels; }

  std::vector<arma::vec> getValidationLabels() { return validationLabels; }

 private:
  std::string dataDir;
  std::string trainFile;

  std::vector<arma::cube> trainData;
  std::vector<arma::cube> validationData;

  std::vector<arma::vec> trainLabels;
  std::vector<arma::vec> validationLabels;
};

#endif
