# 1 "newmain.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "newmain.c" 2
# 13 "newmain.c"
#pragma config FOSC = INTOSCIO
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config IOSCFS = 8MHZ
#pragma config BOREN = OFF



# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\xc.h" 1 3
# 18 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\xc8debug.h" 1 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\xc8debug.h" 3
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 24 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\xc.h" 2 3
# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\builtins.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 1 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed char int8_t;






typedef signed int int16_t;







typedef __int24 int24_t;







typedef signed long int int32_t;
# 52 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint8_t;





typedef unsigned int uint16_t;






typedef __uint24 uint24_t;






typedef unsigned long int uint32_t;
# 88 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_least8_t;







typedef signed int int_least16_t;
# 109 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_least24_t;
# 118 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed long int int_least32_t;
# 136 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_least8_t;






typedef unsigned int uint_least16_t;
# 154 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_least24_t;







typedef unsigned long int uint_least32_t;
# 181 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_fast8_t;






typedef signed int int_fast16_t;
# 200 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_fast24_t;







typedef signed long int int_fast32_t;
# 224 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
# 240 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_fast24_t;






typedef unsigned long int uint_fast32_t;
# 268 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef int32_t intmax_t;
# 282 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef uint32_t uintmax_t;






typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 5 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\builtins.h" 2 3


#pragma intrinsic(__nop)
extern void __nop(void);


#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(uint32_t);
# 25 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\xc.h" 2 3



# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic.h" 1 3




# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\htc.h" 1 3



# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\xc.h" 1 3
# 5 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\htc.h" 2 3
# 6 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic.h" 2 3







# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic_chip_select.h" 1 3
# 184 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic_chip_select.h" 3
# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 1 3
# 45 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\__at.h" 1 3
# 46 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 2 3







extern volatile unsigned char INDF __attribute__((address(0x000)));

__asm("INDF equ 00h");




extern volatile unsigned char TMR0 __attribute__((address(0x001)));

__asm("TMR0 equ 01h");




extern volatile unsigned char PCL __attribute__((address(0x002)));

__asm("PCL equ 02h");




extern volatile unsigned char STATUS __attribute__((address(0x003)));

__asm("STATUS equ 03h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned RP :2;
        unsigned IRP :1;
    };
    struct {
        unsigned :5;
        unsigned RP0 :1;
        unsigned RP1 :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0x003)));
# 160 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char FSR __attribute__((address(0x004)));

__asm("FSR equ 04h");




extern volatile unsigned char GPIO __attribute__((address(0x005)));

__asm("GPIO equ 05h");


extern volatile unsigned char PORTA __attribute__((address(0x005)));

__asm("PORTA equ 05h");


typedef union {
    struct {
        unsigned GP0 :1;
        unsigned GP1 :1;
        unsigned GP2 :1;
        unsigned GP3 :1;
        unsigned GP4 :1;
        unsigned GP5 :1;
    };
    struct {
        unsigned GPIO0 :1;
        unsigned GPIO1 :1;
        unsigned GPIO2 :1;
        unsigned GPIO3 :1;
        unsigned GPIO4 :1;
        unsigned GPIO5 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
    };
} GPIObits_t;
extern volatile GPIObits_t GPIObits __attribute__((address(0x005)));
# 296 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
typedef union {
    struct {
        unsigned GP0 :1;
        unsigned GP1 :1;
        unsigned GP2 :1;
        unsigned GP3 :1;
        unsigned GP4 :1;
        unsigned GP5 :1;
    };
    struct {
        unsigned GPIO0 :1;
        unsigned GPIO1 :1;
        unsigned GPIO2 :1;
        unsigned GPIO3 :1;
        unsigned GPIO4 :1;
        unsigned GPIO5 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
    };
} PORTAbits_t;
extern volatile PORTAbits_t PORTAbits __attribute__((address(0x005)));
# 417 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char PCLATH __attribute__((address(0x00A)));

__asm("PCLATH equ 0Ah");




extern volatile unsigned char INTCON __attribute__((address(0x00B)));

__asm("INTCON equ 0Bh");


typedef union {
    struct {
        unsigned GPIF :1;
        unsigned INTF :1;
        unsigned TMR0IF :1;
        unsigned GPIE :1;
        unsigned INTE :1;
        unsigned TMR0IE :1;
        unsigned PEIE :1;
        unsigned GIE :1;
    };
    struct {
        unsigned :2;
        unsigned T0IF :1;
        unsigned :2;
        unsigned T0IE :1;
    };
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __attribute__((address(0x00B)));
# 502 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char PIR1 __attribute__((address(0x00C)));

__asm("PIR1 equ 0Ch");


typedef union {
    struct {
        unsigned TMR1IF :1;
        unsigned TMR2IF :1;
        unsigned :1;
        unsigned C1IF :1;
        unsigned :1;
        unsigned ECCPIF :1;
        unsigned ADIF :1;
    };
    struct {
        unsigned T1IF :1;
        unsigned T2IF :1;
        unsigned :1;
        unsigned CMIF :1;
        unsigned :1;
        unsigned CCP1IF :1;
    };
} PIR1bits_t;
extern volatile PIR1bits_t PIR1bits __attribute__((address(0x00C)));
# 576 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned short TMR1 __attribute__((address(0x00E)));

__asm("TMR1 equ 0Eh");




extern volatile unsigned char TMR1L __attribute__((address(0x00E)));

__asm("TMR1L equ 0Eh");




extern volatile unsigned char TMR1H __attribute__((address(0x00F)));

__asm("TMR1H equ 0Fh");




extern volatile unsigned char T1CON __attribute__((address(0x010)));

__asm("T1CON equ 010h");


typedef union {
    struct {
        unsigned TMR1ON :1;
        unsigned TMR1CS :1;
        unsigned nT1SYNC :1;
        unsigned T1OSCEN :1;
        unsigned T1CKPS :2;
        unsigned TMR1GE :1;
        unsigned T1GINV :1;
    };
    struct {
        unsigned :4;
        unsigned T1CKPS0 :1;
        unsigned T1CKPS1 :1;
    };
} T1CONbits_t;
extern volatile T1CONbits_t T1CONbits __attribute__((address(0x010)));
# 668 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char TMR2 __attribute__((address(0x011)));

__asm("TMR2 equ 011h");




extern volatile unsigned char T2CON __attribute__((address(0x012)));

__asm("T2CON equ 012h");


typedef union {
    struct {
        unsigned T2CKPS :2;
        unsigned TMR2ON :1;
        unsigned TOUTPS :4;
    };
    struct {
        unsigned T2CKPS0 :1;
        unsigned T2CKPS1 :1;
        unsigned T2ON :1;
        unsigned TOUTPS0 :1;
        unsigned TOUTPS1 :1;
        unsigned TOUTPS2 :1;
        unsigned TOUTPS3 :1;
    };
} T2CONbits_t;
extern volatile T2CONbits_t T2CONbits __attribute__((address(0x012)));
# 751 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned short CCPR1 __attribute__((address(0x013)));

__asm("CCPR1 equ 013h");




extern volatile unsigned char CCPR1L __attribute__((address(0x013)));

__asm("CCPR1L equ 013h");




extern volatile unsigned char CCPR1H __attribute__((address(0x014)));

__asm("CCPR1H equ 014h");




extern volatile unsigned char CCP1CON __attribute__((address(0x015)));

__asm("CCP1CON equ 015h");


typedef union {
    struct {
        unsigned CCP1M :4;
        unsigned DCB :2;
        unsigned :1;
        unsigned P1M :1;
    };
    struct {
        unsigned CCP1M0 :1;
        unsigned CCP1M1 :1;
        unsigned CCP1M2 :1;
        unsigned CCP1M3 :1;
        unsigned DC1B0 :1;
        unsigned DC1B1 :1;
    };
} CCP1CONbits_t;
extern volatile CCP1CONbits_t CCP1CONbits __attribute__((address(0x015)));
# 843 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char PWM1CON __attribute__((address(0x016)));

__asm("PWM1CON equ 016h");


typedef union {
    struct {
        unsigned PDC :7;
        unsigned PRSEN :1;
    };
    struct {
        unsigned PDC0 :1;
        unsigned PDC1 :1;
        unsigned PDC2 :1;
        unsigned PDC3 :1;
        unsigned PDC4 :1;
        unsigned PDC5 :1;
        unsigned PDC6 :1;
    };
} PWM1CONbits_t;
extern volatile PWM1CONbits_t PWM1CONbits __attribute__((address(0x016)));
# 913 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char ECCPAS __attribute__((address(0x017)));

__asm("ECCPAS equ 017h");


typedef union {
    struct {
        unsigned PSSBD :2;
        unsigned PSSAC :2;
        unsigned ECCPAS :3;
        unsigned ECCPASE :1;
    };
    struct {
        unsigned PSSBD0 :1;
        unsigned PSSBD1 :1;
        unsigned PSSAC0 :1;
        unsigned PSSAC1 :1;
        unsigned ECCPAS0 :1;
        unsigned ECCPAS1 :1;
        unsigned ECCPAS2 :1;
    };
} ECCPASbits_t;
extern volatile ECCPASbits_t ECCPASbits __attribute__((address(0x017)));
# 995 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char VRCON __attribute__((address(0x019)));

__asm("VRCON equ 019h");


typedef union {
    struct {
        unsigned VR :4;
        unsigned FBREN :1;
        unsigned VRR :1;
        unsigned :1;
        unsigned C1VREN :1;
    };
    struct {
        unsigned VR0 :1;
        unsigned VR1 :1;
        unsigned VR2 :1;
        unsigned VR3 :1;
        unsigned VP6EN :1;
        unsigned :2;
        unsigned CMVREN :1;
    };
    struct {
        unsigned :4;
        unsigned FVREN :1;
    };
} VRCONbits_t;
extern volatile VRCONbits_t VRCONbits __attribute__((address(0x019)));
# 1082 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char CMCON0 __attribute__((address(0x01A)));

__asm("CMCON0 equ 01Ah");


typedef union {
    struct {
        unsigned C1CH :1;
        unsigned :1;
        unsigned C1R :1;
        unsigned :1;
        unsigned C1POL :1;
        unsigned C1OE :1;
        unsigned C1OUT :1;
        unsigned C1ON :1;
    };
    struct {
        unsigned C1CH0 :1;
        unsigned :1;
        unsigned CMR :1;
        unsigned :1;
        unsigned CMPOL :1;
        unsigned CMOE :1;
        unsigned COUT :1;
        unsigned CMON :1;
    };
    struct {
        unsigned CMCH :1;
    };
} CMCON0bits_t;
extern volatile CMCON0bits_t CMCON0bits __attribute__((address(0x01A)));
# 1182 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char CMCON1 __attribute__((address(0x01C)));

__asm("CMCON1 equ 01Ch");


typedef union {
    struct {
        unsigned C1SYNC :1;
        unsigned T1GSS :1;
        unsigned :1;
        unsigned C1HYS :1;
        unsigned T1ACS :1;
    };
    struct {
        unsigned CMSYNC :1;
        unsigned :2;
        unsigned CMHYS :1;
    };
} CMCON1bits_t;
extern volatile CMCON1bits_t CMCON1bits __attribute__((address(0x01C)));
# 1236 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char ADRESH __attribute__((address(0x01E)));

__asm("ADRESH equ 01Eh");




extern volatile unsigned char ADCON0 __attribute__((address(0x01F)));

__asm("ADCON0 equ 01Fh");


typedef union {
    struct {
        unsigned ADON :1;
        unsigned GO_nDONE :1;
        unsigned CHS :3;
        unsigned :1;
        unsigned VCFG :1;
        unsigned ADFM :1;
    };
    struct {
        unsigned :1;
        unsigned GO :1;
        unsigned CHS0 :1;
        unsigned CHS1 :1;
        unsigned CHS2 :1;
    };
    struct {
        unsigned :1;
        unsigned nDONE :1;
    };
    struct {
        unsigned :1;
        unsigned GO_DONE :1;
    };
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __attribute__((address(0x01F)));
# 1333 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char OPTION_REG __attribute__((address(0x081)));

__asm("OPTION_REG equ 081h");


typedef union {
    struct {
        unsigned PS :3;
        unsigned PSA :1;
        unsigned T0SE :1;
        unsigned T0CS :1;
        unsigned INTEDG :1;
        unsigned nGPPU :1;
    };
    struct {
        unsigned PS0 :1;
        unsigned PS1 :1;
        unsigned PS2 :1;
    };
} OPTION_REGbits_t;
extern volatile OPTION_REGbits_t OPTION_REGbits __attribute__((address(0x081)));
# 1403 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char TRISIO __attribute__((address(0x085)));

__asm("TRISIO equ 085h");


extern volatile unsigned char TRISA __attribute__((address(0x085)));

__asm("TRISA equ 085h");


typedef union {
    struct {
        unsigned TRISIO0 :1;
        unsigned TRISIO1 :1;
        unsigned TRISIO2 :1;
        unsigned TRISIO3 :1;
        unsigned TRISIO4 :1;
        unsigned TRISIO5 :1;
    };
} TRISIObits_t;
extern volatile TRISIObits_t TRISIObits __attribute__((address(0x085)));
# 1456 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
typedef union {
    struct {
        unsigned TRISIO0 :1;
        unsigned TRISIO1 :1;
        unsigned TRISIO2 :1;
        unsigned TRISIO3 :1;
        unsigned TRISIO4 :1;
        unsigned TRISIO5 :1;
    };
} TRISAbits_t;
extern volatile TRISAbits_t TRISAbits __attribute__((address(0x085)));
# 1501 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char PIE1 __attribute__((address(0x08C)));

__asm("PIE1 equ 08Ch");


typedef union {
    struct {
        unsigned TMR1IE :1;
        unsigned TMR2IE :1;
        unsigned :1;
        unsigned C1IE :1;
        unsigned :1;
        unsigned ECCPIE :1;
        unsigned ADIE :1;
    };
    struct {
        unsigned T1IE :1;
        unsigned T2IE :1;
        unsigned :1;
        unsigned CMIE :1;
        unsigned :1;
        unsigned CCP1IE :1;
    };
} PIE1bits_t;
extern volatile PIE1bits_t PIE1bits __attribute__((address(0x08C)));
# 1575 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char PCON __attribute__((address(0x08E)));

__asm("PCON equ 08Eh");


typedef union {
    struct {
        unsigned nBOR :1;
        unsigned nPOR :1;
    };
    struct {
        unsigned nBOD :1;
    };
} PCONbits_t;
extern volatile PCONbits_t PCONbits __attribute__((address(0x08E)));
# 1609 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char OSCTUNE __attribute__((address(0x090)));

__asm("OSCTUNE equ 090h");


typedef union {
    struct {
        unsigned TUN :5;
    };
    struct {
        unsigned TUN0 :1;
        unsigned TUN1 :1;
        unsigned TUN2 :1;
        unsigned TUN3 :1;
        unsigned TUN4 :1;
    };
} OSCTUNEbits_t;
extern volatile OSCTUNEbits_t OSCTUNEbits __attribute__((address(0x090)));
# 1661 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char PR2 __attribute__((address(0x092)));

__asm("PR2 equ 092h");




extern volatile unsigned char APFCON __attribute__((address(0x093)));

__asm("APFCON equ 093h");


typedef union {
    struct {
        unsigned P1ASEL :1;
        unsigned P1BSEL :1;
        unsigned :2;
        unsigned T1GSEL :1;
    };
} APFCONbits_t;
extern volatile APFCONbits_t APFCONbits __attribute__((address(0x093)));
# 1701 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char WPU __attribute__((address(0x095)));

__asm("WPU equ 095h");


extern volatile unsigned char WPUA __attribute__((address(0x095)));

__asm("WPUA equ 095h");


typedef union {
    struct {
        unsigned WPUA0 :1;
        unsigned WPUA1 :1;
        unsigned WPUA2 :1;
        unsigned :1;
        unsigned WPUA4 :1;
        unsigned WPUA5 :1;
    };
    struct {
        unsigned WPU0 :1;
        unsigned WPU1 :1;
        unsigned WPU2 :1;
        unsigned :1;
        unsigned WPU4 :1;
        unsigned WPU5 :1;
    };
} WPUbits_t;
extern volatile WPUbits_t WPUbits __attribute__((address(0x095)));
# 1782 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
typedef union {
    struct {
        unsigned WPUA0 :1;
        unsigned WPUA1 :1;
        unsigned WPUA2 :1;
        unsigned :1;
        unsigned WPUA4 :1;
        unsigned WPUA5 :1;
    };
    struct {
        unsigned WPU0 :1;
        unsigned WPU1 :1;
        unsigned WPU2 :1;
        unsigned :1;
        unsigned WPU4 :1;
        unsigned WPU5 :1;
    };
} WPUAbits_t;
extern volatile WPUAbits_t WPUAbits __attribute__((address(0x095)));
# 1855 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char IOC __attribute__((address(0x096)));

__asm("IOC equ 096h");


extern volatile unsigned char IOCA __attribute__((address(0x096)));

__asm("IOCA equ 096h");


typedef union {
    struct {
        unsigned IOC0 :1;
        unsigned IOC1 :1;
        unsigned IOC2 :1;
        unsigned IOC3 :1;
        unsigned IOC4 :1;
        unsigned IOC5 :1;
    };
    struct {
        unsigned IOCA0 :1;
        unsigned IOCA1 :1;
        unsigned IOCA2 :1;
        unsigned IOCA3 :1;
        unsigned IOCA4 :1;
        unsigned IOCA5 :1;
    };
} IOCbits_t;
extern volatile IOCbits_t IOCbits __attribute__((address(0x096)));
# 1946 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
typedef union {
    struct {
        unsigned IOC0 :1;
        unsigned IOC1 :1;
        unsigned IOC2 :1;
        unsigned IOC3 :1;
        unsigned IOC4 :1;
        unsigned IOC5 :1;
    };
    struct {
        unsigned IOCA0 :1;
        unsigned IOCA1 :1;
        unsigned IOCA2 :1;
        unsigned IOCA3 :1;
        unsigned IOCA4 :1;
        unsigned IOCA5 :1;
    };
} IOCAbits_t;
extern volatile IOCAbits_t IOCAbits __attribute__((address(0x096)));
# 2029 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile unsigned char ADRESL __attribute__((address(0x09E)));

__asm("ADRESL equ 09Eh");




extern volatile unsigned char ANSEL __attribute__((address(0x09F)));

__asm("ANSEL equ 09Fh");


typedef union {
    struct {
        unsigned ANS :4;
        unsigned ADCS :3;
    };
    struct {
        unsigned AN0 :1;
        unsigned AN1 :1;
        unsigned AN2 :1;
        unsigned AN3 :1;
        unsigned ADCS0 :1;
        unsigned ADCS1 :1;
        unsigned ADCS2 :1;
    };
} ANSELbits_t;
extern volatile ANSELbits_t ANSELbits __attribute__((address(0x09F)));
# 2112 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\proc\\pic12f615.h" 3
extern volatile __bit ADCS0 __attribute__((address(0x4FC)));


extern volatile __bit ADCS1 __attribute__((address(0x4FD)));


extern volatile __bit ADCS2 __attribute__((address(0x4FE)));


extern volatile __bit ADFM __attribute__((address(0xFF)));


extern volatile __bit ADIE __attribute__((address(0x466)));


extern volatile __bit ADIF __attribute__((address(0x66)));


extern volatile __bit ADON __attribute__((address(0xF8)));


extern volatile __bit AN0 __attribute__((address(0x4F8)));


extern volatile __bit AN1 __attribute__((address(0x4F9)));


extern volatile __bit AN2 __attribute__((address(0x4FA)));


extern volatile __bit AN3 __attribute__((address(0x4FB)));


extern volatile __bit C1CH __attribute__((address(0xD0)));


extern volatile __bit C1CH0 __attribute__((address(0xD0)));


extern volatile __bit C1HYS __attribute__((address(0xE3)));


extern volatile __bit C1IE __attribute__((address(0x463)));


extern volatile __bit C1IF __attribute__((address(0x63)));


extern volatile __bit C1OE __attribute__((address(0xD5)));


extern volatile __bit C1ON __attribute__((address(0xD7)));


extern volatile __bit C1OUT __attribute__((address(0xD6)));


extern volatile __bit C1POL __attribute__((address(0xD4)));


extern volatile __bit C1R __attribute__((address(0xD2)));


extern volatile __bit C1SYNC __attribute__((address(0xE0)));


extern volatile __bit C1VREN __attribute__((address(0xCF)));


extern volatile __bit CARRY __attribute__((address(0x18)));


extern volatile __bit CCP1IE __attribute__((address(0x465)));


extern volatile __bit CCP1IF __attribute__((address(0x65)));


extern volatile __bit CCP1M0 __attribute__((address(0xA8)));


extern volatile __bit CCP1M1 __attribute__((address(0xA9)));


extern volatile __bit CCP1M2 __attribute__((address(0xAA)));


extern volatile __bit CCP1M3 __attribute__((address(0xAB)));


extern volatile __bit CHS0 __attribute__((address(0xFA)));


extern volatile __bit CHS1 __attribute__((address(0xFB)));


extern volatile __bit CHS2 __attribute__((address(0xFC)));


extern volatile __bit CMCH __attribute__((address(0xD0)));


extern volatile __bit CMHYS __attribute__((address(0xE3)));


extern volatile __bit CMIE __attribute__((address(0x463)));


extern volatile __bit CMIF __attribute__((address(0x63)));


extern volatile __bit CMOE __attribute__((address(0xD5)));


extern volatile __bit CMON __attribute__((address(0xD7)));


extern volatile __bit CMPOL __attribute__((address(0xD4)));


extern volatile __bit CMR __attribute__((address(0xD2)));


extern volatile __bit CMSYNC __attribute__((address(0xE0)));


extern volatile __bit CMVREN __attribute__((address(0xCF)));


extern volatile __bit COUT __attribute__((address(0xD6)));


extern volatile __bit DC __attribute__((address(0x19)));


extern volatile __bit DC1B0 __attribute__((address(0xAC)));


extern volatile __bit DC1B1 __attribute__((address(0xAD)));


extern volatile __bit ECCPAS0 __attribute__((address(0xBC)));


extern volatile __bit ECCPAS1 __attribute__((address(0xBD)));


extern volatile __bit ECCPAS2 __attribute__((address(0xBE)));


extern volatile __bit ECCPASE __attribute__((address(0xBF)));


extern volatile __bit ECCPIE __attribute__((address(0x465)));


extern volatile __bit ECCPIF __attribute__((address(0x65)));


extern volatile __bit FBREN __attribute__((address(0xCC)));


extern volatile __bit FVREN __attribute__((address(0xCC)));


extern volatile __bit GIE __attribute__((address(0x5F)));


extern volatile __bit GO __attribute__((address(0xF9)));


extern volatile __bit GO_DONE __attribute__((address(0xF9)));


extern volatile __bit GO_nDONE __attribute__((address(0xF9)));


extern volatile __bit GP0 __attribute__((address(0x28)));


extern volatile __bit GP1 __attribute__((address(0x29)));


extern volatile __bit GP2 __attribute__((address(0x2A)));


extern volatile __bit GP3 __attribute__((address(0x2B)));


extern volatile __bit GP4 __attribute__((address(0x2C)));


extern volatile __bit GP5 __attribute__((address(0x2D)));


extern volatile __bit GPIE __attribute__((address(0x5B)));


extern volatile __bit GPIF __attribute__((address(0x58)));


extern volatile __bit GPIO0 __attribute__((address(0x28)));


extern volatile __bit GPIO1 __attribute__((address(0x29)));


extern volatile __bit GPIO2 __attribute__((address(0x2A)));


extern volatile __bit GPIO3 __attribute__((address(0x2B)));


extern volatile __bit GPIO4 __attribute__((address(0x2C)));


extern volatile __bit GPIO5 __attribute__((address(0x2D)));


extern volatile __bit INTE __attribute__((address(0x5C)));


extern volatile __bit INTEDG __attribute__((address(0x40E)));


extern volatile __bit INTF __attribute__((address(0x59)));


extern volatile __bit IOC0 __attribute__((address(0x4B0)));


extern volatile __bit IOC1 __attribute__((address(0x4B1)));


extern volatile __bit IOC2 __attribute__((address(0x4B2)));


extern volatile __bit IOC3 __attribute__((address(0x4B3)));


extern volatile __bit IOC4 __attribute__((address(0x4B4)));


extern volatile __bit IOC5 __attribute__((address(0x4B5)));


extern volatile __bit IOCA0 __attribute__((address(0x4B0)));


extern volatile __bit IOCA1 __attribute__((address(0x4B1)));


extern volatile __bit IOCA2 __attribute__((address(0x4B2)));


extern volatile __bit IOCA3 __attribute__((address(0x4B3)));


extern volatile __bit IOCA4 __attribute__((address(0x4B4)));


extern volatile __bit IOCA5 __attribute__((address(0x4B5)));


extern volatile __bit IRP __attribute__((address(0x1F)));


extern volatile __bit P1ASEL __attribute__((address(0x498)));


extern volatile __bit P1BSEL __attribute__((address(0x499)));


extern volatile __bit P1M __attribute__((address(0xAF)));


extern volatile __bit PDC0 __attribute__((address(0xB0)));


extern volatile __bit PDC1 __attribute__((address(0xB1)));


extern volatile __bit PDC2 __attribute__((address(0xB2)));


extern volatile __bit PDC3 __attribute__((address(0xB3)));


extern volatile __bit PDC4 __attribute__((address(0xB4)));


extern volatile __bit PDC5 __attribute__((address(0xB5)));


extern volatile __bit PDC6 __attribute__((address(0xB6)));


extern volatile __bit PEIE __attribute__((address(0x5E)));


extern volatile __bit PRSEN __attribute__((address(0xB7)));


extern volatile __bit PS0 __attribute__((address(0x408)));


extern volatile __bit PS1 __attribute__((address(0x409)));


extern volatile __bit PS2 __attribute__((address(0x40A)));


extern volatile __bit PSA __attribute__((address(0x40B)));


extern volatile __bit PSSAC0 __attribute__((address(0xBA)));


extern volatile __bit PSSAC1 __attribute__((address(0xBB)));


extern volatile __bit PSSBD0 __attribute__((address(0xB8)));


extern volatile __bit PSSBD1 __attribute__((address(0xB9)));


extern volatile __bit RA0 __attribute__((address(0x28)));


extern volatile __bit RA1 __attribute__((address(0x29)));


extern volatile __bit RA2 __attribute__((address(0x2A)));


extern volatile __bit RA3 __attribute__((address(0x2B)));


extern volatile __bit RA4 __attribute__((address(0x2C)));


extern volatile __bit RA5 __attribute__((address(0x2D)));


extern volatile __bit RP0 __attribute__((address(0x1D)));


extern volatile __bit RP1 __attribute__((address(0x1E)));


extern volatile __bit T0CS __attribute__((address(0x40D)));


extern volatile __bit T0IE __attribute__((address(0x5D)));


extern volatile __bit T0IF __attribute__((address(0x5A)));


extern volatile __bit T0SE __attribute__((address(0x40C)));


extern volatile __bit T1ACS __attribute__((address(0xE4)));


extern volatile __bit T1CKPS0 __attribute__((address(0x84)));


extern volatile __bit T1CKPS1 __attribute__((address(0x85)));


extern volatile __bit T1GINV __attribute__((address(0x87)));


extern volatile __bit T1GSEL __attribute__((address(0x49C)));


extern volatile __bit T1GSS __attribute__((address(0xE1)));


extern volatile __bit T1IE __attribute__((address(0x460)));


extern volatile __bit T1IF __attribute__((address(0x60)));


extern volatile __bit T1OSCEN __attribute__((address(0x83)));


extern volatile __bit T2CKPS0 __attribute__((address(0x90)));


extern volatile __bit T2CKPS1 __attribute__((address(0x91)));


extern volatile __bit T2IE __attribute__((address(0x461)));


extern volatile __bit T2IF __attribute__((address(0x61)));


extern volatile __bit T2ON __attribute__((address(0x92)));


extern volatile __bit TMR0IE __attribute__((address(0x5D)));


extern volatile __bit TMR0IF __attribute__((address(0x5A)));


extern volatile __bit TMR1CS __attribute__((address(0x81)));


extern volatile __bit TMR1GE __attribute__((address(0x86)));


extern volatile __bit TMR1IE __attribute__((address(0x460)));


extern volatile __bit TMR1IF __attribute__((address(0x60)));


extern volatile __bit TMR1ON __attribute__((address(0x80)));


extern volatile __bit TMR2IE __attribute__((address(0x461)));


extern volatile __bit TMR2IF __attribute__((address(0x61)));


extern volatile __bit TMR2ON __attribute__((address(0x92)));


extern volatile __bit TOUTPS0 __attribute__((address(0x93)));


extern volatile __bit TOUTPS1 __attribute__((address(0x94)));


extern volatile __bit TOUTPS2 __attribute__((address(0x95)));


extern volatile __bit TOUTPS3 __attribute__((address(0x96)));


extern volatile __bit TRISIO0 __attribute__((address(0x428)));


extern volatile __bit TRISIO1 __attribute__((address(0x429)));


extern volatile __bit TRISIO2 __attribute__((address(0x42A)));


extern volatile __bit TRISIO3 __attribute__((address(0x42B)));


extern volatile __bit TRISIO4 __attribute__((address(0x42C)));


extern volatile __bit TRISIO5 __attribute__((address(0x42D)));


extern volatile __bit TUN0 __attribute__((address(0x480)));


extern volatile __bit TUN1 __attribute__((address(0x481)));


extern volatile __bit TUN2 __attribute__((address(0x482)));


extern volatile __bit TUN3 __attribute__((address(0x483)));


extern volatile __bit TUN4 __attribute__((address(0x484)));


extern volatile __bit VCFG __attribute__((address(0xFE)));


extern volatile __bit VP6EN __attribute__((address(0xCC)));


extern volatile __bit VR0 __attribute__((address(0xC8)));


extern volatile __bit VR1 __attribute__((address(0xC9)));


extern volatile __bit VR2 __attribute__((address(0xCA)));


extern volatile __bit VR3 __attribute__((address(0xCB)));


extern volatile __bit VRR __attribute__((address(0xCD)));


extern volatile __bit WPU0 __attribute__((address(0x4A8)));


extern volatile __bit WPU1 __attribute__((address(0x4A9)));


extern volatile __bit WPU2 __attribute__((address(0x4AA)));


extern volatile __bit WPU4 __attribute__((address(0x4AC)));


extern volatile __bit WPU5 __attribute__((address(0x4AD)));


extern volatile __bit WPUA0 __attribute__((address(0x4A8)));


extern volatile __bit WPUA1 __attribute__((address(0x4A9)));


extern volatile __bit WPUA2 __attribute__((address(0x4AA)));


extern volatile __bit WPUA4 __attribute__((address(0x4AC)));


extern volatile __bit WPUA5 __attribute__((address(0x4AD)));


extern volatile __bit ZERO __attribute__((address(0x1A)));


extern volatile __bit nBOD __attribute__((address(0x470)));


extern volatile __bit nBOR __attribute__((address(0x470)));


extern volatile __bit nDONE __attribute__((address(0xF9)));


extern volatile __bit nGPPU __attribute__((address(0x40F)));


extern volatile __bit nPD __attribute__((address(0x1B)));


extern volatile __bit nPOR __attribute__((address(0x471)));


extern volatile __bit nT1SYNC __attribute__((address(0x82)));


extern volatile __bit nTO __attribute__((address(0x1C)));
# 185 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic_chip_select.h" 2 3
# 14 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic.h" 2 3
# 76 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic.h" 3
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);



# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\eeprom_routines.h" 1 3
# 84 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic.h" 2 3
# 127 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\pic.h" 3
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;
# 29 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC10-12Fxxx_DFP/1.4.56/xc8\\pic\\include\\xc.h" 2 3
# 22 "newmain.c" 2








void setDuty(unsigned int duty) {
    CCPR1L = duty >> 2;
    CCP1CON &= 0xCF;
    CCP1CON |= (0x30 & (duty << 4));
}

void main(void) {

    unsigned int result;


    unsigned char ledOFF;



    ANSEL = 0b0000001;
    TRISA = 0;


    ADCON0bits.CHS = 0b00;
    ADCON0bits.VCFG = 0;
    ADCON0bits.ADFM = 0;
    ADCON0bits.ADON = 1;



    GP5 = 0;
    TRISIO0 = 1;
    TRISIO5 = 0;
    P1ASEL = 1;

    T2CONbits.T2CKPS = 0b00;
    CCP1CONbits.P1M = 0;
    CCP1CONbits.CCP1M = 0b1100;

    TMR2 = 0;
    TMR2ON = 1;

    ledOFF = 0;

    while (1) {
# 79 "newmain.c"
        ADCON0bits.GO_nDONE = 1;


        while (ADCON0bits.GO_nDONE == 1) {
        }


        result = ADRESH;


        if (result >= 9)
        {
            if (ledOFF ==1)
            {
                TMR2 = 0;
                TMR2ON = 1;
                __nop();
                _delay((unsigned long)((10)*(8000000/4000.0)));
                ledOFF = 0;
            }
            setDuty(result);
            _delay((unsigned long)((10)*(8000000/4000.0)));

        } else {



            if (ledOFF == 0)
            {
            ledOFF = 1;
            TMR2 = 0;
            TMR2ON = 0;
            _delay((unsigned long)((20)*(8000000/4000.0)));
            }

            GP5 = 0;
            _delay((unsigned long)((10)*(8000000/4000.0)));
        }



    }
}
