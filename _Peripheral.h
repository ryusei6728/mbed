/*　**********************************
		mbed Peripheral
********************************** */


//SCI_eDISP3	Disp(p9, NC);				//eDisp3用設定
//Serial		PC_Logger(USBTX,USBRX);			//PCロガー用　bluetooth接続

/*
SCI_eDISP3	Disp(NC, NC);				//eDisp3用設定
Serial		PC_Logger(NC,NC);			//PCロガー用　bluetooth接続
*/


BusOut		mLed(LED1,LED2,LED3,LED4);	//	mbed本体　LED設定

Ticker Time0;							//Timer割り込み用



/*
// MC-I/F ver1.0基板
DigitalIn	RESET		(p14);			// High：RESET

DigitalIn	_FAULT_U	(p16);			//High：正常 Low:異常
DigitalIn	_FAULT_V	(p18);			//High：正常 Low:異常
DigitalIn	_FAULT_W	(p20);			//High：正常 Low:異常

InterruptIn RTD_U		(p15);			//
InterruptIn RTD_V		(p17);			//
InterruptIn RTD_W		(p13);			//

*/
// MC-I/F ver2.0基板
DigitalIn	_FAULT_U	(p16);			//High：正常 Low:異常
DigitalIn	_FAULT_V	(p17);			//High：正常 Low:異常
DigitalIn	_FAULT_W	(p18);			//High：正常 Low:異常

InterruptIn RTD_U		(p13);			//
InterruptIn RTD_V		(p14);			//
InterruptIn RTD_W		(p15);			//

/* NTC Temperature vs. RTD Output Frequency
NTC Temperature (°C) 	NTC Resistance (Ω) 	Frequency Output(kHz)			Time(us)
			0					13,491						4.6					217
			25					4,700						10.3				97
			50					1,928						17.1				58
			75					898							22.8				44
			100					464							26.4				38
			125					260							28.3				35
			150					156							29.5				34
			175					99							30.1				33
*/

Timer 		RTD_U_TIME;
Timer 		RTD_V_TIME;
Timer 		RTD_W_TIME;

DigitalOut FAULT		(p27);		// High:正常 Low:異常

DigitalOut ERR_LED_FU	(p26);		// High:点灯 Low:消灯
DigitalOut ERR_LED_RU	(p25);		// High:点灯 Low:消灯
DigitalOut ERR_LED_FV	(p24);		// High:点灯 Low:消灯
DigitalOut ERR_LED_RV	(p23);		// High:点灯 Low:消灯
DigitalOut ERR_LED_FW	(p22);		// High:点灯 Low:消灯
DigitalOut ERR_LED_RW	(p21);		// High:点灯 Low:消灯






