// PIC16F1938 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f1936.h>
#define _XTAL_FREQ 8000000

void PICinit(){
    OSCCON     = 0b01110010 ; // 内部クロックは８ＭＨｚとする
    OPTION_REG = 0b00000000 ; // デジタルI/Oに内部プルアップ抵抗を使用する
    ANSELA     = 0b00000000 ; // AN0-AN4は使用しない全てデジタルI/Oとする
    ANSELB     = 0b00000000 ; // AN8-AN13は使用しない全てデジタルI/Oとする
    TRISA      = 0b00000000 ; // ピン(RA)は全て出力に割当てる(0:出力 1:入力)
    TRISB      = 0b00000001 ; // ピン(RB)はRB0のみ入力、他は全て出力に割当てる
    TRISC      = 0b00000000 ; // ピン(RC)は全て出力に割当てる
    WPUB       = 0b00000001 ; // RB0は内部プルアップ抵抗を指定する
    PORTA      = 0b00000000 ; // RA出力ピンの初期化(全てLOWにする)
    PORTB      = 0b00000000 ; // RB出力ピンの初期化(全てLOWにする)
    PORTC      = 0b00000000 ; // RC出力ピンの初期化(全てLOWにする)
}

int main(void){
  PICinit();      //PICを初期化
  while(1){
      
      if(RB0 == 1){
          RA1 = 1;  
      }else{
          RA1 = 0;

      }
  }


  return 0;
}