#ifndef NET_H
#define NET_H
#include "connection_ann.h"
#include "neuron.h"
#pragma once
class Net
{
public:
    Net(const std::vector<unsigned> &topology);
    void feedForward(const t_vals &inputVals);
    void backProp(const t_vals &targetVals);
    void getResults(t_vals &resultVals) const;

public: // error
    double getError(void) const { return m_error; }
    double getRecentAverageError(void) const { return m_recentAvgError; }

private:
    std::vector<Layer> m_layers; // m_layers[layerNum][neuronNum]

    // error
    double m_error;
    double m_recentAvgError;
    static double k_recentAvgSmoothingFactor;
    // /error
};

#endif // NET_H
