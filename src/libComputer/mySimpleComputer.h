#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#define Flag_mem 1
#define Flag_file 2
#define Flag_val 3
#define Flag_com 4


#define BIT_SET(X, Y) X = X | (1 << (Y - 1)) //устанавалиет единицу
#define BIT_DEL(X, Y) X = X & (~(1 << (Y - 1))) //устанавливает ноль
#define BIT_GET(X, Y) X >> (Y - 1) & 0x1 //возвращает нужный бит

const int Operations[38] = {
	10, 11,  //Операции ввода/вывода
	20, 21, //Операции загрузки / выгрузки в аккумулятор
	30, 31, 32, 33, //Арифметические операции
	40,41,42,43, //Операции передачи управления
	51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, //
		62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, //Пользовательские функции
			73, 74, 76}; //


#define memory_size 100
static int sc_memory[memory_size];


static int  sc_registr;
int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
//int sc_memorySave(char* filename);
//int sc_memoryLoad(char* filename);
int regInit();
int sc_regSet(int registr, int value);
int sc_regGet(int register, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);
#endif
