/*
 * BIT_MATH.h
 *
 * Created: 6/25/2021 10:34:31 PM
 *  Author: karim
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//Define BIT MATH, Macro like function
#define SET_BIT(REG,PIN) REG|=(1<<PIN)//Logic(1)
#define CLR_BIT(REG,PIN) REG&=~(1<<PIN)//Logic(0)
#define TGL_BIT(REG,PIN) REG^=(1<<PIN)//Not gate
#define GET_BIT(REG,PIN) ((REG>>PIN)&1)//Read value


#endif /* BIT_MATH_H_ */