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
L Isolator:4N25 U1
U 1 1 62C15995
P 4750 2700
F 0 "U1" H 4750 3025 50  0000 C CNN
F 1 "4N25" H 4750 2934 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 4550 2500 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83725/4n25.pdf" H 4750 2700 50  0001 L CNN
	1    4750 2700
	1    0    0    -1  
$EndComp
Text Label 8000 1800 0    50   ~ 0
5v_wall
Text Label 6850 1750 2    50   ~ 0
GND_wall
Text Label 8000 2200 0    50   ~ 0
5v_reg
Text Label 8000 2600 0    50   ~ 0
3v3_reg
Wire Wire Line
	6850 1750 6950 1750
NoConn ~ 5050 2600
Wire Wire Line
	5050 2800 5200 2800
Wire Wire Line
	5200 2800 5200 2850
$Comp
L Device:R_Small R1
U 1 1 62C1ECBF
P 5200 2950
F 0 "R1" H 5259 2996 50  0000 L CNN
F 1 "10k" H 5259 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 5200 2950 50  0001 C CNN
F 3 "~" H 5200 2950 50  0001 C CNN
	1    5200 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2700 5200 2700
Wire Wire Line
	5200 2700 5200 2450
Text Label 5500 2800 0    50   ~ 0
Outage_Sense
Wire Wire Line
	5200 3050 5200 3200
$Comp
L Connector:TestPoint TP1
U 1 1 62C229DE
P 7500 1800
F 0 "TP1" H 7558 1872 50  0000 L CNN
F 1 "5v Wall" H 7558 1827 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 7700 1800 50  0001 C CNN
F 3 "~" H 7700 1800 50  0001 C CNN
	1    7500 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1800 8000 1800
$Comp
L Connector:TestPoint TP2
U 1 1 62C2496D
P 7500 2200
F 0 "TP2" H 7558 2272 50  0000 L CNN
F 1 "5v Regulator" H 7558 2227 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 7700 2200 50  0001 C CNN
F 3 "~" H 7700 2200 50  0001 C CNN
	1    7500 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2200 8000 2200
$Comp
L Connector:TestPoint TP3
U 1 1 62C24DBA
P 7500 2600
F 0 "TP3" H 7558 2672 50  0000 L CNN
F 1 "3v3 Regulator" H 7558 2627 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 7700 2600 50  0001 C CNN
F 3 "~" H 7700 2600 50  0001 C CNN
	1    7500 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2600 8000 2600
$Comp
L Connector:TestPoint TP6
U 1 1 62C2549A
P 6950 1750
F 0 "TP6" H 7008 1822 50  0000 L CNN
F 1 "Wall GND" H 7008 1777 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 7150 1750 50  0001 C CNN
F 3 "~" H 7150 1750 50  0001 C CNN
	1    6950 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP4
U 1 1 62C27EE4
P 8700 2050
F 0 "TP4" H 8758 2122 50  0000 L CNN
F 1 "Battery +" H 8758 2077 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 8900 2050 50  0001 C CNN
F 3 "~" H 8900 2050 50  0001 C CNN
	1    8700 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP5
U 1 1 62C28FFF
P 8700 2450
F 0 "TP5" H 8758 2522 50  0000 L CNN
F 1 "uP GND" H 8758 2477 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 8900 2450 50  0001 C CNN
F 3 "~" H 8900 2450 50  0001 C CNN
	1    8700 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2050 9200 2050
Wire Wire Line
	8700 2450 9200 2450
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 62C2A662
P 9400 2050
F 0 "J1" H 9480 2042 50  0000 L CNN
F 1 "BATT in" H 9480 1951 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9400 2050 50  0001 C CNN
F 3 "~" H 9400 2050 50  0001 C CNN
	1    9400 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 2450 9200 2150
Text Label 9300 2450 0    50   ~ 0
uP_GND
Wire Wire Line
	9300 2450 9200 2450
Connection ~ 9200 2450
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 62C2BDDB
P 8200 3800
F 0 "J2" H 8280 3842 50  0000 L CNN
F 1 "External 5v Reg" H 8280 3751 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8200 3800 50  0001 C CNN
F 3 "~" H 8200 3800 50  0001 C CNN
	1    8200 3800
	1    0    0    -1  
$EndComp
Text Label 9200 2050 2    50   ~ 0
Batt+
Text Label 7800 3700 2    50   ~ 0
Batt+
Wire Wire Line
	7800 3700 8000 3700
Wire Wire Line
	8000 3800 7800 3800
Wire Wire Line
	7800 3900 8000 3900
$Comp
L My_Library:+3.3V #PWR0109
U 1 1 62C2DAE7
P 5200 2450
F 0 "#PWR0109" H 5200 2300 50  0001 C CNN
F 1 "+3.3V" H 5215 2623 50  0000 C CNN
F 2 "" H 5200 2450 50  0001 C CNN
F 3 "" H 5200 2450 50  0001 C CNN
	1    5200 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP8
U 1 1 62C2E429
P 5350 2700
F 0 "TP8" H 5408 2772 50  0000 L CNN
F 1 "Outage_Sense" H 5408 2727 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 5550 2700 50  0001 C CNN
F 3 "~" H 5550 2700 50  0001 C CNN
	1    5350 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 62C32F5D
P 4300 2450
F 0 "#PWR0110" H 4300 2300 50  0001 C CNN
F 1 "+5V" H 4315 2623 50  0000 C CNN
F 2 "" H 4300 2450 50  0001 C CNN
F 3 "" H 4300 2450 50  0001 C CNN
	1    4300 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 62C3459F
P 4300 2950
F 0 "R2" H 4359 2996 50  0000 L CNN
F 1 "50" H 4359 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 4300 2950 50  0001 C CNN
F 3 "~" H 4300 2950 50  0001 C CNN
	1    4300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2800 4300 2800
Wire Wire Line
	4300 2800 4300 2850
Wire Wire Line
	4300 3050 4300 3200
Wire Wire Line
	4300 2450 4300 2600
Wire Wire Line
	4300 2600 4450 2600
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 62C38B75
P 8200 4300
F 0 "J3" H 8280 4292 50  0000 L CNN
F 1 "5v Wall" H 8280 4201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8200 4300 50  0001 C CNN
F 3 "~" H 8200 4300 50  0001 C CNN
	1    8200 4300
	1    0    0    -1  
$EndComp
Text Label 7800 4400 2    50   ~ 0
GND_wall
Text Label 7800 4300 2    50   ~ 0
5v_wall
$Comp
L wemos_mini:WeMos_D1_mini U2
U 1 1 62C3E700
P 4750 4200
F 0 "U2" H 4750 4837 60  0000 C CNN
F 1 "WeMos_D1_mini" H 4750 4731 60  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 5300 3500 60  0001 C CNN
F 3 "http://www.wemos.cc/Products/d1_mini.html" H 4750 4731 60  0001 C CNN
	1    4750 4200
	1    0    0    -1  
$EndComp
Text Label 3400 2350 0    50   ~ 0
Batt+
$Comp
L Device:R_Small R3
U 1 1 62C45C5C
P 3400 2550
F 0 "R3" H 3459 2596 50  0000 L CNN
F 1 "10k" H 3459 2505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 3400 2550 50  0001 C CNN
F 3 "~" H 3400 2550 50  0001 C CNN
	1    3400 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R4
U 1 1 62C46153
P 3400 2850
F 0 "R4" H 3459 2896 50  0000 L CNN
F 1 "10k" H 3459 2805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 3400 2850 50  0001 C CNN
F 3 "~" H 3400 2850 50  0001 C CNN
	1    3400 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2350 3400 2450
$Comp
L Device:R_Small R5
U 1 1 62C39ED5
P 3950 4050
F 0 "R5" V 4050 3900 50  0000 L CNN
F 1 "470" V 4050 4050 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 3950 4050 50  0001 C CNN
F 3 "~" H 3950 4050 50  0001 C CNN
	1    3950 4050
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 62C413A8
P 8200 4850
F 0 "J4" H 8280 4892 50  0000 L CNN
F 1 "Serial0" H 8280 4801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8200 4850 50  0001 C CNN
F 3 "~" H 8200 4850 50  0001 C CNN
	1    8200 4850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 62C41EFF
P 8200 5400
F 0 "J5" H 8280 5392 50  0000 L CNN
F 1 "Serial1 (SIM7000E)" H 8280 5301 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 8200 5400 50  0001 C CNN
F 3 "~" H 8200 5400 50  0001 C CNN
	1    8200 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4300 8000 4300
Wire Wire Line
	7800 4400 8000 4400
Text Label 7800 3900 2    50   ~ 0
5v_reg
Text Label 7800 3800 2    50   ~ 0
uP_GND
Text Label 7800 5500 2    50   ~ 0
5v_reg
Text Label 7800 5600 2    50   ~ 0
uP_GND
Wire Wire Line
	7800 5500 8000 5500
Wire Wire Line
	8000 5600 7800 5600
Text Label 7800 4950 2    50   ~ 0
uP_GND
Text Label 7800 4850 2    50   ~ 0
UART0_RX
Text Label 7800 5300 2    50   ~ 0
SIM_rx
Text Label 7800 5400 2    50   ~ 0
SIM_tx
Wire Wire Line
	7800 4750 8000 4750
Wire Wire Line
	8000 4850 7800 4850
Wire Wire Line
	7800 4950 8000 4950
Wire Wire Line
	7800 5300 8000 5300
Wire Wire Line
	8000 5400 7800 5400
Wire Wire Line
	3400 2650 3400 2700
Text Label 3700 2700 0    50   ~ 0
Batt_Sense
Wire Wire Line
	3700 2700 3650 2700
Connection ~ 3400 2700
Wire Wire Line
	3400 2700 3400 2750
Text Label 4150 3950 2    50   ~ 0
Batt_Sense
Wire Wire Line
	3600 4050 3600 3850
Wire Wire Line
	3600 3850 4250 3850
Wire Wire Line
	4250 4050 4050 4050
Wire Wire Line
	3850 4050 3600 4050
Text Label 7800 4750 2    50   ~ 0
UART0_TX
Text Label 4150 4350 2    50   ~ 0
SIM_tx
Text Label 5350 4350 0    50   ~ 0
SIM_rx
Text Label 4150 4450 2    50   ~ 0
UART0_TX
Text Label 5350 4050 0    50   ~ 0
Outage_Sense
Text Label 3500 3850 2    50   ~ 0
RST
Text Label 3500 3950 2    50   ~ 0
A0
Text Label 4200 4050 2    50   ~ 0
D0
Text Label 3500 4150 2    50   ~ 0
D5
Text Label 3500 4250 2    50   ~ 0
D6
Text Label 3500 4350 2    50   ~ 0
D7
Text Label 3500 4450 2    50   ~ 0
D8
Text Label 6000 3850 0    50   ~ 0
Tx
Text Label 6000 3950 0    50   ~ 0
Rx
Text Label 6000 4050 0    50   ~ 0
D1
Text Label 6000 4150 0    50   ~ 0
D2
Text Label 6000 4250 0    50   ~ 0
D3
Text Label 6000 4350 0    50   ~ 0
D4
Wire Wire Line
	3500 3850 3600 3850
Connection ~ 3600 3850
Wire Wire Line
	3500 3950 4250 3950
Wire Wire Line
	3500 4150 4250 4150
Wire Wire Line
	3500 4250 4250 4250
Wire Wire Line
	3500 4350 4250 4350
Wire Wire Line
	3500 4450 4250 4450
Wire Wire Line
	5250 4550 6000 4550
Wire Wire Line
	5250 4450 6000 4450
Wire Wire Line
	5250 4350 6000 4350
Wire Wire Line
	5250 4250 6000 4250
Wire Wire Line
	6000 4150 5250 4150
Wire Wire Line
	5250 3950 6000 3950
Wire Wire Line
	5250 3850 6000 3850
Wire Wire Line
	5250 4050 6000 4050
$Comp
L Connector_Generic:Conn_01x08 J6
U 1 1 62CA175D
P 9650 3900
F 0 "J6" H 9730 3892 50  0000 L CNN
F 1 "Wemos RHS" H 9730 3801 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 9650 3900 50  0001 C CNN
F 3 "~" H 9650 3900 50  0001 C CNN
	1    9650 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J7
U 1 1 62CA1CE1
P 9650 4800
F 0 "J7" H 9730 4792 50  0000 L CNN
F 1 "Wemos LHS" H 9730 4701 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 9650 4800 50  0001 C CNN
F 3 "~" H 9650 4800 50  0001 C CNN
	1    9650 4800
	1    0    0    -1  
$EndComp
Text Label 9200 3600 0    50   ~ 0
Tx
Text Label 9200 3700 0    50   ~ 0
Rx
Text Label 9200 3800 0    50   ~ 0
D1
Text Label 9200 3900 0    50   ~ 0
D2
Text Label 9200 4000 0    50   ~ 0
D3
Text Label 9200 4100 0    50   ~ 0
D4
Text Label 9200 4200 0    50   ~ 0
GND
Text Label 9200 4300 0    50   ~ 0
5v
Text Label 9200 4500 2    50   ~ 0
RST
Text Label 9200 4600 2    50   ~ 0
A0
Text Label 9200 4700 2    50   ~ 0
D0
Text Label 9200 4800 2    50   ~ 0
D5
Text Label 9200 4900 2    50   ~ 0
D6
Text Label 9200 5000 2    50   ~ 0
D7
Text Label 9200 5100 2    50   ~ 0
D8
Wire Wire Line
	9200 3600 9450 3600
Wire Wire Line
	9450 3700 9200 3700
Wire Wire Line
	9200 3800 9450 3800
Wire Wire Line
	9450 3900 9200 3900
Wire Wire Line
	9200 4000 9450 4000
Wire Wire Line
	9450 4100 9200 4100
Wire Wire Line
	9200 4200 9450 4200
Wire Wire Line
	9450 4300 9200 4300
Wire Wire Line
	9200 4500 9450 4500
Wire Wire Line
	9450 4600 9200 4600
Wire Wire Line
	9200 4700 9450 4700
Wire Wire Line
	9450 4800 9200 4800
Wire Wire Line
	9200 4900 9450 4900
Wire Wire Line
	9450 5000 9200 5000
Wire Wire Line
	9200 5100 9450 5100
Text Label 9200 5200 2    50   ~ 0
3.3v
Wire Wire Line
	9200 5200 9450 5200
Text Label 3850 4550 0    50   ~ 0
3v3_reg
Wire Wire Line
	5200 2800 5350 2800
Connection ~ 5200 2800
Wire Wire Line
	5350 2700 5350 2800
Connection ~ 5350 2800
Wire Wire Line
	5350 2800 5500 2800
Text Label 4300 3200 2    50   ~ 0
GND_wall
Text Label 5200 3200 2    50   ~ 0
uP_GND
Text Label 3500 4550 2    50   ~ 0
3.3v
Wire Wire Line
	3500 4550 4250 4550
Text Label 5350 4450 0    50   ~ 0
uP_GND
Text Label 6000 4450 0    50   ~ 0
GND
Text Label 5350 4550 0    50   ~ 0
5v
$Comp
L power:+5VA #PWR0104
U 1 1 62C1D2ED
P 6000 4550
F 0 "#PWR0104" H 6000 4400 50  0001 C CNN
F 1 "+5VA" V 6000 4750 50  0000 C CNN
F 2 "" H 6000 4550 50  0001 C CNN
F 3 "" H 6000 4550 50  0001 C CNN
	1    6000 4550
	0    1    1    0   
$EndComp
Connection ~ 7500 2600
Wire Wire Line
	7400 2600 7500 2600
Wire Wire Line
	7400 2550 7400 2600
$Comp
L My_Library:+3.3V #PWR0105
U 1 1 62C1DB68
P 7400 2550
F 0 "#PWR0105" H 7400 2400 50  0001 C CNN
F 1 "+3.3V" H 7350 2700 50  0000 L CNN
F 2 "" H 7400 2550 50  0001 C CNN
F 3 "" H 7400 2550 50  0001 C CNN
	1    7400 2550
	1    0    0    -1  
$EndComp
Connection ~ 7500 2200
Wire Wire Line
	7400 2200 7500 2200
Wire Wire Line
	7400 2150 7400 2200
$Comp
L power:+5VA #PWR0115
U 1 1 62CDFD55
P 7400 2150
F 0 "#PWR0115" H 7400 2000 50  0001 C CNN
F 1 "+5VA" H 7400 2350 50  0000 C CNN
F 2 "" H 7400 2150 50  0001 C CNN
F 3 "" H 7400 2150 50  0001 C CNN
	1    7400 2150
	1    0    0    -1  
$EndComp
Connection ~ 7500 1800
Wire Wire Line
	7400 1800 7500 1800
Wire Wire Line
	7400 1750 7400 1800
$Comp
L power:+5V #PWR0103
U 1 1 62C1C9F7
P 7400 1750
F 0 "#PWR0103" H 7400 1600 50  0001 C CNN
F 1 "+5V" H 7350 1950 50  0000 L CNN
F 2 "" H 7400 1750 50  0001 C CNN
F 3 "" H 7400 1750 50  0001 C CNN
	1    7400 1750
	1    0    0    -1  
$EndComp
Text Label 9000 2450 0    50   ~ 0
Batt-
Text Label 3400 3150 0    50   ~ 0
uP_GND
Wire Wire Line
	3400 2950 3400 3150
$Comp
L Connector:TestPoint TP7
U 1 1 62D3A80A
P 3650 2650
F 0 "TP7" H 3708 2722 50  0000 L CNN
F 1 "Battery_Sense" H 3708 2677 50  0001 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.50mm_Drill1.0mm_LowProfile" H 3850 2650 50  0001 C CNN
F 3 "~" H 3850 2650 50  0001 C CNN
	1    3650 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2650 3650 2700
Connection ~ 3650 2700
Wire Wire Line
	3650 2700 3400 2700
$EndSCHEMATC
