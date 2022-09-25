#ifndef MACROS_H
#define MACROS_H
// boolean values
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

// Set a certain bit in any register
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

//Clear a certain bit in any register
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

// Toggle a certain bit in any register
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

// Read a certain bit in any register
#define READ_BIT(REG,BIT)  (( REG &(1<< BIT) ) >> BIT)

// Check if a specific bit is set in any register and return true if yes
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

// Check if a specific bit is cleared in any register and return true if yes
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

// macros for ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'
//macros for pin no.s
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
// macros for voltage values
#define LOW 0
#define HIGH 1
// macros for directions
#define IN 0
#define OUT 1
// macros for number of ports and pins
#define NUM_OF_PINS_PER_PORT 8
#define NUM_OF_PORTS 4
// macros for error free and error
#define OK 1
#define ERROR 0

#endif
