// ---------------------------------------------------------------------------------
//  xigo_types.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#ifndef CLT_xigo_types_h
#define CLT_xigo_types_h

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned long      uint32;
typedef unsigned long long uint64;

#ifndef NULL
#define NULL nullptr
#endif

typedef enum {
    XIGO_SUCCESS = 0,
    XIGO_FAILURE
} XIGO_status_e;

#endif
