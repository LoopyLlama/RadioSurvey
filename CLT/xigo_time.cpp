// ---------------------------------------------------------------------------------
//  xigo_file.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------
#include <sys/time.h>
#include <stdio.h>
#include "xigo_time.h"

XIGO_Time::XIGO_Time()
{
    
}

XIGO_Time::~XIGO_Time()
{
    
}

XIGO_status_e XIGO_Create_Time( uint32 cid, void **pp )
{
    XIGO_status_e status = XIGO_FAILURE;
    
    *pp = new XIGO_Time();
    if( pp != NULL )
    {
        XIGO_Time *pTime = (XIGO_Time*)*pp;
        status = pTime->Create( cid, 0, pp );
    }
    return status;
}

XIGO_status_e XIGO_Destroy_Time( void **pp )
{
    XIGO_status_e status = XIGO_FAILURE;
    
    if( pp != NULL )
    {
        XIGO_Time *pTime = (XIGO_Time*)*pp;
        status = pTime->Destroy( pp );
        delete (XIGO_Time*)*pp;
    }
    return status;
}

XIGO_status_e XIGO_Time::Create( uint32 cid, uint32 iid, void **pp )
{
    return XIGO_SUCCESS;
}

XIGO_status_e XIGO_Time::Destroy( void **pp )
{
    return XIGO_SUCCESS;
}

XIGO_status_e XIGO_Time::Get( XIGO_time_ms_t *ms )
{
    XIGO_status_e  status = XIGO_FAILURE;
    
    if( ms != NULL )
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        *ms = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
        status = XIGO_SUCCESS;
    }
    return status;
}

XIGO_status_e XIGO_Time::GetTimestamp( XIGO_time_ms_t *ms, XIGO_string_t string )
{
    XIGO_status_e  status = XIGO_FAILURE;
    
    if( string != NULL )
    {
        struct timeval tv;
        time_t nowtime;
        struct tm *x_tm;
        char tmbuf[64];
        
        gettimeofday(&tv, NULL);
        nowtime = tv.tv_sec;
        x_tm = localtime(&nowtime);
        
        if( ms != NULL )
        {
            *ms = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
            
            XIGO_time_ms_t residual_ms = *ms - tv.tv_sec * 1000;
        
            strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d %H:%M:%S", x_tm);
            snprintf(string, sizeof tmbuf, "%s.%03d", tmbuf, (int)residual_ms );
        
            status = XIGO_SUCCESS;
        }
    }
    return status;
}

XIGO_status_e XIGO_Time::ConvertMillisecondTimeToString( XIGO_time_ms_t *ms, XIGO_string_t string )
{
    XIGO_status_e  status = XIGO_FAILURE;
    
    if( ms != NULL && string != NULL )
    {
        time_t       secs = *ms / 1000;
        struct tm   *x_tm;
        char         tmbuf[64];
        
        XIGO_time_ms_t residual_ms;
        
        residual_ms = *ms - secs * 1000;
        
        x_tm = localtime( &secs );
        
        strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d %H:%M:%S", x_tm);
        snprintf(string, sizeof tmbuf, "%s.%03d", tmbuf, (int)residual_ms );
        
        status = XIGO_SUCCESS;
    }
    return status;
}