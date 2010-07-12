/*  Copyright (C) 1988-2010 by Brian Doty and the 
    Institute of Global Environment and Society (IGES).  
    See file COPYRIGHT for more information.   */

/*  Constants for generating wx symbols */

gaint stype[83] =
    { 11, 8, 8, 2, 8, 1, 8,16, 8, 6, 9, 9, 2, 9, 1,
       9,16, 9, 6,10, 2, 2,10, 2, 5, 2, 4, 2, 2, 2,
       2, 2, 2, 2, 2, 2, 2, 4, 1, 5, 1, 1, 1, 1, 1,
       1, 1, 1, 1, 1, 7, 2, 7, 2,10, 3, 3,10, 3, 3,
       3, 3, 3, 3, 3, 3, 3, 3, 4, 6, 5, 6,13,12,14,
      15, 2, 1,17,18,19,19,20};
gadouble sxpos[83] =
    {   0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0,
        0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0,
        0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  , -0.175,
        0.175,  0.0  , -0.175,  0.0  ,  0.0  ,  0.0  ,  0.0,
       -0.150,  0.150, -0.150,  0.150,  0.0  , -0.150,  0.150,
        0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  , -0.200,
        0.200, -0.200,  0.200,  0.0  , -0.200,  0.200,  0.0,
        0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  , -0.175,
        0.175,  0.0  , -0.175, -0.150,  0.150, -0.150,  0.150,
        0.0  , -0.150,  0.150,  0.0  ,  0.0  ,  0.0  ,  0.0,
        0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0,
        0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0};
gadouble sypos[83] =
    {   0.0  ,  0.0  , -0.1  ,  0.375, -0.1  ,  0.400, -0.1,
        0.350, -0.1  ,  0.375,  0.0  ,  0.0  ,  0.475,  0.0,
        0.500,  0.0  ,  0.450,  0.0  ,  0.475,  0.0  , -0.10,
        0.10 ,  0.0  , -0.1  , -0.1 ,  0.275, -0.1  ,  0.275,
        0.0  ,  0.0  , -0.100, -0.100,  0.150,  0.0  ,  0.0,
        0.250, -0.250, -0.2  ,  0.250, -0.2  ,  0.250,  0.0,
        0.0  , -0.150, -0.150,  0.200,  0.0  ,  0.0  ,  0.300,
       -0.300,  0.0  , -0.100,  0.0  , -0.100,  0.0  , -0.150,
        0.150,  0.0  , -0.150,  0.0  ,  0.0  , -0.100, -0.100,
        0.150,  0.0  ,  0.0  ,  0.250, -0.250, -0.15 ,  0.300,
       -0.15 ,  0.300,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.200,
       -0.200,  0.0  ,  0.0  ,  0.0  ,  0.0  ,  0.0};
gaint strt[43] = {1,2,3,5,7,9,11,12,14,16,18,20,23,25,27,29,31,
       34,38,40,42,44,47,51,53,55,58,60,62,65,69,71,73,74,75,
       76,77,79,80,81,82,83,83};
gaint scnt[43] = {1,1,2,2,2,2,1,2,2,2,2,3,2,2,2,2,3,4,2,2,
       2,3,4,2,2,3,2,2,3,4,2,2,1,1,1,1,2,1,1,1,1,1,1};
gadouble symin[39] = {-.35,-.3,-.4,-.4,-.4,-.4,-.45,-.45,-.45,-.45,-.45,
       -.2,-.2,-.3,-.3,-.1,-.25,-.35,-.45,
       -.45,-.15,-.30,-.45,-.3,-.3,-.25,-.25,-.15,-.25,-.4,-.35,
       -.35,-.15,-.15,-.25,-.35,-.35,-.25,-.2};
gadouble symax[39] = {.35,.3,.45,.5,.45,.45,.3,.55,.6,.55,.55,
       .2,.2,.35,.35,.1,.25,.35,.4,.4,.15,.35,.45,.3,.3,.25,.2,
       .15,.3,.4,.40,.40,.15,.15,.25,.35,.4,.25,.25};
gadouble sxwid[39] = {.4,.5,.5,.5,.5,.5,.5,.5,.5,.5,.5,
       .7,.7,.4,.4,.5,.5,.5,.5,.5,.7,.7,.7,.7,.7,.7,.7,
       .5,.5,.5,.4,.4,.6,.5,.5,.3,.3,.3,.4};
gaint soff[20] =  {1,7,20,35,39,45,49,53,61,70,84,92,96,104,
                         114,131,139,145,157,171};
gaint slen[20] =  {6,13,15,4,6,4,4,8,9,14,8,4,8,10,17,8,6,12,14,14};
gaint scol[20] =  {2,1,1,1,1,0,0,0,0,0,0,3,4,4,4,0,0,4,0,0};
gadouble xpts[184] =
       { -0.150, 0.150,-0.150, 0.150, 0.0  , 0.0  ,-0.100,-0.087,
         -0.050, 0.0  , 0.050, 0.087, 0.100, 0.087, 0.050, 0.0  ,
         -0.050,-0.087,-0.100, 0.030,-0.050,-0.100,-0.087,-0.050,
          0.0  , 0.050, 0.087, 0.100, 0.100, 0.087, 0.050, 0.0  ,
          0.030, 0.030,-0.200, 0.200, 0.0  ,-0.200,-0.200, 0.200,
          0.0  ,-0.200,-0.150, 0.150,-0.150, 0.0  , 0.150,-0.150,
         -0.350, 0.0  , 0.350,-0.350,-0.250,-0.250, 0.250,-0.150,
          0.250, 0.200, 0.250, 0.100,-0.250,-0.250, 0.250,-0.150,
          0.250, 0.050, 0.100, 0.050, 0.200,-0.350,-0.350,-0.320,
         -0.250,-0.175,-0.100,-0.050, 0.050, 0.100, 0.175, 0.250,
          0.320, 0.350, 0.350,-0.200,-0.100,-0.100,-0.200, 0.200,
          0.100, 0.100, 0.200,-0.250, 0.250,-0.250, 0.250,-0.175,
         -0.300,-0.175,-0.300, 0.300, 0.175, 0.300, 0.175,-0.250,
          0.250, 0.150, 0.250, 0.150, 0.0  , 0.0  ,-0.100, 0.0  ,
          0.100, 0.0  , 0.0  ,-0.100, 0.0  , 0.100, 0.150, 0.050,
         -0.050,-0.130,-0.150,-0.120, 0.120, 0.150, 0.130, 0.050,
         -0.050,-0.150,-0.150,-0.150,-0.100,-0.050, 0.050, 0.100,
          0.150, 0.150, 0.150,-0.150, 0.150, 0.110, 0.150, 0.000,
         -0.150,-0.150,-0.130,-0.100,-0.070,-0.030, 0.000, 0.030,
          0.070, 0.100, 0.130, 0.170,-0.200,-0.200,-0.180,-0.150,
         -0.100,-0.030, 0.050, 0.200, 0.200, 0.180, 0.150, 0.100,
          0.030,-0.050,-0.200,-0.200,-0.180,-0.150,-0.100,-0.030,
          0.050, 0.200, 0.200, 0.180, 0.150, 0.100, 0.030,-0.050};
gadouble ypts[184] =
       { 0.100,-0.100,-0.100, 0.100, 0.175,-0.175, 0.0  , 0.050,
         0.087, 0.100, 0.087, 0.050, 0.0  ,-0.050,-0.087,-0.100,
        -0.087,-0.050, 0.0  , 0.0  , 0.0  , 0.050, 0.100, 0.137,
         0.150, 0.137, 0.100, 0.050, 0.0  ,-0.050,-0.100,-0.150,
        -0.075, 0.0  , 0.200, 0.200,-0.200, 0.200, 0.200, 0.200,
        -0.200, 0.200, 0.100, 0.100,-0.100, 0.100,-0.100,-0.100,
        -0.300, 0.300,-0.300,-0.300,-0.300, 0.300, 0.300, 0.0  ,
        -0.300,-0.150,-0.300,-0.280,-0.300, 0.300, 0.300, 0.0  ,
        -0.300,-0.450,-0.300,-0.450,-0.430,-0.150, 0.0  , 0.100,
         0.160, 0.175, 0.160, 0.100,-0.100,-0.160,-0.175,-0.160,
        -0.100, 0.0  , 0.150, 0.350, 0.250,-0.250,-0.350, 0.350,
         0.250,-0.250,-0.350, 0.100, 0.100,-0.100,-0.100, 0.125,
         0.0  ,-0.125, 0.0  , 0.0  , 0.125, 0.0  ,-0.125, 0.0  ,
         0.0  , 0.100, 0.0  ,-0.100,-0.250, 0.250, 0.150, 0.250,
         0.150,-0.350, 0.350, 0.200, 0.350, 0.200, 0.100, 0.150,
         0.150, 0.100, 0.050, 0.0  ,-0.100,-0.150,-0.200,-0.250,
        -0.250,-0.200,-0.075, 0.0  , 0.075, 0.075,-0.075,-0.075,
         0.0  , 0.075, 0.250, 0.0  ,-0.250,-0.100,-0.250,-0.220,
        -0.200, 0.200, 0.240, 0.255, 0.240, 0.160, 0.145, 0.160,
         0.240, 0.255, 0.240, 0.160, 0.000, 0.200, 0.300, 0.380,
         0.430, 0.470, 0.500, 0.000,-0.200,-0.300,-0.380,-0.430,
        -0.470,-0.500, 0.000,-0.200,-0.300,-0.380,-0.430,-0.470,
        -0.500, 0.000, 0.200, 0.300, 0.380, 0.430, 0.470, 0.500};
gaint spens[184] =
      { 3,2,3,2,3,2,3,2,2,2,2,2,2,2,2,2,2,2,2,3,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,3,2,2,2,3,2,2,2,3,2,3,2,2,2,3,2,
        2,2,3,2,2,2,2,2,3,2,3,2,2,2,2,2,2,3,2,3,2,2,2,2,2,
        2,2,2,2,2,2,2,2,3,2,2,2,3,2,2,2,3,2,3,2,3,2,2,3,2,
        3,2,2,3,2,3,2,2,3,2,3,2,2,3,2,3,2,2,3,2,2,2,2,2,2,
        2,2,2,2,2,3,2,2,2,2,2,2,2,3,2,2,2,3,2,3,2,2,2,2,2,
        2,2,2,2,2,2,3,2,2,2,2,2,2,3,2,2,2,2,2,2,3,2,2,2,2,
        2,2,3,2,2,2,2,2,2};
