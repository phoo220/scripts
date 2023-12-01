-- This reservoir simulation deck is made available under the Open Database
-- License: http://opendatacommons.org/licenses/odbl/1.0/. Any rights in
-- individual contents of the database are licensed under the Database Contents
-- License: http://opendatacommons.org/licenses/dbcl/1.0/

-- Copyright (C) 2015 Statoil

-- This simulation is based on the data given in 
-- 'Comparison of Solutions to a Three-Dimensional
-- Black-Oil Reservoir Simulation Problem' by Aziz S. Odeh,
-- Journal of Petroleum Technology, January 1981

-- NOTE: This deck is currently not supported by the OPM
-- simulator flow due to lack of support for DRSDT.

---------------------------------------------------------------------------
------------------------ SPE1 - CASE 1 ------------------------------------
---------------------------------------------------------------------------

RUNSPEC
-- -------------------------------------------------------------------------

TITLE
   SPE1 - CASE 1

DIMENS
   10 10 3 /

-- The number of equilibration regions is inferred from the EQLDIMS
-- keyword.
EQLDIMS
/

-- The number of PVTW tables is inferred from the TABDIMS keyword;
-- when no data is included in the keyword the default values are used.
TABDIMS
/

OIL
GAS
WATER
DISGAS
-- As seen from figure 4 in Odeh, GOR is increasing with time,
-- which means that dissolved gas is present

METRIC

START
   1 'JAN' 2015 /

WELLDIMS
-- Item 1: maximum number of wells in the model
-- 	   - there are two wells in the problem; injector and producer
-- Item 2: maximum number of grid blocks connected to any one well
-- 	   - must be one as the wells are located at specific grid blocks
-- Item 3: maximum number of groups in the model
-- 	   - we are dealing with only one 'group'
-- Item 4: maximum number of wells in any one group
-- 	   - there must be two wells in a group as there are two wells in total
   2 2 1 2 /

UNIFIN
UNIFOUT

GRID

-- The INIT keyword is used to request an .INIT file. The .INIT file
-- is written before the simulation actually starts, and contains grid
-- properties and saturation tables as inferred from the input
-- deck. There are no other keywords which can be used to configure
-- exactly what is written to the .INIT file.
INIT


-- -------------------------------------------------------------------------
NOECHO

DX 
-- There are in total 300 cells with length 1000ft in x-direction	
   	300*500 /
DY
-- There are in total 300 cells with length 1000ft in y-direction	
	300*500 /
DZ
-- The layers are 20, 30 and 50 ft thick, in each layer there are 100 cells
	100*30 100*5 100*15 /

TOPS
-- The depth of the top of each grid block
	100*3000 100*3030 100*3035 /

PORO
-- Constant porosity of 0.3 throughout all 300 grid cells
   	300*0.3 /

PERMX
-- The layers have perm. 500mD, 50mD and 200mD, respectively.
	100*500 100*0 100*200 /

PERMY
-- Equal to PERMX
	100*500 100*0 100*200 /

PERMZ
-- Cannot find perm. in z-direction in Odeh's paper
-- For the time being, we will assume PERMZ equal to PERMX and PERMY:
	100*500 100*0 100*200 /
ECHO

PROPS
-- -------------------------------------------------------------------------

PVTW
-- Using values from Norne:
    200 1.038 4.67E-5 0.318 0.0 /

ROCK
-- Using values from Norne:
	200     4.84E-5 /

SWOF
-- Values in column 1-3 are taken SPE1CASE1.DATA
0.12	0    		        	1	    0
0.18	4.64876033057851E-008	1	    0
0.24	0.000000186	        	0.997	0
0.3	    4.18388429752066E-007	0.98	0
0.36	7.43801652892562E-007	0.7	    0
0.42	1.16219008264463E-006	0.35	0
0.48	1.67355371900826E-006	0.2 	0
0.54	2.27789256198347E-006	0.09	0
0.6	    2.97520661157025E-006	0.021	0
0.66	3.7654958677686E-006	0.01	0
0.72	4.64876033057851E-006	0.001	0
0.78	0.000005625	        	0.0001	0
0.84	6.69421487603306E-006	0	    0
0.91	8.05914256198347E-006	0   	0
1	    0.00001		        	0   	0 /


SGOF
-- Values in column 1-3 are taken SPE1CASE1.DATA
-- SGAS KRG KRO PCOG
0	    0	    1   	0
0.001	0	    1	    0
0.02	0	    0.997	0
0.05	0.005	0.980	0
0.12	0.025	0.700	0
0.2	    0.075	0.350	0
0.25	0.125	0.200	0
0.3 	0.190	0.090	0
0.4	    0.410	0.021	0
0.45	0.60	0.010	0
0.5 	0.72	0.001	0
0.6 	0.87	0.0001	0
0.7 	0.94	0.000	0
0.85	0.98	0.000	0 
0.88	0.984	0.000	0 /
--1.00	1.0	0.000	0 /

DENSITY
-- Using values from Norne:
-- In METRIC units:
      859.5 1033.0 0.854 /

PVDG
-- Using values from SPE1CASE1.DATA
-- PRESSURE       GFVF     VISCOSITY                                
--   BAR                     (CP) 
    1.01	    0.9357	    0.008000
    18.25	    0.0678	    0.009600
    35.48	    0.0352	    0.011200
    69.96	    0.0179	    0.014000
    138.90	    0.0091	    0.018900
    173.38	    0.0073      0.020800
    207.85	    0.0061	    0.022800
    276.80	    0.0046	    0.026800
    345.75	    0.0036	    0.030900
    621.54	    0.0022	    0.047000 /

PVTO
-- Use values from SPE1CASE1.DATA
--  RSO       PRESSURE       B-OIL      VISCOSI
--               (BAR)                  (CP) 
    0.18	    1.01	    1.0620	    1.0400 /
    16.12	    18.25	    1.1500	    0.9750 /
    32.06	    35.48	    1.2070	    0.9100 /
    66.08	    69.96	    1.2950	    0.8300 /
    113.28  	138.90	    1.4350	    0.6950 /
    138.03	    173.38	    1.5000	    0.6410 /
    165.64  	207.85	    1.5650	    0.5940 /
    226.19  	276.80	    1.6950	    0.5100 
    	        621.54	    1.5790	    0.7400 /
    288.18  	345.75	    1.8270	    0.4490 
    	        621.54	    1.7370	    0.6310 /	
/

REGIONS 
-- ---------------------------------------------------------------------------
 EQUALS
--          I1  I2  J1  J2  K1  K2
 FIPNUM 1    1*  1*  1*  1*  1  1 / SET REGION 1
 FIPNUM 2    1*  1*  1*  1*  3  3 / SET REGION 1
/

SOLUTION
-- -------------------------------------------------------------------------

EQUIL
--datum press OWC WATCAP GOC GASCAP 
	3000 200 3035 0 0 0 1 0 0 /

RSVD
-- Depth    RS(dissolved gas)
0    226
3035 226 /


SUMMARY
-- -------------------------------------------------------------------------	 
AAQR
/
AAQT
/

FOPR
FWPR
FGPR
FWIR
FGIR
FPR
FGOR

CLFR
--	'INJ'
/

COFR
--	'INJ'
--	'PROD'
/

CWFR
	'INJ' 1 1 1  /
    'INJ' 1 1 3  /
/

WGOR
  'PROD'
/

BPR
1	1 	1 /
1 	1 	3 / 
10 	10 	1 /
/

BGSAT
1 	1 	1 /
1 	1 	3 / 
10 	10 	1 /
/

-- In order to compare Eclipse with Flow:
WBHP
  'INJ'
  'PROD'
/
WGIR
  'INJ'
  'PROD'
/
WGIT
  'INJ'
  'PROD'
/
WGPR
  'INJ'
  'PROD'
/
WGPT
  'INJ'
  'PROD'
/
WOPR
  'INJ'
  'PROD'
/
WOPT
  'INJ'
  'PROD'
/
WWIR
  'INJ'
  'PROD'
/
WWIT
  'INJ'
  'PROD'
/
WWPR
  'INJ'
  'PROD'
/
WWPT
  'INJ'
  'PROD'
/
