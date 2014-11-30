// ---------------------------------------------------------------------------------
//  xigo_time.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------
#ifndef CLT_xigo_time_h
#define CLT_xigo_time_h

#include "xigo_component.h"
#include "xigo_string.h"

#define XIGO_IID_Time 0x00000060
#define XIGO_CID_Time 0x00000060

typedef unsigned long long XIGO_time_ms_t;

XIGO_COMPONENT_DECL_START( Time )
    XIGO_status_e Get( XIGO_time_ms_t *ms );
    XIGO_status_e GetTimestamp( XIGO_time_ms_t *ms, XIGO_string_t string );
    XIGO_status_e ConvertMillisecondTimeToString( XIGO_time_ms_t *ms, XIGO_string_t string );
XIGO_COMPONENT_DECL_END( Time )

#endif
