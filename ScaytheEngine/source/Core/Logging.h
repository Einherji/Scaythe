//
// Created by matthiaso on 6/8/21.
//
#ifndef SCAYTHE_CORE_LOGGING
#define SCAYTHE_CORE_LOGGING

#include "Base.h"
#include <stdio.h>

namespace Scaythe {
    class Logging {
    public:
        void Log();
        inline static char* str = "lib";
    };
}

#endif

