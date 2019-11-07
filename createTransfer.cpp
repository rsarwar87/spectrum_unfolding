// createTransfer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <random>
#include <vector>
/*

neu_multi[0] = {1286, 15189, 67133, 133887, 139461, 78378, 26272, 5091, 574, 34};
neu_multi[1] = {1286, 15189, 67133, 133887, 139461, 78378, 26272, 5091, 574, 34};
neu_multi[2] = {   0,   160,  1584,   5489,   8633,  7707,  4144, 1312, 281, 53};
neu_multi[3] = {   0,    11,   107,    434,    829,   819,   572,  243,  81, 12};
neu_multi[4] = {   0,     0,     7,     28,     34,    45,    39,   22,  10,  1};
neu_multi[5] = {   0,     1,     0,      1,      3,     4,     2,    2,   3,  0};
*/
int main()
{
	std::vector<double> neu_multi[6];
	neu_multi[0] = { 1286, 15189, 67133, 133887, 139461, 78378, 26272, 5091, 574, 34 };
	neu_multi[1] = { 1286, 15189, 67133, 133887, 139461, 78378, 26272, 5091, 574, 34 };
	neu_multi[2] = { 0,   160,  1584,   5489,   8633,  7707,  4144, 1312, 281, 53 };
	neu_multi[3] = { 0,    11,   107,    434,    829,   819,   572,  243,  81, 12 };
	neu_multi[4] = { 0,     0,     7,     28,     34,    45,    39,   22,  10,  1 };
	neu_multi[5] = { 0,     1,     0,      1,      3,     4,     2,    2,   3,  0 };

	static std::discrete_distribution<> neu_enrgy_dis[6];
	std::random_device rd;
	std::mt19937 gen(rd());

	double detected[5] = { 0, 21060686,16000,1000, 1 };
	std::vector<double> vdet(detected, detected + sizeof detected / sizeof detected[0]);
	std::discrete_distribution<> _det(vdet.begin(), vdet.end());
	double detected_track[5] = { 0, 0, 0, 0, 0 };
	int th[5] = { 0, 29377, 3114, 187, 16 };
	int jmp[5] = { 0 };
	jmp[1] = detected[1] / detected[2];
	jmp[2] = detected[2] / detected[3];
	jmp[3] = detected[3] / detected[4];
	int step = 0;
	int idx = 1;
	int sum = 0;
	for (int a = 0; a<5; a++)
		sum += detected[a];

	for (int i = 0; i < 6; i++)
	{
		std::discrete_distribution<> _tmp(neu_multi[i].begin(), neu_multi[i].end());
		neu_enrgy_dis[i] = _tmp;
	}

	double detected_nn[10][4] = { { 0.4382,   0.3329,    0.2081,    0.0208 },
								 { 0.4382,    0.3029,    0.1081,    0.0018 } ,
								 { 0.4382,    0.0129,    0.0081,    0.0008 } ,
								 { 0.4382,    0.0229,    0.0181,    0.0018 } ,
								 { 0.4382,    0.0329,    0.0281,    0.0028 } ,
								 { 0.4382,    0.0729,    0.0581,    0.0088 } ,
								 { 0.4382,    0.0929,    0.0881,    0.0108 } ,
								 { 0.4382,    0.1329,    0.1281,    0.0128 } ,
								 { 0.4382,    0.2029,    0.1681,    0.0158 } ,
								 { 0.4382,    0.2529,    0.1881,    0.0188 } };
									// 1         1     1         1          1           1          10          10      100         1000    10000
	double detected_th[10][10] = { { 0.02751,	0.13250,	0.2437,	0.38651,	0.39843,	0.26772,	0.76220,	0.20894,	0.22283,	0.82757 },
	{ 0.9751,	0.2250,	0.1037,	0.1,	0.1,	0.1,	0.1,	0.1,	0.1,	0.1 } ,
	{ 0.8751,	0.3250,	0.1437,	0.101,	0.1,	0.1,	0.1,	0.1,	0.1,	0.1 } ,
	{ 0.7751,	0.4250,	0.2437,	0.15,	0.101,	0.1,	0.1,	0.1,	0.1,	0.1 } ,
	{ 0.5751,	0.5250,	0.3437,	0.21651,	0.19843,	0.11,	0.1,	0.1,	0.1,	0.1} ,
	{ 0.2751,	0.2250,	0.3037,	0.20651,	0.25843,	0.12772,	0.36220,	0.12894,	0.10283,	0.102757 } ,
	{ 0.1751,	0.1850,	0.2837,	0.25651,	0.29843,	0.16772,	0.49220,	0.14894,	0.14283,	0.73757 } ,
	{ 0.1051,	0.1650,	0.2637,	0.30651,	0.31843,	0.19772,	0.56220,	0.16894,	0.16283,	0.74757 } ,
	{ 0.06751,	0.1550,	0.2437,	0.35651,	0.35843,	0.21772,	0.66220,	0.18894,	0.18283,	0.76757 } ,
	{ 0.02751,	0.1350,	0.2237,	0.38651,	0.39843,	0.24772,	0.76220,	0.20894,	0.20283,	0.79757 } };



	std::cout << "topology: 4 8 12 16 10" << std::endl;
	for (int i = 5000; i >= 0; --i)
	{
		std::cout << "in: ";
		for (int a = 0; a < 4; a++)
			std::cout << detected_nn[step][a] << " ";
		std::cout << std::endl;
		std::cout << "out: ";
		for (int a = 0; a < 10; a++)
			std::cout << detected_th[step][a]<< " ";
		std::cout << std::endl;
		step++;
		if (step == 10) step = 0;
		/*
		
		std::cout << "in: ";
		for (int a = 0; a < 10; a++)
			std::cout << (a == idx ? " 1 " : " 0 " );
		std::cout << std::endl;
		std::cout << "out: ";
		int res = neu_enrgy_dis[idx](gen);
		for (int a = 0; a < 10; a++)
			std::cout << (a == res ? " 1 " : " 0 ");
		std::cout << std::endl;
		*/
		/*idx = _det(gen);*/
		
		/*std::cout << "in: " << idx/10.0 << std::endl;
		std::cout << "out: " << neu_enrgy_dis[idx](gen)/10.0 << std::endl;
		idx++;
		if (idx == 4) idx = 1;*/
		
		/*
		if (step % jmp[idx] == 0)
		{
			//std::cout << idx << " " << step << std::endl;
			step = 0;
			idx++;
			if (idx == 4) idx = 1;
		}*/
	}

    return 0;
}

