# signature_scanner

A work-in-progress signature scanner that scans a span of memory for patterns in the form `FB D3 ?? 35 28 ??` or `FB D3 ? 35 28 ?`. Patterns are parsed from strings at compile time rather than at runtime. The first match is returned, and if it is not found, `nullptr` is returned.

## Installation

Simply place the `signature.h` file in your project and include it.