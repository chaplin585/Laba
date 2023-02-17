#include "mySimpleComputer.h"

int sc_memoryInit() {
    for (int i = 0; i <= memory_size; ++i) {
        sc_memory[i] = 0;
    }
    return 0;

}

int sc_memorySet(int address, int value) {
    if (address > memory_size || address < 0) {
        cout << "error" << endl;
    }
    else {
        sc_memory[address] = value;

    }
    return 0;
}

int sc_memoryGet(int address, int value) {
    if (address > memory_size || address < 0) {

    }
    else {

        value = sc_memory[address];

    }
    return 0;
}

/*int sc_memorySave(char* filename) {
    FILE* sc_file;
    if ((sc_file = fopen(filename, "f")) == NULL) {

    }
    else {
        for (int i = 0; i < memory_size; i++) {
            fwrite(sc_memory, sizeof(int), memory_size, sc_file);
        }
    }
    return 0;
}

int sc_memoryLoad(char* filename) {
    FILE* sc_file;
    if ((sc_file = fopen(filename, "r+")) == NULL) {

    }
    else {
        fread(sc_memory, sizeof(int), memory_size, sc_file);
    }
    return 0;
}*/

int regInit() {
    sc_registr &= 0;
    return 0;
}

int sc_regSet(int registr, int value) {
    if (registr <= 3 && registr > 0) {
        if (value) {
            if (value == 1) {
                BIT_SET(sc_registr, registr);
            }
            else {
                BIT_SET(sc_registr, Flag_val);
            }
        }
        else {
            BIT_DEL(sc_registr, registr);
        }
    }
    else {
        sc_regSet(Flag_val, sc_registr);
        return -3;
    }
        
    return 0;

}

int sc_regGet(int registr, int* value) {
    *value = BIT_GET(sc_registr, registr);
    return 0;
}

int sc_commandEncode(int command, int operand, int* value) {
    bool check = false;
    for (int i = 0; i < sizeof(Operations); i++) {
        if (Operations[i] == command) {
            check = true;
            break;
        }
        else {
            check = false;
        }
    }
    if (check == true) {
        *value = (command << 7) | operand;
        return 0;
    }
    else {
        return -4;
    }    
}

int sc_commandDecode(int value, int* command, int* operand) {
    int checkbit;
    bool check;
    checkbit = BIT_GET(value, 14);
    if (checkbit == 0) {
        *command = (value >> 7);
        value -= ((value >> 7) << 7);
        *operand = value;  
    }
    else {
        sc_regSet(Flag_com, 1);
        return -4;
    }

}

