#include "stc15f2k60s2.h"
#include "types.h"

/*
Row 0 pin P20
Row 1 pin P45
Row 2 pin P04
Row 3 pin P27
Row 4 pin P00
Row 5 pin P03
Row 6 pin P01
Row 7 pin P02
Row 8 pin P05
Row 9 pin P07
Row 10 pin P13
Row 11 pin P06
Row 12 pin P14
Row 13 pin P12
Row 14 pin P11
Row 15 pin P54

Column 0 pin P24
Column 1 pin P26
Column 2 pin P44
Column 3 pin P21
Column 4 pin P42
Column 5 pin P22
Column 6 pin P35
Column 7 pin P17
*/

void MyInitHw() {
  // Turn off all the segments;
  P0 = 0;
  P1 = 0x80;
  P2 = 0x7E;
  P3 = 0x20;
  P4 = 0x16;
  P5 = 0;

  // Set the rows to have push-pull mode, 20ma current source
  P0M0 = 0xFF;
  P1M0 = 0x1E;
  P2M0 = 0x81;
  P4M0 = 0x20;
  P5M0 = 0x10;

  // Drive buttons up.
  P30 = 1;  // OK
  P31 = 1;  // Reset
  P32 = 1;  // Up
  P33 = 1;  // Right
  P36 = 1;  // Down
  P37 = 1;  // Left
}

// Designed to run at 27.000MHz
void MyDelay100ms() {
  unsigned char i, j, k;

  i = 10;
  j = 153;
  k = 44;
  do {
    do {
      while (--k) {};
    } while (--j);
  } while (--i);
}

void main(void) {
  MyInitHw();

  // Columns are sinks, rows are sources.
  // When a column has a value of zero, the sink is enabled.
  // When a column has a vlaue of one, the sink is disabled.
  // When a row has a value of zero, the source is disabled.
  // when a row has a value of one, the source is enabled.

  // Col 0 - ON
  P24 = 0;
  while (1) {
    MyDelay100ms();
    // ROW 0 - ON
    P20 = 1;

    MyDelay100ms();
    // ROW 1 - ON
    P45 = 1;

    MyDelay100ms();
    // ROW 2 - ON
    P04 = 1;

    MyDelay100ms();
    // ROW 0 - OFF
    P20 = 0;

    MyDelay100ms();
    // ROW 1 - OFF
    P45 = 0;

    MyDelay100ms();
    // ROW 2 - OFF
    P04 = 0;
  }
}
