//  Program:      nes-py
//  File:         cpu_opcodes.hpp
//  Description:  This file defines relevant CPU opcodes
//
//  Copyright (c) 2019 Christian Kauten. All rights reserved.
//

#ifndef CPUOPCODES_H_INCLUDED
#define CPUOPCODES_H_INCLUDED

const auto INSTRUCTION_MODE_MASK = 0x3;

const auto OPERATION_MASK = 0xe0;
const auto OPERATION_SHIFT = 5;

const auto ADRESS_MODE_MASK = 0x1c;
const auto ADDRESS_MODE_SHIFT = 2;

const auto BRANCH_INSTRUCTION_MASK = 0x1f;
const auto BRANCH_INSTRUCTION_MASK_RESULT = 0x10;
const auto BRANCH_CONDITION_MASK = 0x20;
const auto BRANCH_ON_FLAG_SHIFT = 6;

const auto NMI_VECTOR = 0xfffa;
const auto RESET_VECTOR = 0xfffc;
const auto IRQ_VECTOR = 0xfffe;

enum BranchOnFlag {
    Negative,
    Overflow,
    Carry,
    Zero
};

enum Operation1 {
    ORA,
    AND,
    EOR,
    ADC,
    STA,
    LDA,
    CMP,
    SBC,
};

enum AddrMode1 {
    IndexedIndirectX,
    ZeroPage,
    Immediate,
    Absolute,
    IndirectY,
    IndexedX,
    AbsoluteY,
    AbsoluteX,
};

enum Operation2 {
    ASL,
    ROL,
    LSR,
    ROR,
    STX,
    LDX,
    DEC,
    INC,
};

enum AddrMode2 {
    Immediate_,
    ZeroPage_,
    Accumulator,
    Absolute_,
    Indexed         = 5,
    AbsoluteIndexed = 7,
};

enum Operation0 {
    BIT  = 1,
    STY  = 4,
    LDY,
    CPY,
    CPX,
};

enum OperationImplied {
    NOP = 0xea,
    BRK = 0x00,
    JSR = 0x20,
    RTI = 0x40,
    RTS = 0x60,

    JMP  = 0x4C,
    JMPI = 0x6C, //JMP Indirect

    PHP = 0x08,
    PLP = 0x28,
    PHA = 0x48,
    PLA = 0x68,

    DEY = 0x88,
    DEX = 0xca,
    TAY = 0xa8,
    INY = 0xc8,
    INX = 0xe8,

    CLC = 0x18,
    SEC = 0x38,
    CLI = 0x58,
    SEI = 0x78,
    TYA = 0x98,
    CLV = 0xb8,
    CLD = 0xd8,
    SED = 0xf8,

    TXA = 0x8a,
    TXS = 0x9a,
    TAX = 0xaa,
    TSX = 0xba,
};

//0 implies unused opcode
int OperationCycles[0x100] = {
    7, 6, 0, 0, 0, 3, 5, 0, 3, 2, 2, 0, 0, 4, 6, 0,
    2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 0, 0, 0, 4, 7, 0,
    6, 6, 0, 0, 3, 3, 5, 0, 4, 2, 2, 0, 4, 4, 6, 0,
    2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 0, 0, 0, 4, 7, 0,
    6, 6, 0, 0, 0, 3, 5, 0, 3, 2, 2, 0, 3, 4, 6, 0,
    2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 0, 0, 0, 4, 7, 0,
    6, 6, 0, 0, 0, 3, 5, 0, 4, 2, 2, 0, 5, 4, 6, 0,
    2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 0, 0, 0, 4, 7, 0,
    0, 6, 0, 0, 3, 3, 3, 0, 2, 0, 2, 0, 4, 4, 4, 0,
    2, 6, 0, 0, 4, 4, 4, 0, 2, 5, 2, 0, 0, 5, 0, 0,
    2, 6, 2, 0, 3, 3, 3, 0, 2, 2, 2, 0, 4, 4, 4, 0,
    2, 5, 0, 0, 4, 4, 4, 0, 2, 4, 2, 0, 4, 4, 4, 0,
    2, 6, 0, 0, 3, 3, 5, 0, 2, 2, 2, 0, 4, 4, 6, 0,
    2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 0, 0, 0, 4, 7, 0,
    2, 6, 0, 0, 3, 3, 5, 0, 2, 2, 2, 2, 4, 4, 6, 0,
    2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 0, 0, 0, 4, 7, 0,
};

#endif // CPUOPCODES_H_INCLUDED
