# AVR-Programming

This repo consists of example codes and how to interface and build programs with ATmega 8/328p 8 - Bit Microcontroller, and also building an envirionment for programming the chip and bootloading the Atmega 8/328p microcontroller.

Atmega 328p is a RISC based Micro-Controller belongs to megaAVR family, combines 32KB ISP flash memory with read-while-write capabilities, 1KB EEPROM, 2KB SRAM, 23 general purpose I/O lines, 32 general purpose working registers, three flexible timer/counters with compare modes, internal and external interrupts,serial programmable USART, a byte-oriented 2-wire serial interface, SPI serial port, 6-channel 10-bit A/D converter (8-channels in TQFP and QFN/MLF packages), programmable watchdog timer with internal oscillator, and five software selectable power saving modes. The device operates between 1.8-5.5 volts.

By executing powerful instructions in a single clock cycle, the device achieves throughputs approaching 1 MIPS per MHz, balancing power consumption and processing speed.

BUILDING AN ENVIROINMENT

In Windows, 

  - You can install AVR STUDIO 7 [LINK to Download](http://www.atmel.com/microsite/atmel-studio/) (or)
  - You can install winAVR [LINK to Download](http://sourceforge.net/projects/winavr/files/WinAVR/20100110/) with Programmer's  Notepad which is light version to program the AVR Chip.

In Linux,

  - You Should install avr-gcc, gcc latest version and avrdude (or simply install Arduino IDE it takes care of building the   
    enviorinment for you to write the program to the chip using avrdude).

FLASHING THE FUSEBITS 

Settings:

  - Chip is enabled to work with 16 MHz External Crystal with 65ms Delay Startup
  
For ATmega 328p:
----------------

0 - Programmed
1 - Unprogrammed

HIGH FUSE BYTE:

          RST DISBL       1
          DWEN            1
          SPIEN           0
          WDTON           1
          EESAVE          1
          BOOTSZ1         0
          BOOTSZ0         0
          BOOTRST         1

LOW FUSE BYTE:

          CKDIV8          1
          CKOUT           1
          SUT1            1
          SUT0            1
          CKSEL3          0
          CKSEL2          1
          CKSEL1          1
          CKSEL0          1

To Write the fuse bits to the Chip follow the command:

          avrdude -c USBasp -p m328p -U hfuse:0b11011001:m -U lfuse:0b11110111:m

For ATmega 8:
-------------

HIGH FUSE BYTE:

          RST DISBL       1
          WDTON           1
          SPIEN           0
          CKOPT           0
          EESAVE          1
          BOOTSZ1         0
          BOOTSZ0         0
          BOOTRST         1

LOW FUSE BYTE:

          BODLEVEL        1
          BODEN           1`
          SUT1            1
          SUT0            1
          CKSEL3          1
          CKSEL2          1
          CKSEL1          1
          CKSEL0          1

To Write the fuse bits to the Chip follow the command:

          avrdude -c USBasp -p m8 -U hfuse:0b11001001:m -U lfuse:0b11111111:m


PROGRAMMING THE CHIP:

(Writing the Chip with hex file)

          avrdude -c USBasp -p m328p -U flash:w:main.hex

USBasp => Programmer
m329p  => Atmega 328p Chip




