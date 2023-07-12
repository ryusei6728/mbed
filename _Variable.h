//	****************************
//	変数定義
//	****************************


// DATA表示用
long Data0,Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10,Data11,Data12;
//
short Log0,Log1;

//　Jobフラグ
char Job_100m = 0;
char Job_1s = 0;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 温度計測用 周期時間
int	Rtd_u_time = 0;
int	Rtd_v_time = 0;
int	Rtd_w_time = 0;

int	Err = 0;
/*
0bit:DRV-U_ERR
1bit:TEMP_U_ERR
2bit:DRV-V_ERR
3bit:TEMP_V_ERR
4bit:DRV-W_ERR
5bit:TEMP_W_ERR
6bit:none
7bit:none
*/
