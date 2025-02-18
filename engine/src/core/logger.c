#include "logger.h"
#include "assert.h"

// TODO: temp
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


b8 initalise_logging() {
    // TODO: create log file
    return TRUE;
}

void shutdown_logging() {
    // TODO: cleanup logging/write queued entries(in future i will do it in different thread)
}

void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    b8 is_error = level < 2;

    // im trying to avoid memalloc on a heap :)
    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    // i got a strange error here so i decided to use a __builtin_va_list instead va_list
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char out_message_2[32000];
    sprintf(out_message_2, "%s%s\n", level_strings[level], out_message);

    // TODO: this is platform specific
    printf("%s", out_message_2);
}

//implementation for asserts.h
KAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line){
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}