#pragma once

#include <iostream>

#define DEBUG 1

// event system debug log macros
#define EVENT_DBG 1
#define IDLE_EVENT_DBG 0

#if DEBUG == 1
    #if EVENT_DBG == 1
        #define LOG_EVENT(x) std::cout << x << std::endl;
    #else
        #define LOG_EVENT(x)
    #endif

    #if IDLE_EVENT_DBG == 1
        #define LOG_IDLE_EVENT(x) std::cout << x << std::endl;
    #else
        #define LOG_IDLE_EVENT(x)
    #endif

    #define LOG(x) std::cout << x << std::endl;
#else
    #define LOG_EVENT(x)
    #define LOG_IDLE_EVENT(x)
    #define LOG(x)
#endif