/***************************************************|
|            MEGACORE 100-PIN AVR PINOUT            |
|        https://github.com/MCUdude/MegaCore        |
|                                                   |
| This file is used when compiling for:             |
| ATmega2560/V                                      |
| ATmega1280/V                                      |
| ATmega640/V                                       |
|                                                   |
|***************************************************/


#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define MEGACORE
#define MCUDUDE_MEGACORE

// Current pinout
#define MEGACORE_100_PIN_AVR_PINOUT

// ATmega640, ATmega1280, ATmega2560
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  // Digital pins
  #define NUM_DIGITAL_PINS            (86)

  // PWM pins
  #define digitalPinHasPWM(p)         (((p) >= 3 && (p) <= 5) || \
                                      ((p) >= 11 && (p)<= 14) || \
                                      ((p) >= 19 && (p)<= 22) || \
                                      ((p) >= 29 && (p)<= 31) || \
                                      ((p) == 85))
  // Builtin LED
  #if !defined(LED_BUILTIN)
    #define LED_BUILTIN               (22)
  #endif
  static const uint8_t LED = LED_BUILTIN;

  // SPI defs
  #define PIN_SPI_SS                  (15)
  #define PIN_SPI_SCK                 (16)
  #define PIN_SPI_MOSI                (17)
  #define PIN_SPI_MISO                (18)
  static const uint8_t SS   = PIN_SPI_SS;
  static const uint8_t SCK  = PIN_SPI_SCK;
  static const uint8_t MOSI = PIN_SPI_MOSI;
  static const uint8_t MISO = PIN_SPI_MISO;

  // i2c defs
  #define PIN_WIRE_SDA                (35)
  #define PIN_WIRE_SCL                (34)
  static const uint8_t SDA = PIN_WIRE_SDA;
  static const uint8_t SCL = PIN_WIRE_SCL;

  // Serial defs
  #define SERIAL_PORT_MONITOR         Serial
  #define SERIAL_PORT_HARDWARE        Serial
  #define SERIAL_PORT_HARDWARE1       Serial1
  #define SERIAL_PORT_HARDWARE2       Serial2
  #define SERIAL_PORT_HARDWARE3       Serial3
  #define SERIAL_PORT_HARDWARE_OPEN   Serial1
  #define SERIAL_PORT_HARDWARE_OPEN1  Serial2
  #define SERIAL_PORT_HARDWARE_OPEN2  Serial3

  // Interrupts
  #define EXTERNAL_NUM_INTERRUPTS     (8)
  #define digitalPinToInterrupt(p)    ((((p) >= 4) && ((p) <= 7))  ? (p) : \
                                      (((p) >= 34) && ((p) <= 37)) ? ((p) - 34) : NOT_AN_INTERRUPT)

  // PCINT defs
  #define digitalPinToPCICR(p)        (((p) == 0)  || \
                                      (((p) >= 15) && ((p) <= 22)) || \
                                      (((p) >= 52) && ((p) <= 58)) || \
                                      (((p) >= 77) && ((p) <= 84)) ?  (&PCICR) : ((uint8_t *)0))

  #define digitalPinToPCICRbit(p)     ((((p) >= 15) && ((p) <= 22)) ? 0 : \
                                      ((((p) >= 52) && ((p) <= 58)) || ((p) == 0)) ? 1 : \
                                      (((p) >= 77)  && ((p) <= 84)) ? 2 : 0)

  #define digitalPinToPCMSK(p)        ((((p) >= 15) && ((p) <= 22)) ? (&PCMSK0) : \
                                      ((((p) >= 52) && ((p) <= 58)) || ((p) == 0)) ? (&PCMSK1) : \
                                      (((p) >= 77)  && ((p) <= 84)) ? (&PCMSK2) : ((uint8_t *)0))

  #define digitalPinToPCMSKbit(p)     ((((p) >= 15) && ((p) <= 22)) ? ((p) - 15) : \
                                      (((p) >= 52)  && ((p) <= 58)) ? ((p) - 51) : \
                                      (((p) >= 77)  && ((p) <= 84)) ? ((p) - 77) : \
                                      ((p) == 85) ? 0 : 0)

  // Analog pin defs
  #define NUM_ANALOG_INPUTS           (16)
  #define analogInputToDigitalPin(p)  ((p < 16) ? (p) + 69 : -1)
  #define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 69 ? (p) - 69 : -1)
  #define PIN_A0   (69)
  #define PIN_A1   (70)
  #define PIN_A2   (71)
  #define PIN_A3   (72)
  #define PIN_A4   (73)
  #define PIN_A5   (74)
  #define PIN_A6   (75)
  #define PIN_A7   (76)
  #define PIN_A8   (77)
  #define PIN_A9   (78)
  #define PIN_A10  (79)
  #define PIN_A11  (80)
  #define PIN_A12  (81)
  #define PIN_A13  (82)
  #define PIN_A14  (83)
  #define PIN_A15  (84)
  static const uint8_t A0 = PIN_A0;
  static const uint8_t A1 = PIN_A1;
  static const uint8_t A2 = PIN_A2;
  static const uint8_t A3 = PIN_A3;
  static const uint8_t A4 = PIN_A4;
  static const uint8_t A5 = PIN_A5;
  static const uint8_t A6 = PIN_A6;
  static const uint8_t A7 = PIN_A7;
  static const uint8_t A8 = PIN_A8;
  static const uint8_t A9 = PIN_A9;
  static const uint8_t A10 = PIN_A10;
  static const uint8_t A11 = PIN_A11;
  static const uint8_t A12 = PIN_A12;
  static const uint8_t A13 = PIN_A13;
  static const uint8_t A14 = PIN_A14;
  static const uint8_t A15 = PIN_A15;

  // PIN macros
  #define PIN_PE0 0
  #define PIN_PE1 1
  #define PIN_PE2 2
  #define PIN_PE3 3
  #define PIN_PE4 4
  #define PIN_PE5 5
  #define PIN_PE6 6
  #define PIN_PE7 7
  #define PIN_PH0 8
  #define PIN_PH1 9
  #define PIN_PH2 10
  #define PIN_PH3 11
  #define PIN_PH4 12
  #define PIN_PH5 13
  #define PIN_PH6 14
  #define PIN_PB0 15
  #define PIN_PB1 16
  #define PIN_PB2 17
  #define PIN_PB3 18
  #define PIN_PB4 19
  #define PIN_PB5 20
  #define PIN_PB6 21
  #define PIN_PB7 22
  #define PIN_PH7 23
  #define PIN_PG3 24
  #define PIN_PG4 25
  #define PIN_PL0 26
  #define PIN_PL1 27
  #define PIN_PL2 28
  #define PIN_PL3 29
  #define PIN_PL4 30
  #define PIN_PL5 31
  #define PIN_PL6 32
  #define PIN_PL7 33
  #define PIN_PD0 34
  #define PIN_PD1 35
  #define PIN_PD2 36
  #define PIN_PD3 37
  #define PIN_PD4 38
  #define PIN_PD5 39
  #define PIN_PD6 40
  #define PIN_PD7 41
  #define PIN_PG0 42
  #define PIN_PG1 43
  #define PIN_PC0 44
  #define PIN_PC1 45
  #define PIN_PC2 46
  #define PIN_PC3 47
  #define PIN_PC4 48
  #define PIN_PC5 49
  #define PIN_PC6 50
  #define PIN_PC7 51
  #define PIN_PJ0 52
  #define PIN_PJ1 53
  #define PIN_PJ2 54
  #define PIN_PJ3 55
  #define PIN_PJ4 56
  #define PIN_PJ5 57
  #define PIN_PJ6 58
  #define PIN_PG2 59
  #define PIN_PA7 60
  #define PIN_PA6 61
  #define PIN_PA5 62
  #define PIN_PA4 63
  #define PIN_PA3 64
  #define PIN_PA2 65
  #define PIN_PA1 66
  #define PIN_PA0 67
  #define PIN_PJ7 68
  #define PIN_PF0 69
  #define PIN_PF1 70
  #define PIN_PF2 71
  #define PIN_PF3 72
  #define PIN_PF4 73
  #define PIN_PF5 74
  #define PIN_PF6 75
  #define PIN_PF7 76
  #define PIN_PK0 77
  #define PIN_PK1 78
  #define PIN_PK2 79
  #define PIN_PK3 80
  #define PIN_PK4 81
  #define PIN_PK5 82
  #define PIN_PK6 83
  #define PIN_PK7 84
  #define PIN_PG5 85

  #ifdef ARDUINO_MAIN
    const uint16_t PROGMEM port_to_mode_PGM[] = {
      NOT_A_PORT,
      (uint16_t) &DDRA,
      (uint16_t) &DDRB,
      (uint16_t) &DDRC,
      (uint16_t) &DDRD,
      (uint16_t) &DDRE,
      (uint16_t) &DDRF,
      (uint16_t) &DDRG,
      (uint16_t) &DDRH,
      NOT_A_PORT,
      (uint16_t) &DDRJ,
      (uint16_t) &DDRK,
      (uint16_t) &DDRL,
    };

    const uint16_t PROGMEM port_to_output_PGM[] = {
      NOT_A_PORT,
      (uint16_t) &PORTA,
      (uint16_t) &PORTB,
      (uint16_t) &PORTC,
      (uint16_t) &PORTD,
      (uint16_t) &PORTE,
      (uint16_t) &PORTF,
      (uint16_t) &PORTG,
      (uint16_t) &PORTH,
      NOT_A_PORT,
      (uint16_t) &PORTJ,
      (uint16_t) &PORTK,
      (uint16_t) &PORTL,
    };

    const uint16_t PROGMEM port_to_input_PGM[] = {
      NOT_A_PIN,
      (uint16_t) &PINA,
      (uint16_t) &PINB,
      (uint16_t) &PINC,
      (uint16_t) &PIND,
      (uint16_t) &PINE,
      (uint16_t) &PINF,
      (uint16_t) &PING,
      (uint16_t) &PINH,
      NOT_A_PIN,
      (uint16_t) &PINJ,
      (uint16_t) &PINK,
      (uint16_t) &PINL,
    };

    // Port list
    const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
      PE, // PE 0 ** 0
      PE, // PE 1 ** 1
      PE, // PE 2 ** 2
      PE, // PE 3 ** 3
      PE, // PE 4 ** 4
      PE, // PE 5 ** 5
      PE, // PE 6 ** 6
      PE, // PE 7 ** 7
      PH, // PH 0 ** 8
      PH, // PH 1 ** 9
      PH, // PH 2 ** 10
      PH, // PH 3 ** 11
      PH, // PH 4 ** 12
      PH, // PH 5 ** 13
      PH, // PH 6 ** 14
      PB, // PB 0 ** 15
      PB, // PB 1 ** 16
      PB, // PB 2 ** 17
      PB, // PB 3 ** 18
      PB, // PB 4 ** 19
      PB, // PB 5 ** 20
      PB, // PB 6 ** 21
      PB, // PB 7 ** 22
      PH, // PH 7 ** 23
      PG, // PG 3 ** 24
      PG, // PG 4 ** 25
      PL, // PL 0 ** 26
      PL, // PL 1 ** 27
      PL, // PL 2 ** 28
      PL, // PL 3 ** 29
      PL, // PL 4 ** 30
      PL, // PL 5 ** 31
      PL, // PL 6 ** 32
      PL, // PL 7 ** 33
      PD, // PD 0 ** 34
      PD, // PD 1 ** 35
      PD, // PD 2 ** 36
      PD, // PD 3 ** 37
      PD, // PD 4 ** 38
      PD, // PD 5 ** 39
      PD, // PD 6 ** 40
      PD, // PD 7 ** 41
      PG, // PG 0 ** 42
      PG, // PG 1 ** 43
      PC, // PC 0 ** 44
      PC, // PC 1 ** 45
      PC, // PC 2 ** 46
      PC, // PC 3 ** 47
      PC, // PC 4 ** 48
      PC, // PC 5 ** 49
      PC, // PC 6 ** 50
      PC, // PC 7 ** 51
      PJ, // PJ 0 ** 52
      PJ, // PJ 1 ** 53
      PJ, // PJ 2 ** 54
      PJ, // PJ 3 ** 55
      PJ, // PJ 4 ** 56
      PJ, // PJ 5 ** 57
      PJ, // PJ 6 ** 58
      PG, // PG 2 ** 59
      PA, // PA 7 ** 60
      PA, // PA 6 ** 61
      PA, // PA 5 ** 62
      PA, // PA 4 ** 63
      PA, // PA 3 ** 64
      PA, // PA 2 ** 65
      PA, // PA 1 ** 66
      PA, // PA 0 ** 67
      PJ, // PJ 7 ** 68
      PF, // PF 0 ** 69
      PF, // PF 1 ** 70
      PF, // PF 2 ** 71
      PF, // PF 3 ** 72
      PF, // PF 4 ** 73
      PF, // PF 5 ** 74
      PF, // PF 6 ** 75
      PF, // PF 7 ** 76
      PK, // PK 0 ** 77
      PK, // PK 1 ** 78
      PK, // PK 2 ** 79
      PK, // PK 3 ** 80
      PK, // PK 4 ** 81
      PK, // PK 5 ** 82
      PK, // PK 6 ** 83
      PK, // PK 7 ** 84
      PG, // PG 5 ** 85
    };

    // Pin in port
    const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
      _BV(0), // PE 0 ** 0
      _BV(1), // PE 1 ** 1
      _BV(2), // PE 2 ** 2
      _BV(3), // PE 3 ** 3
      _BV(4), // PE 4 ** 4
      _BV(5), // PE 5 ** 5
      _BV(6), // PE 6 ** 6
      _BV(7), // PE 7 ** 7
      _BV(0), // PH 0 ** 8
      _BV(1), // PH 1 ** 9
      _BV(2), // PH 2 ** 10
      _BV(3), // PH 3 ** 11
      _BV(4), // PH 4 ** 12
      _BV(5), // PH 5 ** 13
      _BV(6), // PH 6 ** 14
      _BV(0), // PB 0 ** 15
      _BV(1), // PB 1 ** 16
      _BV(2), // PB 2 ** 17
      _BV(3), // PB 3 ** 18
      _BV(4), // PB 4 ** 19
      _BV(5), // PB 5 ** 20
      _BV(6), // PB 6 ** 21
      _BV(7), // PB 7 ** 22
      _BV(7), // PH 7 ** 23
      _BV(3), // PG 3 ** 24
      _BV(4), // PG 4 ** 25
      _BV(0), // PL 0 ** 26
      _BV(1), // PL 1 ** 27
      _BV(2), // PL 2 ** 28
      _BV(3), // PL 3 ** 29
      _BV(4), // PL 4 ** 30
      _BV(5), // PL 5 ** 31
      _BV(6), // PL 6 ** 32
      _BV(7), // PL 7 ** 33
      _BV(0), // PD 0 ** 34
      _BV(1), // PD 1 ** 35
      _BV(2), // PD 2 ** 36
      _BV(3), // PD 3 ** 37
      _BV(4), // PD 4 ** 38
      _BV(5), // PD 5 ** 39
      _BV(6), // PD 6 ** 40
      _BV(7), // PD 7 ** 41
      _BV(0), // PG 0 ** 42
      _BV(1), // PG 1 ** 43
      _BV(0), // PC 0 ** 44
      _BV(1), // PC 1 ** 45
      _BV(2), // PC 2 ** 46
      _BV(3), // PC 3 ** 47
      _BV(4), // PC 4 ** 48
      _BV(5), // PC 5 ** 49
      _BV(6), // PC 6 ** 50
      _BV(7), // PC 7 ** 51
      _BV(0), // PJ 0 ** 52
      _BV(1), // PJ 1 ** 53
      _BV(2), // PJ 2 ** 54
      _BV(3), // PJ 3 ** 55
      _BV(4), // PJ 4 ** 56
      _BV(5), // PJ 5 ** 57
      _BV(6), // PJ 6 ** 58
      _BV(2), // PG 2 ** 59
      _BV(7), // PA 7 ** 60
      _BV(6), // PA 6 ** 61
      _BV(5), // PA 5 ** 62
      _BV(4), // PA 4 ** 63
      _BV(3), // PA 3 ** 64
      _BV(2), // PA 2 ** 65
      _BV(1), // PA 1 ** 66
      _BV(0), // PA 0 ** 67
      _BV(7), // PJ 7 ** 68
      _BV(0), // PF 0 ** 69
      _BV(1), // PF 1 ** 70
      _BV(2), // PF 2 ** 71
      _BV(3), // PF 3 ** 72
      _BV(4), // PF 4 ** 73
      _BV(5), // PF 5 ** 74
      _BV(6), // PF 6 ** 75
      _BV(7), // PF 7 ** 76
      _BV(0), // PK 0 ** 77
      _BV(1), // PK 1 ** 78
      _BV(2), // PK 2 ** 79
      _BV(3), // PK 3 ** 80
      _BV(4), // PK 4 ** 81
      _BV(5), // PK 5 ** 82
      _BV(6), // PK 6 ** 83
      _BV(7), // PK 7 ** 84
      _BV(5), // PG 5 ** 85
    };

    // Timers
    const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
      NOT_ON_TIMER, // PE 0 ** 0
      NOT_ON_TIMER, // PE 1 ** 1
      NOT_ON_TIMER, // PE 2 ** 2
      TIMER3A,      // PE 3 ** 3
      TIMER3B,      // PE 4 ** 4
      TIMER3C,      // PE 5 ** 5
      NOT_ON_TIMER, // PE 6 ** 6
      NOT_ON_TIMER, // PE 7 ** 7
      NOT_ON_TIMER, // PH 0 ** 8
      NOT_ON_TIMER, // PH 1 ** 9
      NOT_ON_TIMER, // PH 2 ** 10
      TIMER4A,      // PH 3 ** 11
      TIMER4B,      // PH 4 ** 12
      TIMER4C,      // PH 5 ** 13
      TIMER2B,      // PH 6 ** 14
      NOT_ON_TIMER, // PB 0 ** 15
      NOT_ON_TIMER, // PB 1 ** 16
      NOT_ON_TIMER, // PB 2 ** 17
      NOT_ON_TIMER, // PB 3 ** 18
      TIMER2A,      // PB 4 ** 19
      TIMER1A,      // PB 5 ** 20
      TIMER1B,      // PB 6 ** 21
      TIMER1C,      // PB 7 ** 22
      NOT_ON_TIMER, // PH 7 ** 23
      NOT_ON_TIMER, // PG 3 ** 24
      NOT_ON_TIMER, // PG 4 ** 25
      NOT_ON_TIMER, // PL 0 ** 26
      NOT_ON_TIMER, // PL 1 ** 27
      NOT_ON_TIMER, // PL 2 ** 28
      TIMER5A,      // PL 3 ** 29
      TIMER5B,      // PL 4 ** 30
      TIMER5C,      // PL 5 ** 31
      NOT_ON_TIMER, // PL 6 ** 32
      NOT_ON_TIMER, // PL 7 ** 33
      NOT_ON_TIMER, // PD 0 ** 34
      NOT_ON_TIMER, // PD 1 ** 35
      NOT_ON_TIMER, // PD 2 ** 36
      NOT_ON_TIMER, // PD 3 ** 37
      NOT_ON_TIMER, // PD 4 ** 38
      NOT_ON_TIMER, // PD 5 ** 39
      NOT_ON_TIMER, // PD 6 ** 40
      NOT_ON_TIMER, // PD 7 ** 41
      NOT_ON_TIMER, // PG 0 ** 42
      NOT_ON_TIMER, // PG 1 ** 43
      NOT_ON_TIMER, // PC 0 ** 44
      NOT_ON_TIMER, // PC 1 ** 45
      NOT_ON_TIMER, // PC 2 ** 46
      NOT_ON_TIMER, // PC 3 ** 47
      NOT_ON_TIMER, // PC 4 ** 48
      NOT_ON_TIMER, // PC 5 ** 49
      NOT_ON_TIMER, // PC 6 ** 50
      NOT_ON_TIMER, // PC 7 ** 51
      NOT_ON_TIMER, // PJ 0 ** 52
      NOT_ON_TIMER, // PJ 1 ** 53
      NOT_ON_TIMER, // PJ 2 ** 54
      NOT_ON_TIMER, // PJ 3 ** 55
      NOT_ON_TIMER, // PJ 4 ** 56
      NOT_ON_TIMER, // PJ 5 ** 57
      NOT_ON_TIMER, // PJ 6 ** 58
      NOT_ON_TIMER, // PG 2 ** 59
      NOT_ON_TIMER, // PA 7 ** 60
      NOT_ON_TIMER, // PA 6 ** 61
      NOT_ON_TIMER, // PA 5 ** 62
      NOT_ON_TIMER, // PA 4 ** 63
      NOT_ON_TIMER, // PA 3 ** 64
      NOT_ON_TIMER, // PA 2 ** 65
      NOT_ON_TIMER, // PA 1 ** 66
      NOT_ON_TIMER, // PA 0 ** 67
      NOT_ON_TIMER, // PJ 7 ** 68
      NOT_ON_TIMER, // PF 0 ** 69
      NOT_ON_TIMER, // PF 1 ** 70
      NOT_ON_TIMER, // PF 2 ** 71
      NOT_ON_TIMER, // PF 3 ** 72
      NOT_ON_TIMER, // PF 4 ** 73
      NOT_ON_TIMER, // PF 5 ** 74
      NOT_ON_TIMER, // PF 6 ** 75
      NOT_ON_TIMER, // PF 7 ** 76
      NOT_ON_TIMER, // PK 0 ** 77
      NOT_ON_TIMER, // PK 1 ** 78
      NOT_ON_TIMER, // PK 2 ** 79
      NOT_ON_TIMER, // PK 3 ** 80
      NOT_ON_TIMER, // PK 4 ** 81
      NOT_ON_TIMER, // PK 5 ** 82
      NOT_ON_TIMER, // PK 6 ** 83
      NOT_ON_TIMER, // PK 7 ** 84
      TIMER0B,      // PG 5 ** 85
    };
  #endif // ARDUINO_MAIN


#else // ATmega3250, ATmega3290, ATmega6450, ATmega6490

  // Digital pins
  #define NUM_DIGITAL_PINS            (67)

  // PWM pins
  #define digitalPinHasPWM(p)         (((p) >= 14 && (p) <= 17))

  // Builtin LED
  #if !defined(LED_BUILTIN)
    #define LED_BUILTIN               (17)
  #endif
  static const uint8_t LED = LED_BUILTIN;

  // SPI defs
  #define PIN_SPI_SS                  (10)
  #define PIN_SPI_SCK                 (11)
  #define PIN_SPI_MOSI                (12)
  #define PIN_SPI_MISO                (13)
  static const uint8_t SS   = PIN_SPI_SS;
  static const uint8_t SCK  = PIN_SPI_SCK;
  static const uint8_t MOSI = PIN_SPI_MOSI;
  static const uint8_t MISO = PIN_SPI_MISO;

  // i2c defs
  #define PIN_WIRE_SDA                (5)
  #define PIN_WIRE_SCL                (4)
  static const uint8_t SDA = PIN_WIRE_SDA;
  static const uint8_t SCL = PIN_WIRE_SCL;

  // Serial defs
  #define SERIAL_PORT_MONITOR         Serial
  #define SERIAL_PORT_HARDWARE        Serial

  // Interrupts
  #define EXTERNAL_NUM_INTERRUPTS     (1)
  #define digitalPinToInterrupt(p)    ((p) == 26 ? 0 : NOT_AN_INTERRUPT)

  // PCINT defs
  #define digitalPinToPCICR(p)     	  ((((p) >= 0) && ((p) <= 17)) || \
                                      (((p) >= 20) && ((p) <= 24)) || \
                                      (((p) >= 41) && ((p) <= 44)) || \
                                      (((p) >= 56) && ((p) <= 59)) ?  (&EIMSK) : ((uint8_t *)0))

  #define digitalPinToPCICRbit(p)     ((((p) >= 0)  && ((p) <= 7))  ? PCIE0 : \
                                      (((p) >= 10)  && ((p) <= 17)) ? PCIE1 : \
                                      ((((p) >= 41) && ((p) <= 44)) || (((p) >= 56) && ((p) <= 59))) ? PCIE2 : \
                                      ((((p) >= 20) && ((p) <= 24)) || (((p) == 8)  || ((p) == 9)))  ? PCIE3 : 0)

  #define digitalPinToPCMSK(p)        ((((p) >= 0)  && ((p) <= 7))  ? &PCMSK0 : \
                                      (((p) >= 10)  && ((p) <= 17)) ? &PCMSK1 : \
                                      ((((p) >= 41) && ((p) <= 44)) || (((p) >= 56) && ((p) <= 59))) ? &PCMSK2 : \
                                      ((((p) >= 20) && ((p) <= 24)) || (((p) == 8)  || ((p) == 9)))  ? &PCMSK3 : (uint8_t *)0)

  #define digitalPinToPCMSKbit(p)     ((((p) >= 0) && ((p) <= 7))  ? (p)        : \
                                      (((p) == 8)  || ((p) <= 9))  ? ((p) - 8)  : \
                                      (((p) >= 10) && ((p) <= 17)) ? ((p) - 10) : \
                                      (((p) >= 20) && ((p) <= 24)) ? ((p) - 18) : \
                                      (((p) >= 41) && ((p) <= 44)) ? ((p) - 41) : \
                                      (((p) >= 56) && ((p) <= 59)) ? ((p) - 52) : 0)

  // Analog pin defs
  #define NUM_ANALOG_INPUTS           (8)
  #define analogInputToDigitalPin(p)  (((p) < NUM_ANALOG_INPUTS) ? (p) + 60 : -1)
  #define analogPinToChannel(p)       (((p) < NUM_ANALOG_INPUTS) ? (p) : (p) >= 60 ? (p) - 60 : -1)
  #define PIN_A0   (60)
  #define PIN_A1   (61)
  #define PIN_A2   (62)
  #define PIN_A3   (63)
  #define PIN_A4   (64)
  #define PIN_A5   (65)
  #define PIN_A6   (66)
  #define PIN_A7   (67)
  static const uint8_t A0 = PIN_A0;
  static const uint8_t A1 = PIN_A1;
  static const uint8_t A2 = PIN_A2;
  static const uint8_t A3 = PIN_A3;
  static const uint8_t A4 = PIN_A4;
  static const uint8_t A5 = PIN_A5;
  static const uint8_t A6 = PIN_A6;
  static const uint8_t A7 = PIN_A7;

  // PIN macros
  #define PIN_PE0 0
  #define PIN_PE1 1
  #define PIN_PE2 2
  #define PIN_PE3 3
  #define PIN_PE4 4
  #define PIN_PE5 5
  #define PIN_PE6 6
  #define PIN_PE7 7
  #define PIN_PJ0 8
  #define PIN_PJ1 9
  #define PIN_PB0 10
  #define PIN_PB1 11
  #define PIN_PB2 12
  #define PIN_PB3 13
  #define PIN_PB4 14
  #define PIN_PB5 15
  #define PIN_PB6 16
  #define PIN_PB7 17
  #define PIN_PG3 18
  #define PIN_PG4 19
  #define PIN_PJ2 20
  #define PIN_PJ3 21
  #define PIN_PJ4 22
  #define PIN_PJ5 23
  #define PIN_PJ6 24
  #define PIN_PD0 25
  #define PIN_PD1 26
  #define PIN_PD2 27
  #define PIN_PD3 28
  #define PIN_PD4 39
  #define PIN_PD5 30
  #define PIN_PD6 31
  #define PIN_PD7 32
  #define PIN_PG0 33
  #define PIN_PG1 34
  #define PIN_PC0 35
  #define PIN_PC1 36
  #define PIN_PC2 37
  #define PIN_PC3 38
  #define PIN_PC4 39
  #define PIN_PC5 40
  #define PIN_PH0 41
  #define PIN_PH1 42
  #define PIN_PH2 43
  #define PIN_PH3 44
  #define PIN_PC6 45
  #define PIN_PC7 46
  #define PIN_PG2 47
  #define PIN_PA7 48
  #define PIN_PA6 49
  #define PIN_PA5 50
  #define PIN_PA4 51
  #define PIN_PA3 52
  #define PIN_PA2 53
  #define PIN_PA1 54
  #define PIN_PA0 55
  #define PIN_PH4 56
  #define PIN_PH5 57
  #define PIN_PH6 58
  #define PIN_PH7 59
  #define PIN_PF0 60
  #define PIN_PF1 61
  #define PIN_PF2 62
  #define PIN_PF3 63
  #define PIN_PF4 64
  #define PIN_PF5 65
  #define PIN_PF6 66
  #define PIN_PF7 67

#ifdef ARDUINO_MAIN
    const uint16_t PROGMEM port_to_mode_PGM[] = {
      NOT_A_PORT,
      (uint16_t) &DDRA,
      (uint16_t) &DDRB,
      (uint16_t) &DDRC,
      (uint16_t) &DDRD,
      (uint16_t) &DDRE,
      (uint16_t) &DDRF,
      (uint16_t) &DDRG,
      (uint16_t) &DDRH,
      NOT_A_PORT,
      (uint16_t) &DDRJ,
    };

    const uint16_t PROGMEM port_to_output_PGM[] = {
      NOT_A_PORT,
      (uint16_t) &PORTA,
      (uint16_t) &PORTB,
      (uint16_t) &PORTC,
      (uint16_t) &PORTD,
      (uint16_t) &PORTE,
      (uint16_t) &PORTF,
      (uint16_t) &PORTG,
      (uint16_t) &PORTH,
      NOT_A_PORT,
      (uint16_t) &PORTJ,
    };

    const uint16_t PROGMEM port_to_input_PGM[] = {
      NOT_A_PIN,
      (uint16_t) &PINA,
      (uint16_t) &PINB,
      (uint16_t) &PINC,
      (uint16_t) &PIND,
      (uint16_t) &PINE,
      (uint16_t) &PINF,
      (uint16_t) &PING,
      (uint16_t) &PINH,
      NOT_A_PIN,
      (uint16_t) &PINJ,
    };

    // Port list
    const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
      PE, // PE 0 ** 0
      PE, // PE 1 ** 1
      PE, // PE 2 ** 2
      PE, // PE 3 ** 3
      PE, // PE 4 ** 4
      PE, // PE 5 ** 5
      PE, // PE 6 ** 6
      PE, // PE 7 ** 7
      PJ, // PJ 0 ** 8
      PJ, // PJ 1 ** 9
      PB, // PB 0 ** 10
      PB, // PB 1 ** 11
      PB, // PB 2 ** 12
      PB, // PB 3 ** 13
      PB, // PB 4 ** 14
      PB, // PB 5 ** 15
      PB, // PB 6 ** 16
      PB, // PB 7 ** 17
      PG, // PG 3 ** 18
      PG, // PG 4 ** 19
      PJ, // PJ 2 ** 20
      PJ, // PJ 3 ** 21
      PJ, // PJ 4 ** 22
      PJ, // PJ 5 ** 23
      PJ, // PJ 6 ** 24
      PD, // PD 0 ** 25
      PD, // PD 1 ** 26
      PD, // PD 2 ** 27
      PD, // PD 3 ** 28
      PD, // PD 4 ** 29
      PD, // PD 5 ** 30
      PD, // PD 6 ** 31
      PD, // PD 7 ** 32
      PG, // PG 0 ** 33
      PG, // PG 1 ** 34
      PC, // PC 0 ** 35
      PC, // PC 1 ** 36
      PC, // PC 2 ** 37
      PC, // PC 3 ** 38
      PC, // PC 4 ** 39
      PC, // PC 5 ** 40
      PH, // PH 0 ** 41
      PH, // PH 1 ** 42
      PH, // PH 2 ** 43
      PH, // PH 3 ** 44
      PC, // PC 6 ** 45
      PC, // PC 7 ** 46
      PG, // PG 2 ** 47
      PA, // PA 7 ** 48
      PA, // PA 6 ** 49
      PA, // PA 5 ** 50
      PA, // PA 4 ** 51
      PA, // PA 3 ** 52
      PA, // PA 2 ** 53
      PA, // PA 1 ** 54
      PA, // PA 0 ** 55
      PH, // PH 4 ** 56
      PH, // PH 5 ** 57
      PH, // PH 6 ** 58
      PH, // PH 7 ** 59
      PF, // PF 0 ** 60
      PF, // PF 1 ** 61
      PF, // PF 2 ** 62
      PF, // PF 3 ** 63
      PF, // PF 4 ** 64
      PF, // PF 5 ** 65
      PF, // PF 6 ** 66
      PF, // PF 7 ** 67
    };

    // Pin in port
    const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
      _BV(0), // PE 0 ** 0
      _BV(1), // PE 1 ** 1
      _BV(2), // PE 2 ** 2
      _BV(3), // PE 3 ** 3
      _BV(4), // PE 4 ** 4
      _BV(5), // PE 5 ** 5
      _BV(6), // PE 6 ** 6
      _BV(7), // PE 7 ** 7
      _BV(0), // PJ 0 ** 8
      _BV(1), // PJ 1 ** 9
      _BV(0), // PB 0 ** 10
      _BV(1), // PB 1 ** 11
      _BV(2), // PB 2 ** 12
      _BV(3), // PB 3 ** 13
      _BV(4), // PB 4 ** 14
      _BV(5), // PB 5 ** 15
      _BV(6), // PB 6 ** 16
      _BV(7), // PB 7 ** 17
      _BV(3), // PG 3 ** 18
      _BV(4), // PG 4 ** 19
      _BV(2), // PJ 2 ** 20
      _BV(3), // PJ 3 ** 21
      _BV(4), // PJ 4 ** 22
      _BV(5), // PJ 5 ** 23
      _BV(6), // PJ 6 ** 24
      _BV(0), // PD 0 ** 25
      _BV(1), // PD 1 ** 26
      _BV(2), // PD 2 ** 27
      _BV(3), // PD 3 ** 28
      _BV(4), // PD 4 ** 29
      _BV(5), // PD 5 ** 30
      _BV(6), // PD 6 ** 31
      _BV(7), // PD 7 ** 32
      _BV(0), // PG 0 ** 33
      _BV(1), // PG 1 ** 34
      _BV(0), // PC 0 ** 35
      _BV(1), // PC 1 ** 36
      _BV(2), // PC 2 ** 37
      _BV(3), // PC 3 ** 38
      _BV(4), // PC 4 ** 39
      _BV(5), // PC 5 ** 40
      _BV(0), // PH 0 ** 41
      _BV(1), // PH 1 ** 42
      _BV(2), // PH 2 ** 43
      _BV(3), // PH 3 ** 44
      _BV(6), // PC 6 ** 45
      _BV(7), // PC 7 ** 46
      _BV(2), // PG 2 ** 47
      _BV(7), // PA 7 ** 48
      _BV(6), // PA 6 ** 49
      _BV(5), // PA 5 ** 50
      _BV(4), // PA 4 ** 51
      _BV(3), // PA 3 ** 52
      _BV(2), // PA 2 ** 53
      _BV(1), // PA 1 ** 53
      _BV(0), // PA 0 ** 55
      _BV(4), // PH 4 ** 56
      _BV(5), // PH 5 ** 57
      _BV(6), // PH 6 ** 58
      _BV(7), // PH 7 ** 59
      _BV(0), // PF 0 ** 60
      _BV(1), // PF 1 ** 61
      _BV(2), // PF 2 ** 62
      _BV(3), // PF 3 ** 63
      _BV(4), // PF 4 ** 64
      _BV(5), // PF 5 ** 65
      _BV(6), // PF 6 ** 66
      _BV(7), // PF 7 ** 67
    };

    // Timers
    const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
      NOT_ON_TIMER, // PE 0 ** 0
      NOT_ON_TIMER, // PE 1 ** 1
      NOT_ON_TIMER, // PE 2 ** 2
      NOT_ON_TIMER, // PE 3 ** 3
      NOT_ON_TIMER, // PE 4 ** 4
      NOT_ON_TIMER, // PE 5 ** 5
      NOT_ON_TIMER, // PE 6 ** 6
      NOT_ON_TIMER, // PE 7 ** 7
      NOT_ON_TIMER, // PJ 0 ** 8
      NOT_ON_TIMER, // PJ 1 ** 9
      NOT_ON_TIMER, // PB 0 ** 10
      NOT_ON_TIMER, // PB 1 ** 11
      NOT_ON_TIMER, // PB 2 ** 12
      NOT_ON_TIMER, // PB 3 ** 13
      TIMER0A,      // PB 4 ** 14
      TIMER1A,      // PB 5 ** 15
      TIMER1B,      // PB 6 ** 16
      TIMER2A,      // PB 7 ** 17
      NOT_ON_TIMER, // PG 3 ** 18
      NOT_ON_TIMER, // PG 4 ** 19
      NOT_ON_TIMER, // PJ 2 ** 20
      NOT_ON_TIMER, // PJ 3 ** 21
      NOT_ON_TIMER, // PJ 4 ** 22
      NOT_ON_TIMER, // PJ 5 ** 23
      NOT_ON_TIMER, // PJ 6 ** 24
      NOT_ON_TIMER, // PD 0 ** 25
      NOT_ON_TIMER, // PD 1 ** 26
      NOT_ON_TIMER, // PD 2 ** 27
      NOT_ON_TIMER, // PD 3 ** 28
      NOT_ON_TIMER, // PD 4 ** 29
      NOT_ON_TIMER, // PD 5 ** 30
      NOT_ON_TIMER, // PD 6 ** 31
      NOT_ON_TIMER, // PD 7 ** 32
      NOT_ON_TIMER, // PG 0 ** 33
      NOT_ON_TIMER, // PG 1 ** 34
      NOT_ON_TIMER, // PC 0 ** 35
      NOT_ON_TIMER, // PC 1 ** 36
      NOT_ON_TIMER, // PC 2 ** 37
      NOT_ON_TIMER, // PC 3 ** 38
      NOT_ON_TIMER, // PC 4 ** 39
      NOT_ON_TIMER, // PC 5 ** 40
      NOT_ON_TIMER, // PH 0 ** 41
      NOT_ON_TIMER, // PH 1 ** 42
      NOT_ON_TIMER, // PH 2 ** 43
      NOT_ON_TIMER, // PH 3 ** 44
      NOT_ON_TIMER, // PC 6 ** 45
      NOT_ON_TIMER, // PC 7 ** 46
      NOT_ON_TIMER, // PG 2 ** 47
      NOT_ON_TIMER, // PA 7 ** 48
      NOT_ON_TIMER, // PA 6 ** 49
      NOT_ON_TIMER, // PA 5 ** 50
      NOT_ON_TIMER, // PA 4 ** 51
      NOT_ON_TIMER, // PA 3 ** 52
      NOT_ON_TIMER, // PA 2 ** 53
      NOT_ON_TIMER, // PA 1 ** 54
      NOT_ON_TIMER, // PA 0 ** 55
      NOT_ON_TIMER, // PH 4 ** 56
      NOT_ON_TIMER, // PH 5 ** 57
      NOT_ON_TIMER, // PH 6 ** 58
      NOT_ON_TIMER, // PH 7 ** 59
      NOT_ON_TIMER, // PF 0 ** 60
      NOT_ON_TIMER, // PF 1 ** 61
      NOT_ON_TIMER, // PF 2 ** 62
      NOT_ON_TIMER, // PF 3 ** 63
      NOT_ON_TIMER, // PF 4 ** 64
      NOT_ON_TIMER, // PF 5 ** 65
      NOT_ON_TIMER, // PF 6 ** 66
      NOT_ON_TIMER, // PF 7 ** 67
    };

  #endif //ARDUINO_MAIN

#endif // ATmega3250, ATmega3290, ATmega6450, ATmega6490

#include "pins_bosl0v5.h"

#endif // Pins_Arduino_h
