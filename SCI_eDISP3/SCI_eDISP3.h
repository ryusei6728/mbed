#ifndef MBED_SCI_eDISP3_H
#define MBED_SCI_eDISP3_H

#include "mbed.h"
//#include "def_type.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"


class SCI_eDISP3{

    public:
		SCI_eDISP3(PinName tx, PinName rx);

		// function
        void send_init(void);

        void clear(void);
        
        void font(char);
        void font(char,char);
        void font(char,char,char);
        void color_reset(void);

        void printf(const char format[],...);
        void print_locate(char,char,char,const char format[],...);
        void print_insert(char,char,const char format[],...);

        // variables
        int def_color;						// default font color
        


    private:
        // module
        Serial m_sci;                       // Peripheral

		// function
        void isr_receive();					// Rx interrupt

        void put_char(char);
        void clear_line(void);
        void locate(char , char);
        void locate_msg(char,char,char msg[]);

        void send_msg(char msg[]);
        void send_msg_ln(char msg[]);

        int RS232_BAUD;

    protected:

}; //end class

#endif
