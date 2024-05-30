# signature_scanner

A work-in-progress signature scanner that scans a span of memory for patterns in the form `FB D3 ?? 35 28 ??` or `FB D3 ? 35 28 ?`. Patterns are parsed from strings at compile time rather than at runtime. The first match is returned, and if it is not found, `nullptr` is returned.

## Installation

This library can be installed using CMake's `FetchContent` as follows:
```cmake
FetchContent_Declare(
        signature-scanner
        GIT_REPOSITORY "https://github.com/jpdown/signature-scanner"
        GIT_TAG "4fe7119e276e0ed0ccb6ddd0510b43a0efc0ac37"
)
FetchContent_MakeAvailable(signature-scanner)
```
This will make the library available by including `"signature.h"` as well as `"signature_scanner.h"`.

Make sure to replace the tag with the commit that you would like to use (likely the newest).