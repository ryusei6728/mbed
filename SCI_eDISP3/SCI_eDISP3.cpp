#include <SCI_eDISP3/SCI_eDISP3.h>

//-----------------------------------------------------------------------------------------------
//  Setting data
//-----------------------------------------------------------------------------------------------

#define STATION_NO 1                	// CAR UNIT station no

#define RS232_BAUD 			115200      // RS232 baud late
#define DEF_COLOR 			18          // Default font color 18:Green 23:White
#define PRINT_BUFFER_LEN 	45         	// eDisp printf buffer length ( 1-line 39-char + CR,LF)

//--------------------------------------------------
// FEP UART initialize 
//--------------------------------------------------
SCI_eDISP3::SCI_eDISP3(PinName tx, PinName rx) : m_sci(tx, rx)
{
    m_sci.baud(RS232_BAUD);
    m_sci.format(8,Serial::None,1);     // (bits,parity,stop_bit)
    m_sci.attach(this, &SCI_eDISP3::isr_receive, Serial::RxIrq);
    def_color = DEF_COLOR;              // default font color set

} 

//--------------------------------------------------
//  SEND initialize message
//--------------------------------------------------
void SCI_eDISP3::send_init(void){

    // Display setting
	SCI_eDISP3::clear();                // clear display
    wait_ms(100);                       // wait clear
    m_sci.printf("\x1b[%dm",def_color); // font color set
    m_sci.printf("\x1b@21Z");           // disable auto LF
    m_sci.printf("\x1b[>5h");           // disable cursor 
    m_sci.printf("\x1b@23Z");           // disable scroll





//    m_sci.printf("YHA Evaluation Board v050\r\n");
//    m_sci.printf("Station No [%03d]\r\n",STATION_NO);
//    m_sci.printf("----------------------------------------\r\n");
//    m_sci.printf("\r\n\r\n");
//    m_sci.printf("----------------------------------------\r\n");
}    


//--------------------------------------------------
// eDISP clear
//--------------------------------------------------
void SCI_eDISP3::clear(){
    
    m_sci.printf("\x1b@0Z");
    wait_ms(100);
}    

//--------------------------------------------------
// eDISP clear line
//--------------------------------------------------
void SCI_eDISP3::clear_line(){

    m_sci.printf("\x1b[0K");

}    




//--------------------------------------------------
// eDISP locate
//--------------------------------------------------
void SCI_eDISP3::locate(char y,char x){
    
    m_sci.printf("\x1b[%d;%dH",y,x);

}    

//--------------------------------------------------
// eDISP locate message
//--------------------------------------------------
void SCI_eDISP3::locate_msg(char y,char x,char msg[]){

    SCI_eDISP3::locate(y,x);
    SCI_eDISP3::send_msg(msg);

}    

/*------------------------------------------------------------------------
eDISP font command
Format
  0:initial		 1:bold		4:Uline		5:Blink		7:BG-invert

Font Color
 17:red		18:green	19:yellow	20:blue		21:purple	22:water	23:white

BG Color
 40:black	41:red		42:green	43:yellow	44:blue		45:purple	46:water
 47:white	49:Transparent
-------------------------------------------------------------------------*/
void SCI_eDISP3::font(char cmd){

    m_sci.printf("\x1b[%dm",cmd);

}    
void SCI_eDISP3::font(char cmd1,char cmd2){

    m_sci.printf("\x1b[%d;%dm",cmd1,cmd2);

}    
void SCI_eDISP3::font(char cmd1,char cmd2,char cmd3){

    m_sci.printf("\x1b[%d;%d;%dm",cmd1,cmd2,cmd3);

}    

//--------------------------------------------------
//  eDISP font color reset
//--------------------------------------------------
void SCI_eDISP3::color_reset(){

    m_sci.printf("\x1b[%dm",def_color);

}


//--------------------------------------------------
// eDISP printf redirect
//--------------------------------------------------
void SCI_eDISP3::printf(const char format[],...){
    char buf[PRINT_BUFFER_LEN];

    va_list ap;
    va_start(ap,format);
    vsprintf(buf,format,ap);
    va_end(ap);

    m_sci.printf(buf);
}

//--------------------------------------------------
// eDISP printf redirect & locate & font color
//--------------------------------------------------
void SCI_eDISP3::print_locate(char y, char x, char color,const char format[],...){

    char buf[PRINT_BUFFER_LEN];

    SCI_eDISP3::locate(y,x);
    SCI_eDISP3::font(color);

    // print eDISP
    va_list ap;
    va_start(ap,format);
    vsprintf(buf,format,ap);
    va_end(ap);

    m_sci.printf(buf);
    SCI_eDISP3::color_reset();

}

//--------------------------------------------------
// eDISP printf insert
// 指定した行から下を１段下にスクロールし、formatで指定した文字列を挿入
//--------------------------------------------------
void SCI_eDISP3::print_insert(char line,char color,const char format[],...){

    char buf[PRINT_BUFFER_LEN];

    SCI_eDISP3::locate(line,1);     // locate cursor
    m_sci.printf("\x1b[1L");         // insert line
    SCI_eDISP3::font(color);

    // print eDISP
    va_list ap;
    va_start(ap,format);
    vsprintf(buf,format,ap);
    va_end(ap);

    m_sci.printf(buf);
    SCI_eDISP3::color_reset();

}


//--------------------------------------------------
// eDISP put char
//--------------------------------------------------
void SCI_eDISP3::put_char(char c){

    m_sci.putc(c);
}


//--------------------------------------------------
//  eDISP send message + \r\n string
//--------------------------------------------------
void SCI_eDISP3::send_msg_ln(char msg[]){

    m_sci.printf("%s\r\n",msg);

}
//--------------------------------------------------
//  eDISP send message string
//--------------------------------------------------
void SCI_eDISP3::send_msg(char msg[]){

    m_sci.printf("%s",msg);

}


//--------------------------------------------------
// SCI receive interrupt
// * dummy function at eDISP 
//--------------------------------------------------
void SCI_eDISP3::isr_receive(){
    char buf;

    while(m_sci.readable()){        
        buf = m_sci.getc();         // get char
        m_sci.putc(buf);            // send eDISP char
    }

}
