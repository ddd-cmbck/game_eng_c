#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// disable debug and trace logging for release builds
#if KRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

// this enum is needed to have different levels of error detection
typedef enum log_level {
    LOG_LEVEL_FATAL = 0, // for something that can crush my program
    LOG_LEVEL_ERROR = 1, // serios error but program can still run
    LOG_LEVEL_WARN = 2, // warns for not optimal code
    LOG_LEVEL_INFO = 3, // basic level of logging
    LOG_LEVEL_DEBUG = 4, // specific for debug info       ( this both included only )
    LOG_LEVEL_TRACE = 5 // robust low level debug info    ( when debug mode is on   )
} log_level;


b8 initalise_logging();
void shutdown_logging();

// variadic function for displaing log messages
KAPI void log_output(log_level level, const char* message, ...); 

// logs a fatal-level messages
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef KERROR
// logs error-level message
#define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// logs warning-level message
#define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
// does nothing when LOG_WARN_ENABLED != 1
#define KWARN(messsage, ...)
#endif

#if LOG_INFO_ENABLED == 1
// logs info-level message
#define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// does nothing when LOG_WARN_ENABLED != 1
#define KINFO(messsage, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// logs debug-level message
#define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// does nothing when LOG_WARN_ENABLED != 1
#define KDEBUG(messsage, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// logs warning-level message
#define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// does nothing when LOG_WARN_ENABLED != 1
#define KTRACE(messsage, ...)
#endif
