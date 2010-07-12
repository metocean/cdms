/* Test cdunif vargets */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "cdunif.h"

#define T21_NLON 64
#define T21_NLAT 32
static double t21Lats[T21_NLAT] = {
 0.85760587120445E+02, 0.80268779072251E+02, 0.74744540368636E+02, 0.69212976169371E+02,
 0.63678635561097E+02, 0.58142954049203E+02, 0.52606526034345E+02, 0.47069642059688E+02,
 0.41532461246656E+02, 0.35995078411272E+02, 0.30457553961152E+02, 0.24919928629948E+02,
 0.19382231346434E+02, 0.13844483734385E+02, 0.83067028565188E+01, 0.27689030077360E+01,
-0.27689030077360E+01,-0.83067028565188E+01,-0.13844483734385E+02,-0.19382231346434E+02,
-0.24919928629948E+02,-0.30457553961152E+02,-0.35995078411272E+02,-0.41532461246656E+02,
-0.47069642059688E+02,-0.52606526034345E+02,-0.58142954049203E+02,-0.63678635561097E+02,
-0.69212976169371E+02,-0.74744540368636E+02,-0.80268779072251E+02,-0.85760587120445E+02
};

static float prc[T21_NLON * T21_NLAT] = {
  0.8563904,  0.7936714,  0.7127936,   0.631571,  0.5231538,  0.4113186
,  0.3023199,  0.2124669,  0.1443063, 0.09259053, 0.07897226, 0.07060092
, 0.06606676, 0.06446455, 0.06539725, 0.06551341, 0.06970616, 0.07992123
, 0.09381074,  0.1077938,  0.1267541,  0.1593308,  0.1986484,   0.258161
,  0.3530961,  0.4704561,  0.5995206,  0.7227747,   0.838576,  0.9541376
,   1.107713,   1.287468,   1.399231,   1.449168,   1.420279,   1.349518
,   1.298045,   1.257933,   1.219473,   1.189115,   1.161147,   1.150998
,   1.155463,   1.156072,   1.160271,   1.201047,   1.302856,   1.421572
,   1.567779,   1.734776,   1.895845,   2.041617,   2.125327,   2.146708
,   2.100109,   1.987495,   1.842663,   1.662379,   1.519688,   1.414898
,   1.310517,   1.202442,   1.057383,  0.9342816,  0.7409869,  0.4776548
,  0.3829142,  0.6096529,   1.000898,   1.404976,   1.584631,   1.539231
,   1.314044,   1.069156,  0.8818675,  0.7115594,  0.4961515,  0.3048035
,  0.2277647,  0.2021576,  0.1475389, 0.08469184,  0.1075981,  0.1400966
,  0.2355068,  0.5613635,  0.9071403,   1.174631,   1.474435,   1.809477
,   2.097666,   2.231107,   2.407282,   2.540909,     2.1228,   1.715146
,   1.428584,   1.313911,   1.198556,   1.011005,  0.8528511,  0.6870969
,  0.7265099,  0.7800289,  0.7763287,   0.708928,  0.5399349,   0.350299
,  0.1783725,  0.1873179,  0.3822566,  0.5346758,  0.6479212,  0.9651603
,   1.696487,   2.527302,   3.056943,   3.174169,   3.005059,   2.629615
,   2.183614,   1.892733,    1.92823,   1.961597,   1.881851,   1.780333
,   1.578562,   1.205151,  0.7068663,  0.4638551,   0.328357,  0.3752164
,  0.7564619,   1.194034,   1.479325,   1.449965,   1.357498,   1.594674
,    2.54641,    3.40868,   3.467705,   2.601883,   2.034166,   1.789792
,   1.431254,   1.344394,  0.7291726,  0.4283075,  0.2160954,  0.1195526
,  0.1631859,  0.4103299,  0.6166655,  0.6841753,  0.5394782,   0.452257
,  0.6822742,  0.9780843,    1.16013,  0.8549939,  0.3822681,  0.3090441
,  0.2590497,   0.205882,  0.2683906,  0.2798801,  0.2567299,  0.1852126
,  0.1899318,  0.2845543,  0.3425297,  0.4128693,  0.4138181,  0.5342132
,  0.5562913,  0.5935991,   0.681914,   1.112847,   1.536437,   1.863198
,   1.839512,   1.675363,   1.372417,  0.7800296,  0.4372846,  0.6293463
,   1.304458,   1.916912,   2.062509,    1.75868,   1.102557,  0.8586568
,   0.277178,  0.1619728,  0.3784101,  0.6180729,  0.6165524,  0.3361076
,  0.2535183, 0.06963684, 0.01995922, 0.02058361,  0.2089386,  0.3790036
,   0.338687,  0.7206908,   1.357858,   1.413148,   1.126205,  0.9857417
,   1.211074,   1.182917,   1.050153,  0.9420023,  0.9166089,  0.8567184
,  0.4751344,  0.1232678,  0.1676254,  0.2398475,  0.5029635,  0.6273636
,  0.6869096,   1.911784,   2.811316,   2.673053,   2.185745,   1.629841
,   1.708292,   2.016442,   2.396557,   2.548712,   2.134934,   1.265613
,  0.8931614,   1.445459,   2.120013,    2.33393,   2.146836,   1.617375
,   1.383504,   1.137822,  0.7948006,   1.250901,    2.28018,   2.697824
,   2.546224,    2.85591,    2.12369,   1.127453,   1.447728,   2.550302
,   3.344996,   3.566851,   2.463183,  0.7805825,   1.560012,   1.812692
,    2.26822,    3.11098,   3.948129,   3.539428,   3.123109,   2.712625
,   1.781336,   1.180167,   1.473599,   2.467664,   1.944098,    1.74393
,   2.124059,   2.079768,   1.641671,   1.090431,  0.7822323,   1.396379
,   1.689139,   1.188093,   1.003965,    1.06517,   2.169862,   4.407727
,   5.202027,   4.207109,   2.870384,     2.1606,   1.785633,   1.486362
,   1.974244,   2.765962,   2.448425,   1.976442,   2.061999,   2.774523
,   2.434279,     1.5208,  0.8348658,   1.159195,   2.449351,   3.284126
,   3.944639,   2.381106,   1.048369,  0.4557485,  0.8713456,  0.9033113
,   1.014788,   2.099462,   2.776054,   3.014024,   2.908769,    2.35351
,   2.930558,   3.407807,   3.412775,   2.895074,   2.819666,   3.101429
,   2.102233,   1.211754,  0.9573311,   1.452337,   1.913512,   0.807865
,  0.8909149,   2.473094,   2.381332,   1.703658,   2.654638,   4.418713
,   5.216434,   3.476053,   1.359666,  0.8528124,   1.267366,   1.288562
,   1.615577,   1.888392,   1.778602,   2.682088,   1.746946,   1.186162
,    1.34492,   2.278841,   2.980384,   4.339859,   4.848794,   2.845589
,   1.649706,  0.9426612,   1.235675,   3.211525,   3.224801,  0.9756569
,   1.307171,   1.270354,   1.350183,  0.7075794,  0.5073647,  0.7659038
,  0.2599495,  0.2617489,  0.5997518,   1.242624,   3.557062,   2.678151
,   1.147376,  0.6301597,  0.8787138,   1.189768,   1.003764,  0.8714535
,    2.96081,   3.962402,   4.037309,   3.232558,   3.301424,   2.484645
,   1.699787,   1.216474,   1.099728,   1.519283,   1.159527,  0.9584119
,   2.293326,   1.719153,   2.000575,  0.8843937,  0.4864223,  0.4777277
,   0.724518,  0.9879856,   1.466861,  0.9712523,   0.103742,  0.1677712
,  0.3071983,  0.3061435,  0.7210278,  0.9702737,  0.8457521,  0.8133949
,   1.311016,   2.137026,   1.921029,   1.894951,   1.697909,   1.235079
,  0.9134585,  0.6323555,   2.067157,   1.932262,   1.100386,  0.6088951
,  0.2822782,  0.6373824,   2.163728,   1.902368,   1.668205,   3.456297
,   1.824774,  0.6349114,  0.8756528,   1.659931,   1.037393,  0.3033769
,  0.8309734,    1.37009,   1.842874,    2.97653,   2.757602,   2.518487
,   2.307099,   2.439526,   3.469195,   4.324939,    4.66083,   5.723029
,   5.892862,   4.664573,   3.111005,   1.037699,  0.3877273,  0.4650322
,   1.569791,   1.965137,   1.004874,  0.6785927,   3.314801,   4.199851
,   5.269804,   5.410229,   6.008799,   3.454717,    2.59058,   2.024567
,   0.947772, 1.041603e-05,          0,          0, 0.01612483,  0.5461767
,   1.433934,   2.029272,   1.468316,   1.510572,  0.6766274,  0.4418948
,   1.164855,   4.402896,   6.267133,   2.264652,  0.8937604,   1.823823
,   2.616223,   3.883428,   1.887654,   1.108549,   1.046672,   2.557233
,   2.358291,   2.265266,   2.781653,   3.641452,    2.57202,   1.151301
,  0.4988526,  0.7486402,   1.042382,  0.1036022,  0.7229782,   1.288225
,   1.880656,   4.222029,   8.461365,   6.254194,   4.539495,   3.228811
,   3.429171,   4.890299,   5.909373,    5.24261,   3.516797,   2.104177
,   1.781955,     1.7862,   1.827851,    2.30065,   2.809882,   1.740881
,   2.559177,   1.621241,   0.899588,  0.4380245,  0.5101938,   1.532815
,   2.940957,   2.655892,   2.232311,    2.61107,   2.428503,  0.3320274
, 0.09470077, 0.07745422,  0.2161832,   1.247504,   2.811385,   1.597533
,   2.650276,   3.620146,   2.672581,  0.6426914,    1.18627,   3.157145
,   5.319588,   5.016347,   1.525941,   2.760185,   4.361692,   6.255373
,   3.385724,   2.396883,   2.635899,   2.884617,   1.597783,   1.640388
,   2.042253,   2.731664,   1.135269,  0.4786895,   0.549167,  0.1436755
, 0.03249484, 6.889279e-05, 0.07204033,   0.145444,   0.383192,  0.7547231
,   3.283019,   4.640518,   3.994563,   2.154696,   2.023184,   5.403245
,   5.027671,   3.354652,   1.388545,   1.367797,   3.837546,   4.014401
,   2.254375,   0.456443,  0.1576548,  0.3998785,  0.3812417,  0.6863505
,          0,          0,          0, 0.003849884,          0, 0.02007223
,          0,  0.1622027,  0.3574052, 0.03177318,   0.202937, 0.02128353
,  0.1926776,   0.228518,   1.239948,   0.568937,  0.3306097,   1.179331
,   9.347656,   13.34418,   7.302609,   2.712443,  0.4381291,   2.681411
,    1.52353,   1.842557,   2.884473,   3.045741,   2.193339,   2.735153
,   1.942583,   0.925092,   0.566772,   1.437668,   2.929991,   2.165814
,  0.4238165,  0.3388762,  0.3572982,  0.4840434, 0.02884819,  0.0010971
, 0.01668809,          0,  0.4193418, 0.09603978,   1.531534,   2.568167
,   1.895791,   4.573856,   7.972237,   7.494964,   3.489614,   4.870102
,    2.23556,   3.173678,    3.13398,   3.371717,    1.10897, 0.004772226
,  0.1541006,  0.2021848,  0.1631927, 2.987287e-05,          0,          0
,          0,          0, 0.0001008375,          0,          0,          0
, 0.0003279856,  0.2451339, 0.003093788,          0,          0,  0.1759429
,    1.19739,   1.321917,    1.06811,   3.794717,   13.85799,   20.32387
,   9.299255,   4.554922,   5.070869,    6.95119,   4.568362,   3.036982
,   5.695438,   3.630255,   1.100713,  0.7882351,   1.824107,    3.61251
,   1.971805,   1.772787,   3.260258,   3.554478,    1.35953,   1.450617
,  0.6775318, 0.05649507, 0.0007100255, 0.04557097, 0.04083596,          0
,          0, 0.08842117,   1.748311,   1.049931,   1.477849,   5.204572
,    8.41132,   3.548912,   2.551649,    2.10621,   3.860942,   3.474474
,   2.840356,   2.015985, 0.04572697, 0.01384088,   0.237613,  0.4487457
, 0.03320916,          0,          0,          0,          0,          0
,          0,          0,          0,          0,          0,          0
,          0,          0,          0, 0.01999902,  0.6763931,   12.03998
,   21.44466,   22.46257,   12.75094,   16.10292,   15.31725,   7.701861
,   4.096122,   5.237453,   6.522001,   3.128196,   4.704695,   7.464992
,    6.01734,   4.609923,   3.147591,   3.194512,    3.73203,   2.008747
,   1.603809,   2.981553,  0.6472301,  0.2370864, 0.02831372, 0.002281523
, 0.000953613, 0.003949884,  0.1898116,  0.3051765,          0,   0.600395
,  0.7384664,   5.453023,   1.391065,   2.337286,   8.771038,    5.52563
,   5.837051,   7.638685,   9.970174,   3.417936,   2.759256,  0.1490176
, 0.003113332,          0, 0.06748433,  0.1506708,          0,          0
,          0,          0, 0.01340059, 0.006686213,          0,          0
,          0, 1.75029e-05,          0,          0,  0.1992486,   1.177476
,   3.454997,   5.137487,   4.878765,   2.669468,   2.336852,     9.7665
,   3.670482,   3.681511,   6.451616,   12.86275,   15.16592,   10.35542
,   7.800099,   5.767576,   5.706991,   6.554284,   4.573954,   2.707414
,   2.839813,     6.5179,   9.833851,    4.90709,   1.925677,   4.101183
,   2.595373,   1.205933, 0.03826579, 0.04081318, 0.0009619281, 5.401305e-06
, 0.02573439, 0.03556519, 0.01387082,    1.42344,   8.770159,   7.846681
,   1.976844,   5.756784,   13.01527,   5.455579,   4.836015,   5.905333
,   6.738204,   3.015664,   1.552877,  0.4944729,          0,          0
, 0.005200332, 0.000340014,          0, 0.02053763,  0.7142982,  0.3411489
,  0.6637146, 0.008263372,          0,          0,          0,          0
, 0.00251908,   2.905169,   1.428139,   4.433805,   24.38005,   36.15954
,   10.69884,   3.155289,   1.533113,   10.32397,   3.291682,  0.3461694
,   2.691403,   14.14442,   15.45395,   7.435484,   5.203081,    4.35575
,   3.751649,   2.819349,   5.994077,   6.182199,   4.022205,    3.26233
,   7.372073,    10.5595,   5.460784,   5.965178,   4.850563,   1.732274
,  0.3941984,  0.8058376,   0.100043, 0.03657791, 0.002650691, 0.01590367
, 0.009628329,   2.031815,   18.51284,   21.51551,   14.95322,   13.22503
,   11.13959,   4.606083,   2.135955,   1.852412,   1.934019,   1.750331
,    1.51304, 0.05690903, 0.0006620702, 2.87338e-05, 0.01704426,          0
,  0.1590086,  0.6100453,   1.709025,   3.483448,   8.335643,   3.031449
,   1.355952,  0.4406561,   3.610959,   1.916871,  0.1669731, 0.07445505
,   0.143415,    2.66849,   8.106817,   22.97988,   30.82874,   17.64427
,   13.05053,    18.7517,   13.94138,   5.754819,   3.102543,   6.898929
,   11.76011,   9.269172,   2.895259,   1.196976,   2.160203,  0.8096759
,   1.593737,   3.443365,   1.693509,   1.069833,   2.229137,   4.784509
,   4.441173,   3.957589,   4.108034,   3.374636,   3.292405,   3.743027
,    3.20074,   3.291942,   3.918624,   1.186247,   1.090652,  0.5895771
,    2.88445,   4.779158,   10.06017,   16.70507,   11.53996,   4.847741
,   3.179673,   2.706374,   5.577259,   5.592755,    5.15535,   3.099751
,   1.531148,   1.196737,  0.2733047,   1.827577,   1.768524,   2.627611
,  0.2679082,   3.497045,    4.63968,   4.005269,   2.679095,   6.701986
,   6.204921,  0.4274828, 0.06860496,  0.6807296,   2.047746,   3.868021
,   6.013333,   4.723363,   4.114935,   4.149282,   7.503441,   10.87481
,    10.3708,   3.706156,   3.759473,   4.513085,   12.77554,   10.10354
,   2.688227,  0.9277484,   1.113741,  0.5488826,  0.8917305,  0.9447361
,  0.4346932, 0.07521432,  0.4554073,   2.144227,   5.029277,   6.468921
,   7.811219,   5.948898,   3.321389,   2.442482,       0.88,  0.7417024
,   1.447681,   2.206885,   3.081909,   1.702537,   1.284494,   1.083708
,  0.6348517,    1.25695,  0.8519803,  0.5145704,   4.020522,   11.73751
,   11.56319,   8.965738,   5.743159,   9.411779,   8.094976,   4.678654
,   4.555302,   4.148488,    2.37114,  0.6154048, 0.000357989,  0.2069221
,  0.3042374,  0.6085371,  0.3993533,   1.474762,   1.463513,  0.9276875
,   1.438148,  0.7067071,   1.747969,   2.599594,   1.665108,  0.9410419
,   1.607184,   3.739146,   4.329715,    4.93881,   4.095587,   1.144377
,  0.8545574,   3.151983,   3.110022,   2.347161,   4.548945,   7.394592
,   4.587963,   3.977611,   2.501601,   5.641752,   7.326524,   8.232792
,   7.683302,   9.854877,   13.42179,   14.25237,   9.425065,   9.353016
,   6.544571,   4.869545,   1.770624,   1.612425,  0.9524246,  0.7474949
,  0.6860092,   2.235087,   1.991555,  0.3951834, 0.06010544,  0.1789087
,  0.2998029, 0.01508066,   0.516467,   5.028308,    5.85154,    4.66507
,   5.547554,   11.59958,   11.42128,   6.147988,   2.565712,   1.677547
,  0.8209803,  0.1805749,   0.025996, 0.001014314, 0.02051153,  0.3706087
, 0.01562674,          0,  0.1662314,   3.217664,   2.825461,  0.9830306
,    1.19785,   1.703569,   0.792223,  0.8982782,   4.205267,   4.465936
,   2.787682,   3.807921,   3.940128,  0.5857131,  0.8200427,  0.4847571
, 0.004189985, 0.07718286,   4.267972,   7.919616,   7.224811,   10.28063
,   12.33889,   14.81943,    14.7509,    11.6937,   15.49617,   15.45105
,     12.403,   6.259061,   2.580939,    2.77621,   6.880848,   7.146831
,   5.026967,   5.156468,   2.818375,  0.7238541,  0.2792358,  0.6167666
,  0.6495969,  0.0488167,  0.0422289,  0.1410804,  0.3124058, 0.07820664
, 0.04805791,  0.6949568,    1.29415,   1.702453,  0.9013764,  0.8671159
,   7.332981,   2.667545,  0.1553707,  0.2786591,  0.2478482,  0.3171497
, 0.006308242, 0.02313568, 5.385637e-05, 0.06542233, 1.535209e-07,  0.0125583
,  0.2075907,  0.2395206,   1.188852,   1.347314,   2.286899,   2.554357
,   1.979397,   2.179868,  0.5801619,  0.4772559,  0.4751332,   2.979094
,   1.355402,  0.4055802,  0.0416084,  0.1663765, 0.02911078,  0.0036268
, 0.0006617396,  0.3578371,  0.9327179,   5.084054,   6.262361,    7.30014
,   3.711818,   2.394501,   7.483013,   7.995256,   3.751679,   1.986484
,   2.037982,   3.765655,   5.319465,   6.263827,   4.801234,   2.891819
,   2.072773,  0.9132731,  0.7190177,  0.4376005,  0.4139989, 0.07211361
, 0.01796916, 0.01144873, 0.03257537,  0.1103235,  0.3023335,  0.3579857
,  0.1560768,   1.358591,    2.34547,   1.318547,   1.707199,   1.384453
,  0.7590824,   0.380704,  0.1079857, 0.05217846, 0.03553435, 0.02173169
, 0.05795709,  0.4260653,  0.4240022, 9.334164e-06, 0.02793832, 0.09586147
, 0.08016342,   2.192403,   2.049694,   0.746505,   1.122161,   1.311817
,  0.8015773,   1.765391,   1.411859,  0.4954766,  0.1285997,  0.2032409
,  0.2110443,  0.9325629,    1.00212,  0.8454933, 0.04718875, 0.009846914
,  0.9957131,    1.36628,  0.5162191,  0.2606493, 0.08442128, 0.09168167
,  0.6127737,    1.61065,  0.5346899,  0.7999763,  0.8235918,   4.764857
,   5.416192,   6.071077,   5.466557,   2.794093,  0.6614238,   1.538799
,   1.920297,   3.806912,    0.89787,  0.1478605, 0.06900271, 0.004231929
, 0.03842563,  0.1202298,   0.191936,  0.3890058,  0.2120412,  0.6983212
,   2.940091,    7.18789,   2.082186,  0.7547615,  0.6881326,  0.6675262
,  0.1119202, 0.04321135,  0.2189574,  0.1847121,  0.1532642,  0.2694753
, 0.01866571,  0.1808957,  0.1149198,  0.3818565,  0.4664061,  0.6807045
,   1.077451,  0.2453119,   0.327392,   1.095234,  0.8747863,   2.013451
,   1.477245,  0.8317013,  0.2405824,  0.1018068,  0.1711473, 0.06942806
,  0.9592469,   1.128123,  0.5608637, 0.01011231,   1.211512,   1.170277
,  0.1329988, 0.03370437,  0.1126366,  0.3305163,  0.9323062,  0.5755862
,    1.49953,   1.243419,    1.24807,   2.258139,    2.71431,   5.762089
,   3.400405,   1.997806,  0.8299111,  0.5240501,   2.777053,   5.083369
,    1.43231,   1.467768,  0.1513482, 0.03153023,  0.0327866,  0.2794552
,  0.1984219,  0.5824112,  0.1165741,  0.2942731,   2.350727,   3.888751
,   2.044129,    2.78208,   1.642291,   1.383763,  0.9912808,  0.5086154
,  0.3838589,  0.1580751,  0.2738309,  0.5409133,  0.4770607,  0.4953798
,   2.353299,   1.321416,    1.28263,   1.941664,   2.017836,   1.072225
,  0.5425875,  0.7011007,   1.341887,   2.692019,   4.287401,   1.962689
,   1.911862,   2.827354,   2.818905,  0.4420546,   1.112769,  0.2483015
,  0.8004889,   1.224167,   1.194026,  0.7537656,   1.413019,   1.455154
,   3.382456,   3.759174,   2.102281,   2.646142,   3.242384,   3.434486
,   6.284684,   4.644256,   3.964336,   3.707449,   3.542472,   5.726332
,   2.766329,   2.497262,   3.452056,   3.254924,   3.347969,   2.742179
,   1.690322,   0.478446,  0.2205413,  0.2664121,  0.1724754,  0.2405224
,  0.2429451,  0.2774445,   1.658474,   3.639521,   3.469239,   4.250684
,   3.397828,   1.988607,   3.241271,   2.027517,   1.531316,   1.217539
,  0.3996199,   1.366715,   2.709727,   3.972125,   3.303114,   2.814642
,   4.185004,   3.943707,   2.725291,   2.159653,   2.956283,    2.88466
,   2.792698,   2.616271,   1.699805,   1.889062,   3.536864,   3.839872
,   6.038617,   3.641719,   1.752691,   1.412447,   2.665916,   2.405737
,   2.622457,   4.214931,   4.936322,   4.202664,   5.294493,   4.970727
,   4.360699,   4.848382,   5.333756,   4.318677,   4.148815,   5.261274
,   4.960905,   3.971807,   4.136208,   6.544993,    7.57476,   7.005852
,   5.208605,   4.627835,   4.984475,   4.480436,   4.062294,   2.826113
,   2.610822,   1.946971,  0.4516033, 0.05758933, 0.04019751,  0.5188487
,   1.756524,   2.566639,   3.390538,   4.750285,   4.524936,   3.036098
,   3.865319,   3.559104,   2.504566,     2.4066,   2.791868,   1.925124
,   2.558345,   2.475492,   1.634486,   1.632195,   1.655642,   2.018131
,   3.054887,   2.929592,   3.059099,   3.592845,   3.298251,   2.317054
,   2.001648,    2.10579,   1.695207,   2.413323,   3.565058,   3.839374
,   2.738193,   3.208019,   4.061588,   3.905378,   3.576077,   3.645511
,   3.509019,   4.872159,   4.114971,   2.291077,   3.090311,   4.711332
,   4.678432,   3.859265,   3.277295,    4.41374,   4.823455,   3.782878
,   4.351753,   5.897187,   6.196798,   4.768291,   4.165032,   6.120808
,   8.215081,   5.731988,   6.130829,   8.525712,    7.32065,   3.660557
,    1.61097,   1.442156,  0.8936536,   1.172156,   3.649802,   4.111853
,   3.155015,   3.251283,   3.842654,   3.611145,   3.283593,   3.433712
,   3.265892,   4.057483,    3.31305,   2.009708,    2.37053,   3.222928
,   4.241981,    5.00187,   5.190859,   4.169716,   3.975029,   5.543439
,   5.709242,   4.102434,   2.521439,   2.830953,   4.727093,   4.758574
,   2.785709,   2.840879,   4.681803,   5.215784,   2.360281,   1.881617
,   2.143751,   2.175379,   2.554158,   2.804088,   2.462636,   3.670292
,   4.304243,   3.131989,   3.274346,   3.856739,   3.959253,   2.642619
,   2.338413,   2.570572,   2.034206,    1.97034,   3.593895,   4.719689
,   3.500707,   3.125228,   2.574058,   4.029297,   5.031546,   4.162359
,   4.107594,   5.862117,   10.06121,   9.152777,   4.650954,   1.631308
,   1.307904,   3.061886,   4.574201,   3.264392,   2.273014,   2.741136
,   3.685542,    4.18456,   3.581854,   2.553369,   3.389264,   4.024595
,   3.330236,   2.154268,   2.033098,    2.73432,    3.01449,   2.199604
,   2.022118,   2.051545,   2.359534,   2.504015,   3.269128,   3.780437
,   2.811358,   2.596564,    2.73363,   2.900009,   2.658758,    2.44577
,   2.906026,   2.010067,  0.8816854,   0.807882,   1.122928,   1.744614
,   3.022598,   2.835941,   2.137828,   1.130734,   2.682436,   4.291197
,   2.972957,   2.953818,   2.643426,   2.970062,   3.289392,   2.434006
,   1.360783,   1.412062,   1.970987,   2.330761,     2.0258,   1.844422
,    2.74516,   2.594746,   3.702796,   4.696652,   2.454106,   3.357426
,   4.459236,   4.876521,   3.302668,   1.977444,   2.838234,   4.543314
,   4.689437,   2.764367,   2.451161,   3.015648,   4.168719,   3.406675
,   2.119816,    2.49614,   1.123057,   0.383461,   1.134539,   1.879041
,   1.546843,   1.128327,   1.343557,   1.081847,   1.150524,   1.132955
,  0.6454138,  0.9106733,  0.8932402,   1.836038,    2.15124,   2.020479
,   1.897741,   1.428146,   1.638082,   2.691137,   1.630372,  0.6949543
,  0.5565338,  0.7910343,   1.059287,   1.541412,   1.982135,   1.358112
,  0.6590133,  0.7530683,  0.7294793,   1.802659,    2.18197,   2.207355
,    1.98493,   2.201724,   2.736146,   3.348189,   2.950213,   2.186826
,   1.567214,    1.44886,   2.102432,   2.023762,   1.835478,   1.762795
,   1.831835,   2.330683,   2.434613,   2.631894,   2.665572,   2.581769
,   2.594238,    2.37409,   2.785935,   2.605894,   2.318417,   1.998906
,   2.047536,   1.884789,   2.193369,   2.370189,   1.704438,   1.699552
,   2.974772,   2.061015,   1.465874,  0.9881855,   1.507149,   1.615468
,   1.759718,   1.611169,   1.496211,   1.765995,   1.968453,   1.518463
,   2.425274,   3.854088,   4.361781,   4.747531,   5.048534,   5.478229
,   4.642673,   3.715203,   3.346112,   3.129627,   2.946625,   2.246717
,   1.754885,   1.109961,   1.555459,   2.496845,   2.720408,   2.660662
,   3.012156,   3.021453,   3.079469,   1.975771,   1.896819,   2.083383
,   1.785022,   1.862731,   1.961604,    1.80116,   1.401661,   1.089218
,  0.7210416,  0.8221014,   1.113456,   1.455587,   1.649498,   1.764973
,   1.954044,   1.563222,    1.63035,   2.043869,   2.266187,    2.54517
,   2.701967,    2.41665,   1.882566,   1.165022,   1.529598,   3.064454
,   3.134208,   2.921714,   2.376897,   2.616404,   2.678745,   3.399698
,   3.667114,   3.384015,   2.966863,     2.9669,   2.802567,   2.194404
,   1.170617,  0.9014024,   1.522492,   1.991275,    2.43243,    3.05802
,   3.735843,   4.478105,   4.561694,   4.083956,   3.297343,   2.749917
,   2.019921,   1.120608,  0.8871442,   1.646319,   2.153104,   1.872643
,   1.333728,   1.333243,    1.66433,   2.231048,   2.437133,   2.298224
,   2.068717,    1.70094,   1.525833,   1.595578,   1.893759,   2.358227
,   2.396282,   2.040622,   1.924505,   2.343196,   2.430444,   1.949934
,   1.929948,   2.063737,   2.365451,   2.904767,   2.672731,   2.186931
,   1.867759,   1.459763,   1.279757,   1.652884,   2.203276,   2.164457
,    1.97441,   1.801954,   1.642786,   2.102099,   2.290593,    2.20895
,   2.005249,   2.068121,  0.3444327,  0.7478516,   1.136108,   1.534591
,   1.815616,   1.919301,   1.999016,    1.73784,   1.350499,    1.06899
,   0.793339,  0.7004349,  0.6883264,  0.7406906,   0.770223,  0.7639989
,  0.7741778,  0.8292753,  0.8317224,  0.7379978,   0.686568,  0.7884171
,   1.151671,    1.57519,   1.610881,   1.147358,  0.6885793,  0.7926385
,   1.176564,    1.55936,   1.840707,   1.863789,   1.653301,   1.124262
,  0.8113163,  0.8108309,   1.293192,   1.795676,   1.969441,   2.182979
,    2.60618,   2.286372,   1.896789,   1.805023,   1.656906,   1.406024
,    1.02226,  0.8974881,   1.285475,   2.190009,   2.751285,   2.731688
,   2.347717,   1.422706,  0.6460489,  0.5329052,  0.9788653,   1.620125
,   1.776664,   1.297038,   1.057853,  0.9328181,  0.8322033,  0.5407439
,  0.7607239,  0.8327132,  0.9406596,  0.9780981,  0.9550868,  0.9050186
,  0.8934786,   1.056173,   1.278622,   1.521359,   1.707454,   1.886104
,   2.008459,   2.084601,   2.128767,    2.17663,   2.255239,   2.417466
,   2.686807,   3.075549,    3.52523,   3.897731,   4.094755,   3.983346
,   3.670964,   3.133174,   2.457126,   1.914359,   1.601962,   1.321191
,   1.131063,  0.9759143,  0.9662387,   1.025531,   1.250905,   1.502601
,   1.923193,   2.301877,   2.527464,   2.623438,    2.64542,   2.573102
,   2.350022,   1.949378,   1.545164,   1.272785,   1.087234,   1.088009
,   1.203177,   1.281185,   1.357796,   1.641872,    1.96875,   2.187506
,   2.336916,   2.202508,    2.30517,   2.386808,   2.315965,    2.18046
,    1.80681,   1.342616,  0.9781311,  0.8114335,    1.04152,   1.069708
,   1.091329,   1.124509,   1.175016,   1.219798,   1.268113,   1.310445
,   1.337224,   1.361896,    1.37843,   1.392224,   1.383989,   1.347656
,   1.286647,   1.205964,   1.111583,   1.014673,  0.9127378,  0.8171927
,  0.7219748,  0.7055875,  0.7461661,  0.7580735,  0.7597259,  0.7470261
,  0.7242727,  0.6692963,  0.5902245,  0.4989052,  0.3849467,  0.2821263
,  0.2230666,  0.2254971,  0.2212141,  0.2728238,  0.3376213,  0.3449824
,  0.4046862,  0.5055943,  0.6227898,  0.7631364,  0.8946716,  0.9996328
,   1.088616,   1.158463,   1.217336,   1.266475,   1.332758,   1.402791
,   1.492355,   1.577112,   1.636454,   1.658352,   1.674837,   1.656319
,   1.602796,   1.498182,   1.358464,   1.206904,    1.11992,   1.061398
,   1.035493,   1.031126
};

extern void readCheckF(char *varname, int i1, int i2, float *var, float *varcopy, double delta);
extern void readCheckT(char *varname, int i1, int i2, float *var, float *varcopy, double delta);
extern void readCheckW(char *varname, int i1, int i2, float *var, float *varcopy, double delta);
extern void readCheckS(char *varname, int i1, int i2, float *var, float *varcopy, double delta);
extern void readCheckW2(char *varname, int i1, int i2, float *var, float *varcopy, double delta);
extern void readCheckD(char *varname, int i1, int i2, double *var, double *varcopy, double delta);
extern void readCheckFD(char *varname, int i1, int i2, float *var, double *varcopy, double delta);
extern void usage();

main(int argc, char *argv[]){

	double t21LatsCopy[T21_NLAT];
	float prcCopy[T21_NLON * T21_NLAT];
	double prcCopyD[T21_NLON * T21_NLAT];
	int fileid, latid, prcid, attlen;
	long start[3], count[3], order[3], stride[3];
	char prcunits[6], calendar[9];

	cuseterropts(CU_VERBOSE | CU_FATAL);

	fileid = cuopenread("testnc.nc",0);

	prcid = cuvarid(fileid, "prc");

					     /* Check casting */
	start[0]=1;
	start[1]=start[2]=0;
	count[0]=1;
	count[1]=T21_NLAT;
	count[2]=T21_NLON;

	cuvargets(fileid, prcid, 0, start, count, 0, CuDouble, prcCopyD);
	readCheckFD("prc", 0, T21_NLAT*T21_NLON, prc, prcCopyD, 4.e-5);

					     /* Test stride and transpose */
	start[0]=1;
	start[1]=0;
	start[2]=T21_NLAT-1;
	count[0]=1;
	count[1]=T21_NLON;
	count[2]=T21_NLAT;
	order[0]=0;
	order[1]=2;
	order[2]=1;
	stride[0]=1;
	stride[1]=1;
	stride[2]=-1;
	cuvargets(fileid, prcid, order, start, count, stride, 0, prcCopy);
	readCheckS("prc", 0, T21_NLAT, prc, prcCopy, 4.e-5);

					     /* Test 2-D wraparound and transpose */
	start[0]=1;
	start[1]=32;
	start[2]=16;
	count[0]=1;
	count[1]=T21_NLON;
	count[2]=T21_NLAT;
	order[0]=0;
	order[1]=2;
	order[2]=1;
	cuvargets(fileid, prcid, order, start, count, 0, 0, prcCopy);
	readCheckW2("prc", 0, T21_NLAT, prc, prcCopy, 4.e-5);

					     /* Test 1-D wraparound and transpose */
	start[0]=1;
	start[1]=0;
	start[2]=16;
	count[0]=1;
	count[1]=T21_NLON;
	count[2]=T21_NLAT;
	order[0]=0;
	order[1]=2;
	order[2]=1;
	cuvargets(fileid, prcid, order, start, count, 0, 0, prcCopy);
	readCheckW("prc", 0, T21_NLAT, prc, prcCopy, 4.e-5);

					     /* Test transpose and negative indices */
	start[0]=1;
	start[1]=-T21_NLON;
	start[2]=0;
	count[0]=1;
	count[1]=T21_NLON;
	count[2]=T21_NLAT;
	order[0]=0;
	order[1]=2;
	order[2]=1;
	cuvargets(fileid, prcid, order, start, count, 0, 0, prcCopy);
	readCheckT("prc", 0, T21_NLAT, prc, prcCopy, 4.e-5);

					     /* Test straight read */

	start[0]=1;
	start[1]=start[2]=0;
	count[0]=1;
	count[1]=T21_NLAT;
	count[2]=T21_NLON;

	cuvargets(fileid, prcid, 0, start, count, 0, 0, prcCopy);
	readCheckF("prc", 0, T21_NLAT*T21_NLON, prc, prcCopy, 4.e-5);

	exit(0);
}
					     /* Read and compare doubly wrapped, transposed float variable */
void readCheckW2(char *varname, int i1, int i2, float *var, float *varcopy, double delta){
	int i, j;
	int nread;
	float (*var2d)[T21_NLON];
	float (*var2dCopy)[T21_NLAT];

	var2d = (float (*)[])var;
	var2dCopy = (float (*)[])varcopy;
	for(i=i1; i<i2; i++){
		for(j=0; j<T21_NLON; j++){
			if(fabs(var2d[(i+16)%T21_NLAT][(j+32)%T21_NLON]-var2dCopy[j][i]) > delta){
				fprintf(stderr,"%s[%d][%d]=%f, %scopy[%d][%d]=%f\n",varname, (i+16)%T21_NLAT, (j+32)%T21_NLON, var2d[(i+16)%T21_NLAT][(j+32)%T21_NLON], varname, j, i, var2dCopy[j][i]);
				exit(1);
			}
		}
	}
}

					     /* Read and compare wrapped, transposed float variable */
void readCheckW(char *varname, int i1, int i2, float *var, float *varcopy, double delta){
	int i, j;
	int nread;
	float (*var2d)[T21_NLON];
	float (*var2dCopy)[T21_NLAT];

	var2d = (float (*)[])var;
	var2dCopy = (float (*)[])varcopy;
	for(i=i1; i<i2; i++){
		for(j=0; j<T21_NLON; j++){
			if(fabs(var2d[(i+16)%T21_NLAT][j]-var2dCopy[j][i]) > delta){
				fprintf(stderr,"%s[%d][%d]=%f, %scopy[%d][%d]=%f\n",varname, (i+16)%T21_NLAT, j, var2d[(i+16)%T21_NLAT][j], varname, j, i, var2dCopy[j][i]);
				exit(1);
			}
		}
	}
}

					     /* Read and compare negative stride, transposed float variable */
void readCheckS(char *varname, int i1, int i2, float *var, float *varcopy, double delta){
	int i, j;
	int nread;
	float (*var2d)[T21_NLON];
	float (*var2dCopy)[T21_NLAT];

	var2d = (float (*)[])var;
	var2dCopy = (float (*)[])varcopy;
	for(i=i1; i<i2; i++){
		for(j=0; j<T21_NLON; j++){
			if(fabs(var2d[T21_NLAT-i-1][j]-var2dCopy[j][i]) > delta){
				fprintf(stderr,"%s[%d][%d]=%f, %scopy[%d][%d]=%f\n",varname, T21_NLAT-i-1, j, var2d[T21_NLAT-i-1][j], varname, j, i, var2dCopy[j][i]);
				exit(1);
			}
		}
	}
}

					     /* Read and compare transposed float variable */
void readCheckT(char *varname, int i1, int i2, float *var, float *varcopy, double delta){
	int i, j;
	int nread;
	float (*var2d)[T21_NLON];
	float (*var2dCopy)[T21_NLAT];

	var2d = (float (*)[])var;
	var2dCopy = (float (*)[])varcopy;
	for(i=i1; i<i2; i++){
		for(j=0; j<T21_NLON; j++){
			if(fabs(var2d[i][j]-var2dCopy[j][i]) > delta){
				fprintf(stderr,"%s[%d][%d]=%f, %scopy[%d][%d]=%f\n",varname, i, j, var2d[i][j], varname, j, i, var2dCopy[j][i]);
				exit(1);
			}
		}
	}
}

					     /* Read and compare float variable */
void readCheckF(char *varname, int i1, int i2, float *var, float *varcopy, double delta){
	int i;
	int nread;

	for(i=i1; i<i2; i++){
		if(fabs(var[i]-varcopy[i]) > delta){
			fprintf(stderr,"%s[%d]=%f, %scopy[%d]=%f\n",varname, i, var[i], varname, i, varcopy[i]);
			exit(1);
		}
	}
}

					     /* Read and compare double and float variable */
void readCheckFD(char *varname, int i1, int i2, float *var, double *varcopy, double delta){
	int i;
	int nread;

	for(i=i1; i<i2; i++){
		if(fabs(var[i]-varcopy[i]) > delta){
			fprintf(stderr,"%s[%d]=%f, %scopy[%d]=%f\n",varname, i, var[i], varname, i, varcopy[i]);
			exit(1);
		}
	}
}

void
usage(){
	fprintf(stderr,"Usage: testnc\n");
	fprintf(stderr,"   Open the test netCDF file and check data\n");
	exit(1);
}
