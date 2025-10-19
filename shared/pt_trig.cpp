#include <cmath>
#include "pt_trig.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Only provide fallback storage if the game macros are NOT present
#ifndef PTCOS
int gPTCOS[4096];
int gPTSEN[4096];

struct PTTrigInit {
    PTTrigInit() {
        for (int i = 0; i < 4096; ++i) {
            double ang = (double)i * (2.0 * M_PI / 4096.0);
            gPTCOS[i] = (int)std::lround(std::cos(ang) * 256.0);
            gPTSEN[i] = (int)std::lround(std::sin(ang) * 256.0);
        }
    }
} _pttriginit;
#endif