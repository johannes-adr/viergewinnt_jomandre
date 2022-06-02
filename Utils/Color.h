//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.



#define C_RESET   "\033[0m"
#define C_RED     "\033[31m"      /* Red */
#define C_YELLOW  "\033[33m"      /* Yellow */
#define C_WHITE   "\033[37m"      /* White */
/*
#define C_BLACK   "\033[30m"

#define C_GREEN   "\033[32m"
#define C_BLUE    "\033[34m"
#define C_MAGENTA "\033[35m"
#define C_CYAN    "\033[36m"

#define C_BOLDBLACK   "\033[1m\033[30m"
#define C_BOLDRED     "\033[1m\033[31m"
#define C_BOLDGREEN   "\033[1m\033[32m"
#define C_BOLDYELLOW  "\033[1m\033[33m"
#define C_BOLDBLUE    "\033[1m\033[34m"
#define C_BOLDMAGENTA "\033[1m\033[35m"
#define C_BOLDCYAN    "\033[1m\033[36m"
#define C_BOLDWHITE   "\033[1m\033[37m"
*/

std::string white(std::string &s){
    return C_WHITE + s + C_RESET;
}

std::string red(std::string &s){
    return C_RED + s + C_RESET;
}

std::string yellow(std::string &s){
    return C_YELLOW + s + C_RESET;
}

