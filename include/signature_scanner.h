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
    // Returns the offset, or -1 if not found
    template <int size> int scan(Signature<size> sig, std::span<uint8_t> span) {
        for (int offset = 0; offset < span.size() - size; offset++) {
            bool found = true;
            int sig_byte = 0;
            while (sig_byte < size) {
                if (!sig.bytes[sig_byte].known) {
                    sig_byte++;
                }
                else if (span[offset + sig_byte] != sig.bytes[sig_byte].byte) {
                    found = false;
                    sig_byte = 0;
                    break;
                }

                sig_byte++;
            }

            if (found) {
                return offset;
            }
        }

        return -1;
    }
};


#endif //CHUNI_SCALER_SIGNATURE_SCANNER_H
