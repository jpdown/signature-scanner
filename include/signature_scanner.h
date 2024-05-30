//
// Created by pneuma on 5/29/2024.
//

#ifndef CHUNI_SCALER_SIGNATURE_SCANNER_H
#define CHUNI_SCALER_SIGNATURE_SCANNER_H

#include <string>
#include <span>

#include "signature.h"

class SignatureScanner {
public:
    SignatureScanner();

    // Returns the absolute address
    template <int size> void *scan(Signature<size> sig) {
        for (int offset = 0; offset < module.size() - size; offset++) {
            bool found = true;
            int sig_byte = 0;
            while (sig_byte < size) {
                if (!sig.bytes[sig_byte].known) {
                    sig_byte++;
                }
                else if (module[offset + sig_byte] != sig.bytes[sig_byte].byte) {
                    found = false;
                    sig_byte = 0;
                    break;
                }

                sig_byte++;
            }

            if (found) {
                return this->base + offset;
            }
        }

        return nullptr;
    }
private:
    std::span<uint8_t> module;
    uint8_t *base;
};


#endif //CHUNI_SCALER_SIGNATURE_SCANNER_H
