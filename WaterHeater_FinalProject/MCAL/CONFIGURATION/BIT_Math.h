/*
 * BIT_Math.h
 *
 * Created: 13/12/2024 4:34:07 PM
 *  Author: zyade
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* ------------------------->Bit Math              */
#define set_bit(reg,bit) reg|=(1<<bit)
#define clr_bit(reg,bit) reg&=~(1<<bit)
#define tgl_bit(reg,bit) reg^=(1<<bit)
#define get_bit(reg,bit) ((reg>>bit)&0x01)




#endif /* BIT_MATH_H_ */