#pragma once

#include<log/config.h>

#ifndef ANSITERM_DISABLE

    #define AT_BLK "\033[30m"
    #define AT_RED "\033[31m"
    #define AT_GRN "\033[32m"
    #define AT_YLW "\033[33m"
    #define AT_BLU "\033[34m"
    #define AT_MAG "\033[35m"
    #define AT_CYN "\033[36m"
    #define AT_WHT "\033[37m"
    #define AT_BRI_BLK "\033[90m"
    #define AT_GRY AT_BRI_BLK
    #define AT_BRI_RED "\033[91m"
    #define AT_BRI_GRN "\033[92m"
    #define AT_BRI_YLW "\033[93m"
    #define AT_BRI_BLU "\033[94m"
    #define AT_BRI_MAG "\033[95m"
    #define AT_BRI_CYN "\033[96m"
    #define AT_BRI_WHT "\033[97m"

    #define AT_BG_BLK "\033[40m"
    #define AT_BG_RED "\033[41m"
    #define AT_BG_GRN "\033[42m"
    #define AT_BG_YLW "\033[43m"
    #define AT_BG_BLU "\033[44m"
    #define AT_BG_MAG "\033[45m"
    #define AT_BG_CYN "\033[46m"
    #define AT_BG_WHT "\033[47m"
    #define AT_BG_BRT_BLK "\033[100m"
    #define AT_BG_GRY AT_BG_BRT_BLK
    #define AT_BG_BRI_RED "\033[101m"
    #define AT_BG_BRI_GRN "\033[102m"
    #define AT_BG_BRI_YLW "\033[103m"
    #define AT_BG_BRI_BLU "\033[104m"
    #define AT_BG_BRI_MAG "\033[105m"
    #define AT_BG_BRI_CYN "\033[106m"
    #define AT_BG_BRI_WHT "\033[107m"

    #define AT_RESET "\033[0m"
    #define AT_BOLD "\033[1m"
    #define AT_FAINT "\033[2m"
    #define AT_ITALIC "\033[3m"
    #define AT_UNDERLINE "\033[4m"
    #define AT_SLOW_BLINK "\033[5m"
    #define AT_RAPID_BLINK "\033[6m"
    #define AT_INVERT "\033[7m"
    
    #define AT_CUR_UP "\033[A"
    #define AT_CUR_DOWN "\033[B"
    #define AT_CUR_LEFT "\033[C"
    #define AT_CUR_RIGHT "\033[D"

    #define AT_ERASE_TO_END "\033[0J"
    #define AT_ERASE_TO_BEGIN "\033[1J"
    #define AT_ERASE_ALL "\033[2J"
    
    #define AT_CUR_POS_HOME "\033[;H"

#else

    #define AT_BLK ""
    #define AT_RED ""
    #define AT_GRN ""
    #define AT_YLW ""
    #define AT_BLU ""
    #define AT_MAG ""
    #define AT_CYN ""
    #define AT_WHT ""
    #define AT_BRI_BLK ""
    #define AT_GRY AT_BRI_BLK
    #define AT_BRI_RED ""
    #define AT_BRI_GRN ""
    #define AT_BRI_YLW ""
    #define AT_BRI_BLU ""
    #define AT_BRI_MAG ""
    #define AT_BRI_CYN ""
    #define AT_BRI_WHT ""

    #define AT_BG_BLK ""
    #define AT_BG_RED ""
    #define AT_BG_GRN ""
    #define AT_BG_YLW ""
    #define AT_BG_BLU ""
    #define AT_BG_MAG ""
    #define AT_BG_CYN ""
    #define AT_BG_WHT ""
    #define AT_BG_BRT_BLK ""
    #define AT_BG_GRY AT_BG_BRT_BLK
    #define AT_BG_BRI_RED ""
    #define AT_BG_BRI_GRN ""
    #define AT_BG_BRI_YLW ""
    #define AT_BG_BRI_BLU ""
    #define AT_BG_BRI_MAG ""
    #define AT_BG_BRI_CYN ""
    #define AT_BG_BRI_WHT ""

    #define AT_RESET ""
    #define AT_BOLD ""
    #define AT_FAINT ""
    #define AT_ITALIC ""
    #define AT_UNDERLINE ""
    #define AT_SLOW_BLINK ""
    #define AT_RAPID_BLINK ""
    #define AT_INVERT ""
    #define AT_CLEAR ""

    #define AT_CUR_UP ""
    #define AT_CUR_DOWN ""
    #define AT_CUR_LEFT ""
    #define AT_CUR_RIGHT ""

    #define AT_ERASE_TO_END ""
    #define AT_ERASE_TO_BEGIN ""
    #define AT_ERASE_ALL ""
    
    #define AT_CUR_POS_HOME ""
#endif