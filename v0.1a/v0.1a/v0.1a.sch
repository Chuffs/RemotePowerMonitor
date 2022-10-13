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
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2450 2650 50  0001 C CNN
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
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2900 2650 50  0001 C CNN
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
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 3700 2700 50  0001 C CNN
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
P 1550 2500
F 0 "#PWR?" H 1550 2350 50  0001 C CNN
F 1 "+5V" H 1565 2673 50  0000 C CNN
F 2 "" H 1550 2500 50  0001 C CNN
F 3 "" H 1550 2500 50  0001 C CNN
	1    1550 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2500 1550 2600
Text Label 1400 2600 0    50   ~ 0
5V
Wire Wire Line
	1400 2600 1550 2600
Text Label 1400 2700 0    50   ~ 0
GND
$Comp
L power:GND #PWR?
U 1 1 62549391
P 1550 2850
F 0 "#PWR?" H 1550 2600 50  0001 C CNN
F 1 "GND" H 1555 2677 50  0000 C CNN
F 2 "" H 1550 2850 50  0001 C CNN
F 3 "" H 1550 2850 50  0001 C CNN
	1    1550 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 2700 1550 2700
Wire Wire Line
	1550 2700 1550 2850
$Comp
L Device:R_Small R1
U 1 1 6254F066
P 5000 2200
F 0 "R1" H 5059 2246 50  0000 L CNN
F 1 "2k2" H 5059 2155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" H 5000 2200 50  0001 C CNN
F 3 "~" H 5000 2200 50  0001 C CNN
	1    5000 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 6254F62E
P 5000 2650
F 0 "R2" H 5059 2696 50  0000 L CNN
F 1 "3k3" H 5059 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" H 5000 2650 50  0001 C CNN
F 3 "~" H 5000 2650 50  0001 C CNN
	1    5000 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 6254FB8A
P 5500 2650
F 0 "C1" H 5592 2696 50  0000 L CNN
F 1 "1000uF" H 5592 2605 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P2.50mm_P5.00mm" H 5500 2650 50  0001 C CNN
F 3 "~" H 5500 2650 50  0001 C CNN
	1    5500 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2100 5000 2000
Wire Wire Line
	5000 2300 5000 2450
Wire Wire Line
	5000 2450 5500 2450
Wire Wire Line
	5500 2450 5500 2550
Connection ~ 5000 2450
Wire Wire Line
	5000 2450 5000 2550
Wire Wire Line
	5500 2450 6000 2450
Connection ~ 5500 2450
Text Label 6000 2450 0    50   ~ 0
A0
$Comp
L power:+5V #PWR?
U 1 1 62551218
P 5000 2000
F 0 "#PWR?" H 5000 1850 50  0001 C CNN
F 1 "+5V" H 5015 2173 50  0000 C CNN
F 2 "" H 5000 2000 50  0001 C CNN
F 3 "" H 5000 2000 50  0001 C CNN
	1    5000 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2750 5000 2850
$Comp
L power:GND #PWR?
U 1 1 62551FE6
P 5000 2900
F 0 "#PWR?" H 5000 2650 50  0001 C CNN
F 1 "GND" H 5005 2727 50  0000 C CNN
F 2 "" H 5000 2900 50  0001 C CNN
F 3 "" H 5000 2900 50  0001 C CNN
	1    5000 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2750 5500 2850
Wire Wire Line
	5500 2850 5000 2850
Connection ~ 5000 2850
Wire Wire Line
	5000 2850 5000 2900
Text Label 5250 3450 0    50   ~ 0
Waveshare_RXD
Text Label 5250 3600 0    50   ~ 0
Waveshare_TX
Text Label 4950 3600 0    50   ~ 0
D7
Text Label 4950 3450 0    50   ~ 0
D4
Wire Wire Line
	4950 3450 5250 3450
Wire Wire Line
	4950 3600 5250 3600
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 6271BF24
P 1200 2700
F 0 "J4" H 1200 2350 50  0000 C CNN
F 1 "PWR Connector" H 1250 2450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1200 2700 50  0001 C CNN
F 3 "~" H 1200 2700 50  0001 C CNN
	1    1200 2700
	-1   0    0    1   
$EndComp
$EndSCHEMATC
