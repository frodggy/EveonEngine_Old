#pragma once

typedef const char *str;
enum EV_EXIT_CODE
{
    EV_GRACEFUL_EXIT = 0,
    EV_EXIT = 1,
    EV_FAILED = -1,
};