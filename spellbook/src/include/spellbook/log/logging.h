#ifndef au_loggin_h
#define au_loggin_h

// standard includes
#include <stdio.h>
#include <iostream>

// project includes
#include <spellbook/term/term.h>

#define AU_LOG_LEVEL_DEBUG 0   // extended-information of normal usage
#define AU_LOG_LEVEL_INFO  1   // normal usage
#define AU_LOG_LEVEL_CRIT  2   // important normal usage
#define AU_LOG_LEVEL_WARN  3   // existential cases that are gracefully handled
#define AU_LOG_LEVEL_ERROR 4   // existential cases that may have unintended consequences
#define AU_LOG_LEVEL_FATAL 5   // unrecoverable errors that result in program termination

#ifndef AU_LOG_LEVEL
#define AU_LOG_LEVEL AU_LOG_LEVEL_INFO
#endif

#define AU_LOG_FILENAME_ONLY 1

#define AU_LOG_MSG_PADDING 120

namespace au {

char* padded(const char* str, ...);
const char* filename(const char* path);


} // namespace au

#define AU_LOG_STREAM_FIXED(stream, color, pre, msg, ...) \
{\
    stream << color << pre << au::padded(msg, ##__VA_ARGS__) << " | " << au::filename(__FILE__) << ':' << __LINE__ << au::term::nocolor << std::endl;\
}

#define AU_LOG_STDOUT_FIXED(pre, msg, ...) \
{\
    AU_LOG_STREAM_FIXED(std::cout, au::term::white, pre, msg, ##__VA_ARGS__)\
}

#define AU_LOG_STDERR_FIXED(pre, msg, ...) \
{\
    AU_LOG_STREAM_FIXED(std::cerr, au::term::red, pre, msg, ##__VA_ARGS__)\
}

#define AU_LOG_STDOUT(pre, msg, ...) \
{\
    printf(pre msg "| %s:%d\n", ##__VA_ARGS__, au::filename(__FILE__), __LINE__);\
    fflush(stdout);\
}

#define AU_LOG_STDERR(pre, msg, ...) \
{\
    fprintf(stderr, pre msg " | %s:%d\n", ##__VA_ARGS__, au::filename(__FILE__), __LINE__);\
}

#if AU_LOG_LEVEL <= AU_LOG_LEVEL_DEBUG
#define AU_DEBUG(msg, ...) AU_LOG_STDOUT_FIXED("[DEBUG] ", msg, ##__VA_ARGS__)
#else
#define AU_DEBUG(msg, ...)
#endif

#if AU_LOG_LEVEL <= AU_LOG_LEVEL_INFO
#define AU_INFO(msg, ...)  AU_LOG_STDOUT_FIXED("[INFO]  ", msg, ##__VA_ARGS__)
#else
#define AU_INFO(msg, ...)
#endif

#if AU_LOG_LEVEL <= AU_LOG_LEVEL_CRIT
#define AU_CRIT(msg, ...)  AU_LOG_STDOUT_FIXED("[CRIT]  ", msg, ##__VA_ARGS__)
#else
#define AU_CRIT(msg, ...)
#endif

#if AU_LOG_LEVEL <= AU_LOG_LEVEL_CRIT
#define AU_WARN(msg, ...)  AU_LOG_STDERR_FIXED("[WARN]  ", msg, ##__VA_ARGS__)
#else
#define AU_WARN(msg, ...)
#endif

#if AU_LOG_LEVEL <= AU_LOG_LEVEL_ERROR
#define AU_ERROR(msg, ...) AU_LOG_STDERR_FIXED("[ERROR] ", msg, ##__VA_ARGS__)
#else
#define AU_ERROR(msg, ...)
#endif

#if AU_LOG_LEVEL <= AU_LOG_LEVEL_FATAL
#define AU_FATAL(msg, ...) AU_LOG_STDERR_FIXED("[FATAL] ", msg, ##__VA_ARGS__)
#else
#define AU_FATAL(msg, ...)
#endif

// TODO: relative or base path filename
// TODO: configure filename and line number (env variable similar to ROS?)
// TODO: compile-time level configuration
// TODO: run-time level configuration
// TODO: named prints
// TODO: thread-specific prints
// TODO: multiple destinations to write to
// TODO: colored terminal output and compile-time configuration
// TODO: mt logger? maybe differently named loggers can be accessed in a mt manner
// TODO: configuration of buffering
// TODO: column-padding

#endif
