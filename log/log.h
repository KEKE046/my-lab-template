#pragma once

#include<log/config.h>

#include"ansiterm.h"

#include<fstream>
#include<iostream>
#include<exception>
#include<string>

#ifndef LOG_COLOR_DEBUG
#  define LOG_COLOR_DEBUG AT_BRI_BLK
#endif
#ifndef LOG_COLOR_INFO
#  define LOG_COLOR_INFO AT_RESET
#endif
#ifndef LOG_COLOR_NOTIFY
#  define LOG_COLOR_NOTIFY AT_BRI_GRN
#endif
#ifndef LOG_COLOR_PROCESS
#  define LOG_COLOR_PROCESS AT_BRI_MAG
#endif
#ifndef LOG_COLOR_WARNING
#  define LOG_COLOR_WARNING AT_BRI_YLW
#endif
#ifndef LOG_COLOR_ERROR
#  define LOG_COLOR_ERROR AT_BRI_RED
#endif

inline std::ostream & slog(std::ostream & out) { return out << AT_RESET; }

template<typename T1, typename ... T> std::ostream & slog(std::ostream & out, const T1 & first, const T & ... data) {
    out << first; return slog(out, data...);
}

// debug
template<typename ... T> std::ostream & elogd(const T & ... data) {
#ifdef LOG_DEBUG
    return slog(std::cerr, LOG_COLOR_DEBUG, data..., AT_RESET, "\n");
#else
    return std::cerr;
#endif
}

// info, notify, process, warning, error
template<typename ... T> std::ostream & elogi(const T & ... data) { return slog(std::cerr, LOG_COLOR_INFO, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & elogn(const T & ... data) { return slog(std::cerr, LOG_COLOR_NOTIFY, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & elogp(const T & ... data) { return slog(std::cerr, LOG_COLOR_PROCESS, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & elogw(const T & ... data) { return slog(std::cerr, LOG_COLOR_WARNING, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & eloge(const T & ... data) { extern std::string getbt(int); return slog(std::cerr, LOG_COLOR_ERROR, data..., AT_RESET, "\n", getbt(2));}

// debug
template<typename ... T> std::ostream & logd(const T & ... data) {
#ifdef LOG_DEBUG
    return slog(std::cout, LOG_COLOR_DEBUG, data..., AT_RESET, "\n");
#else
    return std::cout;
#endif
}

// info, notify, process, warning, error
template<typename ... T> std::ostream & logi(const T & ... data) { return slog(std::cout, LOG_COLOR_INFO, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & logn(const T & ... data) { return slog(std::cout, LOG_COLOR_NOTIFY, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & logp(const T & ... data) { return slog(std::cout, LOG_COLOR_PROCESS, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & logw(const T & ... data) { return slog(std::cout, LOG_COLOR_WARNING, data..., AT_RESET, "\n"); }
template<typename ... T> std::ostream & loge(const T & ... data) { extern std::string getbt(int); return slog(std::cout, LOG_COLOR_ERROR, data..., AT_RESET, "\n", getbt(2));}

// clear the screen
inline std::ostream & logc() {return slog(std::cout, AT_ERASE_ALL, AT_CUR_POS_HOME);}

#ifdef LOG_LINE_NUM

#  ifdef SOURCE_PATH_SIZE
#    define __FILENAME__ __FILE__ + SOURCE_PATH_SIZE
#  else
#    define __FILENAME__ __FILE__
#  endif

#  define elogd(...) elogd(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define elogi(...) elogi(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define elogn(...) elogn(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define elogp(...) elogp(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define elogw(...) elogw(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define eloge(...) eloge(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)

#  define logd(...) logd(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define logi(...) logi(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define logn(...) logn(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define logp(...) logp(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define logw(...) logw(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)
#  define loge(...) loge(__FILENAME__, ':', __LINE__, ' ',##__VA_ARGS__)

#endif

// simple assert
#define assert(s, ...) do { if(!s) {loge(__VA_ARGS__); throw std::runtime_error("assert fail");}} while(0)

// check a unix call return value >=0, if <0, return his return value
#define ckret(statement) do{ int r = (statement); if(r < 0) return r; } while(0)