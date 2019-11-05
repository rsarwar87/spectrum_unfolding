#include "simple_psd.h"

void SimpleAnnPSD::getTopology(std::vector<unsigned> &topology)
{
    topology.clear();
    topology.push_back(115+3);
    topology.push_back(64);
    topology.push_back(32);
    topology.push_back(16);
    topology.push_back(32);
    topology.push_back(6);

    return;
}

SimpleAnnPSD::SimpleAnnPSD(const std::string filename)
{
    m_trainingDataFile.open(filename.c_str());
}

unsigned SimpleAnnPSD::getNextInputs(t_vals &inputVals)
{
  getEntry();
  inputVals.clear();
  
  for(int i =0; i < 115; i++) 
    inputVals.push_back(m_Line.at(i+8)/(1<<16));
  
  inputVals.push_back(m_Line.at(1)/(1<<16));
  inputVals.push_back(m_Line.at(2)/(1<<16));
  inputVals.push_back(m_Line.at(4)/(1<<16));
    qDebug() << "getEntry: size" << inputVals.size();
  return inputVals.size();
}

unsigned SimpleAnnPSD::getEntry()
{
    m_Line.clear();

    std::string line;
    getline(m_trainingDataFile, line);
    std::stringstream ss(line);

    while( ss.good() )
    {
      std::string substr;
      getline( ss, substr, ',' );
      m_Line.push_back( stod(substr) );
    }
    qDebug() << "getEntry: size" << m_Line.size();
    assert(m_Line.size() == 115+8);
    return m_Line.size();
}

unsigned SimpleAnnPSD::getTargetOutputs(t_vals &targetOutputVals)
{
    targetOutputVals.clear();

    targetOutputVals.push_back(m_Line.at(0));
    targetOutputVals.push_back(m_Line.at(0) == 1 ? 0 : 1);
    targetOutputVals.push_back(m_Line.at(3));
    targetOutputVals.push_back(m_Line.at(5));
    targetOutputVals.push_back(m_Line.at(6));
    targetOutputVals.push_back(m_Line.at(7));

    return targetOutputVals.size();
}
