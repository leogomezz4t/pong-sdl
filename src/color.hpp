#pragma once
#include <inttypes.h>

class Color {
    public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    // Constants
    static Color BLACK;
    static Color WHITE;
    static Color GRAY;
};

