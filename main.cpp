/* ************************************************
 *	総研新人教育　LAP　Time　Monitor
 *	Ver　1.00 = 2017.02.08
 * ************************************************ */
/*　**********************************
		Include Function
********************************** */
#include "_Headerl.h"


/*　**********************************
		Emergency Function
********************************** */
void Emergency();
void Emergency(){

// static int reset_f = 0;	//RESET信号用フラグ

	// DRV-IC エラー判断
	if( _FAULT_U 	== NG)		{	Err = Err | ERR_DRV_U;	ERR_LED_FU = LED_ON;}
	if( _FAULT_V 	== NG)		{	Err = Err | ERR_DRV_V;	ERR_LED_FV = LED_ON;}
	if( _FAULT_W 	== NG)		{	Err = Err | ERR_DRV_W;	ERR_LED_FW = LED_ON;}

	// PM温度異常 判断 EMP_100:100℃以上
	if( Rtd_u_time < TEMP_100)	{	Err = Err | ERR_TEMP_U;	ERR_LED_RU = LED_ON;}
	if( Rtd_u_time < TEMP_100)	{	Err = Err | ERR_TEMP_V;	ERR_LED_RV = LED_ON;}
	if( Rtd_u_time < TEMP_100)	{	Err = Err | ERR_TEMP_W;	ERR_LED_RW = LED_ON;}

	if( Err != 0){			// 異常発生時
		FAULT = NG;			//
		mLed = mLed | 0b0001;
	}

/*
	if( RESET == OFF){		// RESET OFF
		reset_f = 0;
	}
	else{					// RESET ON
		if(reset_f == 0){	// RESET押された一回のみ、RESET
			reset_f = 1;
			Err = 0;
			FAULT = OK;
			ERR_LED_FU = LED_OFF;
			ERR_LED_FV = LED_OFF;
			ERR_LED_FW = LED_OFF;
			ERR_LED_RU = LED_OFF;
			ERR_LED_RV = LED_OFF;
			ERR_LED_RW = LED_OFF;
		}
	}
*/
}
/*　**********************************
	Timer0 Interrupt Function
********************************** */
#define	TIMER0_TIME	5000	// x uS

void time0_int();	// 5ms_JOB
void time0_int(){

// job制御
const int CNT_100mS	= (100000	/	TIMER0_TIME);
const int CNT_1S	= (1000000	/	TIMER0_TIME);

static unsigned short job_1s_cnt = 0;
static unsigned short job_100mS_cnt = 0;

	Emergency();

/*
	Data0 	= 0;	Data1 	= 0;	Data2 	= 0;	Data3 	= 0;	Data4	= 0;	Data5 	= 0;
	Data6 	= 0;	Data7 	= 0;	Data8 	= 0;	Data9 	= 0;	Data10	= 0;	Data11	= 0;
*/
	// job_100mS
	INCREMENT(job_100mS_cnt,CNT_100mS);
	if(job_100mS_cnt == 0)	{ Job_100m = 1;}
	// job_1S
	INCREMENT( job_1s_cnt , CNT_1S );
	if(job_1s_cnt == 0)		{ Job_1s = 1; }
// ************************************

}

/*　**********************************
	Measurement of Time Function
********************************** */

void ru_int();
void ru_int(){
	Rtd_u_time = RTD_U_TIME.read_us();
	RTD_U_TIME.reset();
}

void rv_int();
void rv_int(){
	Rtd_v_time = RTD_V_TIME.read_us();
	RTD_V_TIME.reset();
}

void rw_int();
void rw_int(){
	Rtd_w_time = RTD_W_TIME.read_us();
	RTD_W_TIME.reset();
}

/*　**********************************
		Initialize Function
********************************** */
// Initialize Function
void initialize();
void initialize()
{
	// mbed LED1-4

	FAULT 		= OK;			// OK：正常	NG:異常
	mLed = 0b0000;		// 点灯:0b1111;

	wait(0.2);		//起動準備
	mLed = 0b1000;		// 点灯:0b1111;
	wait(0.2);		//起動準備
	mLed = 0b0100;		// 点灯:0b1111;
	wait(0.2);		//起動準備
	mLed = 0b0010;		// 点灯:0b1111;
	wait(0.2);		//起動準備
	mLed = 0b0001;		// 点灯:0b1111;
	wait(0.2);		//起動準備
	mLed = 0b0000;		// 点灯:0b1111;

	ERR_LED_FU	= LED_ON;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_RU	= LED_ON;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_FV	= LED_ON;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_RV	= LED_ON;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_FW	= LED_ON;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_RW	= LED_ON;		// LED_ON：点灯 LED_OFF：消灯
	wait(0.3);		//起動準備

	ERR_LED_FU	= LED_OFF;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_RU	= LED_OFF;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_FV	= LED_OFF;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_RV	= LED_OFF;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_FW	= LED_OFF;		// LED_ON：点灯 LED_OFF：消灯
	ERR_LED_RW	= LED_OFF;		// LED_ON：点灯 LED_OFF：消灯

	Err = 0;


	// Digital OUT MODE Buzzer
//	Buzzer.mode(OpenDrain);

	// eDisp3 Initialize
//	Disp.send_init();
//	Disp_base_print();


	// Logger Initialize
//	PC_Logger.baud(115200);
//	PC_Logger.attach(&STOP_MODE);

	//	Timer Initialize
	Time0.attach_us(&time0_int, TIMER0_TIME);

	RTD_U.rise(&ru_int);
	RTD_V.rise(&rv_int);
	RTD_W.rise(&rw_int);

	RTD_U_TIME.start();
	RTD_V_TIME.start();
	RTD_W_TIME.start();
}

/*　**********************************
			Main Function
********************************** */
int main()
{

    initialize();
	while(1){
		if(Job_100m == 1){			//	100ms処理 *****************************
			Job_100m = 0;
			//Logger_print();
		}							// 100ms END *****************************

		if(Job_1s	== 1){			//	1S処理 ********************************
			Job_1s = 0;

			mLed = mLed ^ 0b1000;		// LED1(3bit)を反転

			//Disp_print();
		}							// 1S処理 END ******************************
//		if(FAULT == NG ){
//			mLed = mLed | 0b0001;
//		}
//		else{
//			mLed = mLed & ~0b0001;
//		}
		if(Err != 0 ){
			mLed = mLed | 0b0010;
		}

	}
}
