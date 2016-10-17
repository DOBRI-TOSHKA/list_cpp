#ifndef LIST_ERR_H
#define LIST_ERR_H

#include <cstring>

enum list_err{
    ITS_OK = 0,
    BAD_BOUNDARY = -1,
    EMPTY_LIST = -2,
    NULL_POINTER = 3
};

const std::string list_err_str[] = {
    "ITS_OK",
    "BAD_BOUNDARY",
    "EMPTY_LIST",
    "NULL_POINTER"
};


#endif // LIST_ERR_H
