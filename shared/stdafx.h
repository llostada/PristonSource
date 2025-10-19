#pragma once
#define NOMINMAX
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

// Cabeçalhos do próprio projeto que são comuns no "shared"
#include "common.h"
#include "packets.h"
#include "def.h"
#include "strings.h"
#include "CMutex.h"
#if __has_include("../server/server/Logger.h")
#include "../server/server/Logger.h"
#else
#include "../game/game/Logger.h"
#endif
// Mantém o include do globals (de onde vêm WARN/INFO/etc)
#include "../server/server/globals.h"
#define IDI_ICON2			107

// Linkagem (mantém como está)
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Imagehlp.lib")
#pragma comment(lib, "imm32.lib")