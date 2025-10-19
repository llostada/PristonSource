#pragma once
// Unified trig accessors for shared/game/server.
// If the game already defines PTCOS/PTSEN macros, we use them as-is.
// Otherwise we provide fallback storage (gPTCOS/gPTSEN) from pt_trig.cpp
// and also define compatibility aliases so existing code using PTCOS[i]
// continues to compile.

// Accessor wrappers (prefer using these in new code)
#ifdef PTCOS
inline int PT_GET_COS(int i) { return PTCOS[(i) & 0xFFF]; }
#else
extern int gPTCOS[4096];
inline int PT_GET_COS(int i) { return gPTCOS[(i) & 0xFFF]; }
#endif

#ifdef PTSEN
inline int PT_GET_SIN(int i) { return PTSEN[(i) & 0xFFF]; }
#else
extern int gPTSEN[4096];
inline int PT_GET_SIN(int i) { return gPTSEN[(i) & 0xFFF]; }
#endif

// Back-compat: if PTCOS/PTSEN are not defined by the game,
// map them to the fallback arrays so code like PTCOS[idx] still works.
#ifndef PTCOS
#define PTCOS gPTCOS
#endif
#ifndef PTSEN
#define PTSEN gPTSEN
#endif
