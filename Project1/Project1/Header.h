#pragma once


#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;



enum Color { // Цвета дааааааааааааааааааааааааааааааааа
	Black		= 0,
	Blue		= 1,
	Green	    = 2,
	Cyan		= 3,
	Red			= 4,
	Magenta		= 5,
	Yellow		= 6,
	White		= 7,
	Grey		= 8,
	LightBlue	= 9,
	LightGreen  = 10,
	LightCyan	= 11,
	LightRed	= 12,
	LightYellow = 13,
	LightWhite	= 14,
};

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE); // Для изменения цвета консоли






