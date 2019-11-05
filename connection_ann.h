#ifndef CONNECTION_H
#define CONNECTION_H
#pragma once
#include <vector>
#include <QDebug>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

struct Connection
{
    double weight;
    double deltaWeight;
};

class Neuron;
typedef std::vector<double> t_vals;
typedef std::vector<Connection> Connections;
typedef std::vector<Neuron> Layer;
#endif // CONNECTION_H
