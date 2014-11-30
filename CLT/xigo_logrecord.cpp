// ---------------------------------------------------------------------------------
//  xigo_logrecord.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------
#include "xigo_logrecord.h"

XIGO_LogRecord::XIGO_LogRecord()
{
    
}

XIGO_LogRecord::~XIGO_LogRecord()
{
    
}

XIGO_status_e XIGO_LogRecord::Create( uint32 cid, uint32 iid, void **pp )
{
    return XIGO_SUCCESS;
}

XIGO_status_e XIGO_LogRecord::Destroy( void **pp )
{
    return XIGO_SUCCESS;
}

void XIGO_LogRecord::Record( uint32 value )
{
    
}

void XIGO_LogRecord::ToTLV( XIGO_logrecord_t **ppRec )
{
    
}

void XIGO_LogRecord::ToText( XIGO_string_t **ppString )
{
    
}

XIGO_status_e XIGO_Create_LogRecord( uint32 cid, void **pp )
{
    *pp = new XIGO_LogRecord();
    return pp != NULL ? XIGO_SUCCESS : XIGO_FAILURE;
}

XIGO_status_e XIGO_Destroy_LogRecord( void **pp )
{
    delete (XIGO_LogRecord*)*pp;
    return XIGO_SUCCESS;
}
