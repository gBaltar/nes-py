//  Program:      nes-py
//  File:         mapper_CNROM.cpp
//  Description:  An implementation of the CNROM mapper
//
//  Copyright (c) 2019 Christian Kauten. All rights reserved.
//

#include "mappers/mapper_CNROM.hpp"
#include "log.hpp"

MapperCNROM::MapperCNROM(Cartridge& cart) : Mapper(cart), m_selectCHR(0) {
    m_oneBank = cart.getROM().size() == 0x4000;
};

NES_Byte MapperCNROM::readPRG(NES_Address addr) {
    if (!m_oneBank)
        return m_cartridge.getROM()[addr - 0x8000];
    // mirrored
    else
        return m_cartridge.getROM()[(addr - 0x8000) & 0x3fff];
}

const NES_Byte* MapperCNROM::getPagePtr(NES_Address addr) {
    if (!m_oneBank)
        return &m_cartridge.getROM()[addr - 0x8000];
    // mirrored
    else
        return &m_cartridge.getROM()[(addr - 0x8000) & 0x3fff];
}

void MapperCNROM::writeCHR(NES_Address addr, NES_Byte value) {
    LOG(Info) << "Read-only CHR memory write attempt at " << std::hex << addr << std::endl;
}
