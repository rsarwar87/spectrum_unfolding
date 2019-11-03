#ifndef TRAININGDATA_H
#define TRAININGDATA_H
#include "connection.h"

class Neuron;
typedef std::vector<double> t_vals;
typedef std::vector<Connection> Connections;
typedef std::vector<Neuron> Layer;
class TrainingData
{
public:
    TrainingData(const std::string filename);
    bool isEof(void) { return m_trainingDataFile.eof(); }
    void getTopology(std::vector<unsigned> &topology);

    // Returns the number of input values read from the file:
    unsigned getNextInputs(t_vals &inputVals);
    unsigned getTargetOutputs(t_vals &targetOutputVals);

private:
    std::ifstream m_trainingDataFile;
};
#endif // TRAININGDATA_H
