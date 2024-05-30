//
// Created by pneuma on 5/29/2024.
//

#include "../include/signature_scanner.h"

#include <Windows.h>
#include <Psapi.h>

SignatureScanner::SignatureScanner() {
    auto proc = GetCurrentProcess();
    auto mod = GetModuleHandle(nullptr);

    MODULEINFO info;
    auto success = GetModuleInformation(proc, mod, &info, sizeof(info));
    if (!success) {
        return;
    }

    this->base = static_cast<uint8_t *>(info.lpBaseOfDll);
    this->module = std::span<uint8_t> {this->base, info.SizeOfImage};
}
