#ifndef CANOPEN_SKP_H
#define CANOPEN_SKP_H

void CO_setup(void);
void CO_loop(void);
#define ON  LOW
#define OFF HIGH

#define LED_R 39
#define LED_B 40
#define LED_G 38

#define LED_CO_RUN 16   
#define LED_CO_ERR 17
#define LED3        3
#define LED4        46

#define SW1         7
#define SW2         15

#define POT_P1      5
#define POT_P2      6

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif