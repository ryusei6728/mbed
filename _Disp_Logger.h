
#include "mbed.h"						//

extern long Data0,Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10,Data11,Data12;

void Disp_base_print(void);				//
void Disp_print(void);					//




//	□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■ □　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■
//	****************************
//	Disp ベース表示 起動時
//	****************************

void Disp_base_print(void){
	//　Disp ベース表示

	Disp.print_locate(	0,	2,22,"Line Tracecar Parameter DISP");
	Disp.print_locate(	2,	2,22,"    Data00 =");
	Disp.print_locate(	3,	2,22,"    Data01 =");
	Disp.print_locate(	4,	2,22,"    Data02 =");
	Disp.print_locate(	5,	2,22,"    Data03 =");
	Disp.print_locate(	6,	2,22,"    Data04 =");
	Disp.print_locate(	7,	2,22,"    Data05 =");
	Disp.print_locate(	8,	2,22,"    Data06 =");
	Disp.print_locate(	9,	2,22,"    Data07 =");
	Disp.print_locate(	10,	2,22,"    Data08 =");
	Disp.print_locate(	11,	2,22,"    Data09 =");
	Disp.print_locate(	12,	2,22,"    Data10 =");
	Disp.print_locate(	13,	2,22,"    Data11 =");
	Disp.print_locate(	14,	2,22,"    Data12 =");

}

//	□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■ □　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■
//	****************************
//	Disp表示 1SEC処理
//	****************************
void Disp_print(void){
	Disp.print_locate(	2,	15,19,"%+06d",	Data0	);		// data0
	Disp.print_locate(	3,	15,19,"%+06d",	Data1	);		// data1
	Disp.print_locate(	4,	15,19,"%+06d",	Data2	);		// data2
	Disp.print_locate(	5,	15,19,"%+06d",	Data3	);		// data3
	Disp.print_locate(	6,	15,19,"%+06d",	Data4	);		// data4
	Disp.print_locate(	7,	15,19,"%+06d",	Data5	);		// data5
	Disp.print_locate(	8,	15,19,"%+06d",	Data6	);		// data6
	Disp.print_locate(	9,	15,19,"%+06d",	Data7	);		// data7
	Disp.print_locate(	10,	15,19,"%+06d",	Data8	);		// data8
	Disp.print_locate(	11,	15,19,"%+06d",	Data9	);		// data9
	Disp.print_locate(	12,	15,19,"%+06d",	Data10	);		// data10
	Disp.print_locate(	13,	15,19,"%+06d",	Data11	);		// data11
	Disp.print_locate(	14,	15,19,"%+06d",	Data12	);		// data12
}

//	□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■ □　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■


//	****************************
//	LOGGER送信 100ms処理
//	****************************

char DT[] = "DT";
#define	DATA_N		2		//送信データ数
char AD[] = "AD";
//	□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■ □　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■　□　■
void Logger_print(void){

	PC_Logger.printf("%02s%02d%04d%04d%04d%04d%04d%04d%04d%04d%04d%04d\r\n",DT	//アナログデータ送信
					,DATA_N	//送信データ数
					,Log0	,Log1);	//データ送信

}



