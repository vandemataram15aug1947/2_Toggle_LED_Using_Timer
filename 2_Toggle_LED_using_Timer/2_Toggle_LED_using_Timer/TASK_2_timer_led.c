
//////////////// METHOD-2  ///////////////////////////
#include "F28x_Project.h"
#define LED1 GpioDataRegs.GPBDAT.bit.GPIO34
#define LED2 GpioDataRegs.GPADAT.bit.GPIO31

/////////  Vande  //////////
void main(){
    //Initialization of System Control
    InitSysCtrl();
    //Initialization of General Purpose Input Output Pins
    InitGpio();
    EALLOW;

    /////////  Vande  //////////

    //Configure GPIO34 and  GPIO31 as an Output
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    GpioDataRegs.GPASET.bit.GPIO31 = 0; //Initially BLUE LED will turn ON
    GpioDataRegs.GPBSET.bit.GPIO34 = 0; //Initially RED LED will turn OFF
    EDIS;
    //Initialization of CPU_Timers
    InitCpuTimers();

    /////////  Vande  //////////

    //Configure Timer0 for Delay Generation;
    CpuTimer0Regs.PRD.all = 200000000; // 2 Second Of Delay
    CpuTimer0Regs.TCR.bit.TSS = 1;      //Timer in stop state
    CpuTimer0Regs.TCR.bit.TRB = 1;    // reset Timer
    CpuTimer0Regs.TCR.bit.TIE = 0;    // Disable Timer Interrupt
    CpuTimer0Regs.TCR.bit.FREE = 1;   //Free Run of timer
    CpuTimer0Regs.TCR.bit.SOFT = 1;  //Disable Software Control
    //Start Timer0
    CpuTimer0Regs.TCR.bit.TSS = 0;
    while(1){

        /////////  Vande  //////////

        LED1=~LED1;
        //wait for timer to expire
        while(CpuTimer0Regs.TCR.bit.TIF==0);
        //Clear timer flag
        CpuTimer0Regs.TCR.bit.TIF=1;

    }

}

////////////////////// METHOD -2  //////////////////////////
// Device Header file and Examples Include File
/*
#include "F28x_Project.h"

// function prototyping
void Timer_Delay(void);
// Connect LED_1 to GPIO 38.
#define LED_1 GpioDataRegs.GPBDAT.bit.GPIO34


/////////  Vande  //////////

void main(void)
{
    // Initialization of system control register
    InitSysCtrl();
    // Initialization of general purpose Input Output Pins
    InitGpio();


    // Initialize LED_1 as output
    EALLOW;

    /////////  Vande  //////////

    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    // Use GPIO 38 as an Output
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    EDIS;

    while(1)
    {
        /////////  Vande  //////////
        LED_1=1;
        //generate delay using timer
        Timer_Delay();
        LED_1=0;
        Timer_Delay();

    }
}

/////////  Vande  //////////
void Timer_Delay()
{
    // Initialization of Cpu Timers
    InitCpuTimers();
    // Configure Timer 0 with a period of DELAY 100 milliseconds,with system clock frequency of 200MHz
    ConfigCpuTimer(&CpuTimer0, 200, 100000);
    // Start Timer 0
    StartCpuTimer0();
    // Wait for timer to over flow
    while (CpuTimer0Regs.TCR.bit.TIF == 0);
}
 */

