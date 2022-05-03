EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 62540855
P 2450 2650
F 0 "J1" H 2400 3050 50  0000 L CNN
F 1 "WEMOS D1_1" V 2600 2450 50  0000 L CNN
F 2 "" H 2450 2650 50  0001 C CNN
F 3 "~" H 2450 2650 50  0001 C CNN
	1    2450 2650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J2
U 1 1 62541247
P 2900 2650
F 0 "J2" H 2900 3050 50  0000 C CNN
F 1 "WEMOS D1_2" V 3000 2700 50  0000 C CNN
F 2 "" H 2900 2650 50  0001 C CNN
F 3 "~" H 2900 2650 50  0001 C CNN
	1    2900 2650
	-1   0    0    -1  
$EndComp
Text Label 1850 2350 0    50   ~ 0
WEMOS_TX
Text Label 1850 2450 0    50   ~ 0
WEMOS_RX
Text Label 2150 2550 0    50   ~ 0
D1
Text Label 2150 2650 0    50   ~ 0
D2
Text Label 2150 2750 0    50   ~ 0
D3
Text Label 2150 2850 0    50   ~ 0
D4
Text Label 2150 3050 0    50   ~ 0
5V
Text Label 2100 2950 0    50   ~ 0
GND
Text Label 3100 2350 0    50   ~ 0
RST
Text Label 3100 2450 0    50   ~ 0
A0
Text Label 3100 2550 0    50   ~ 0
D0
Text Label 3100 2750 0    50   ~ 0
D6
Text Label 3100 2850 0    50   ~ 0
D7
Text Label 3100 2950 0    50   ~ 0
D8
Text Label 3100 2650 0    50   ~ 0
D5
Text Label 3100 3050 0    50   ~ 0
3v3
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 625441BF
P 3700 2700
F 0 "J3" H 3618 3117 50  0000 C CNN
F 1 "Waveshare SIM7000E" H 3618 3026 50  0000 C CNN
F 2 "" H 3700 2700 50  0001 C CNN
F 3 "~" H 3700 2700 50  0001 C CNN
	1    3700 2700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1850 2350 2250 2350
Wire Wire Line
	2250 2450 1850 2450
Wire Wire Line
	2150 2550 2250 2550
Wire Wire Line
	2150 2650 2250 2650
Wire Wire Line
	2150 2750 2250 2750
Wire Wire Line
	2150 2850 2250 2850
Wire Wire Line
	2150 3050 2250 3050
Text Label 3900 2500 0    50   ~ 0
5V
Text Label 3900 2600 0    50   ~ 0
GND
Text Label 3900 2700 0    50   ~ 0
Waveshare_RXD
Text Label 3900 2800 0    50   ~ 0
Waveshare_TX
Text Label 3900 2900 0    50   ~ 0
DTR
Text Label 3900 3000 0    50   ~ 0
PWR
Wire Wire Line
	2100 2950 2250 2950
$Comp
L power:+5V #PWR?
U 1 1 62548584
P 1300 2450
F 0 "#PWR?" H 1300 2300 50  0001 C CNN
F 1 "+5V" H 1315 2623 50  0000 C CNN
F 2 "" H 1300 2450 50  0001 C CNN
F 3 "" H 1300 2450 50  0001 C CNN
	1    1300 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2450 1300 2550
Text Label 1150 2550 0    50   ~ 0
5V
Wire Wire Line
	1150 2550 1300 2550
Text Label 1150 2650 0    50   ~ 0
GND
$Comp
L power:GND #PWR?
U 1 1 62549391
P 1300 2800
F 0 "#PWR?" H 1300 2550 50  0001 C CNN
F 1 "GND" H 1305 2627 50  0000 C CNN
F 2 "" H 1300 2800 50  0001 C CNN
F 3 "" H 1300 2800 50  0001 C CNN
	1    1300 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2650 1300 2650
Wire Wire Line
	1300 2650 1300 2800
$Comp
L Device:R_Small R1
U 1 1 6254F066
P 5850 2100
F 0 "R1" H 5909 2146 50  0000 L CNN
F 1 "R_Small" H 5909 2055 50  0000 L CNN
F 2 "" H 5850 2100 50  0001 C CNN
F 3 "~" H 5850 2100 50  0001 C CNN
	1    5850 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 6254F62E
P 5850 2550
F 0 "R2" H 5909 2596 50  0000 L CNN
F 1 "R_Small" H 5909 2505 50  0000 L CNN
F 2 "" H 5850 2550 50  0001 C CNN
F 3 "~" H 5850 2550 50  0001 C CNN
	1    5850 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 6254FB8A
P 6350 2550
F 0 "C1" H 6442 2596 50  0000 L CNN
F 1 "C_Small" H 6442 2505 50  0000 L CNN
F 2 "" H 6350 2550 50  0001 C CNN
F 3 "~" H 6350 2550 50  0001 C CNN
	1    6350 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2000 5850 1900
Wire Wire Line
	5850 2200 5850 2350
Wire Wire Line
	5850 2350 6350 2350
Wire Wire Line
	6350 2350 6350 2450
Connection ~ 5850 2350
Wire Wire Line
	5850 2350 5850 2450
Wire Wire Line
	6350 2350 6850 2350
Connection ~ 6350 2350
Text Label 6850 2350 0    50   ~ 0
A0
$Comp
L power:+5V #PWR?
U 1 1 62551218
P 5850 1900
F 0 "#PWR?" H 5850 1750 50  0001 C CNN
F 1 "+5V" H 5865 2073 50  0000 C CNN
F 2 "" H 5850 1900 50  0001 C CNN
F 3 "" H 5850 1900 50  0001 C CNN
	1    5850 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2650 5850 2750
$Comp
L power:GND #PWR?
U 1 1 62551FE6
P 5850 2800
F 0 "#PWR?" H 5850 2550 50  0001 C CNN
F 1 "GND" H 5855 2627 50  0000 C CNN
F 2 "" H 5850 2800 50  0001 C CNN
F 3 "" H 5850 2800 50  0001 C CNN
	1    5850 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2650 6350 2750
Wire Wire Line
	6350 2750 5850 2750
Connection ~ 5850 2750
Wire Wire Line
	5850 2750 5850 2800
$EndSCHEMATC
