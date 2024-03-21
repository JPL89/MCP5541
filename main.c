// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		17/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "ks0066.h"
#include "wire.h"
#include "max5820.h"

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    MAX5541_Init();
    
    MAX5541_write(1023);
    
    
    while(1);
    
    return;
}
