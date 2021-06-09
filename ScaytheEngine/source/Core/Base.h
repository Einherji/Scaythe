//
// Created by matthiaso on 6/8/21.
//
#ifndef SCAYTHE_CORE_BASE
#define SCAYTHE_CORE_BASE

#ifdef SCAYTHE_SYS_WIN
    #ifdef SCAYTHE_LIB
        #define SCAYHTE_API __declspec(dllexport)
    #else
        #define SCAYTHE_API __declspec(dllimport)
    #endif
#else
    #ifdef SCAYTHE_LIB
        #define SCAYHTE_API __attribute__((visibility("default")))
    #else
        #define SCAYTHE_API
    #endif
#endif

#endif
