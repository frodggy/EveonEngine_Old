#pragma once

// string
typedef const char *str;

// ints
typedef signed long int i64;
typedef signed int i32;
typedef signed short i16;
typedef signed char i8;

// unsigned ints
typedef unsigned long int u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

// exit code
enum EV_EXIT_CODE
{
    EV_GRACEFUL_EXIT = 0,
    EV_EXIT = 1,
    EV_FAILED = -1,
};