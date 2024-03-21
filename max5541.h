// @File		MAX5541.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		19/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MAX5541_H
#define MAX5541_H

#define MAX5541_CS          PORTCbits.RC3
#define MAX5541_SDI         PORTCbits.RC1
#define MAX5541_SD0         PORTCbits.RC2
#define MAX5541_SCK         PORTCbits.RC0

#define MAX5541_CS_TRIS     TRISCbits.RC3
#define MAX5541_SDI_TRIS    TRISCbits.RC1
#define MAX5541_SDO_TRIS    TRISCbits.RC2
#define MAX5541_SCK_TRIS    TRISCbits.RC0

void MAX5541_write(unsigned int data)
{   
    MAX5541_CS = 0;
    
    for(unsigned int mask = 0x8000; mask; mask >>= 1)
    {
        if(data & mask) MAX5541_SDI = 1; else MAX5541_SDI = 0;
            
         __asm__ __volatile__("nop");
         MAX5541_SCK = 1;
         __asm__ __volatile__("nop");
         MAX5541_SCK = 0;
         __asm__ __volatile__("nop");    
    }
    
    MAX5541_CS = 1;
}

void MAX5541_Init(void)
{
    MAX5541_SCK_TRIS = 0;
    MAX5541_SDI_TRIS = 0;
    MAX5541_SDO_TRIS = 1;
    MAX5541_CS_TRIS = 0;
    
    MAX5541_CS = 1;
}

#endif
