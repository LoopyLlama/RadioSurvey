// ---------------------------------------------------------------------------------
//  xigo_logrecordwifi.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------
#include "xigo_logrecordwifi.h"
    


XIGO_status_e XIGO_LogRecordWiFi::Create( uint32 cid, uint32 iid, void **pp )
{
    return XIGO_SUCCESS;
}

XIGO_status_e XIGO_LogRecordWiFi::Destroy( void **pp )
{
    return XIGO_SUCCESS;
}

void XIGO_LogRecordWiFi::Record( uint32 ssid, uint32 rssi )
{
    
}
    
void XIGO_LogRecordWiFi::ToTLV( XIGO_logrecord_t **ppRec )
{
    
}

void XIGO_LogRecordWiFi::ToText( XIGO_string_t **ppString )
{
    
}

XIGO_LogRecordWiFi::XIGO_LogRecordWiFi()
{
    
}

XIGO_LogRecordWiFi::~XIGO_LogRecordWiFi()
{
    
}

XIGO_status_e XIGO_Create_LogRecordWiFi( uint32 cid, void **pp )
{
    XIGO_status_e status = XIGO_FAILURE;
    
    *pp = new XIGO_LogRecordWiFi();
    if( pp != NULL )
    {
        XIGO_LogRecordWiFi *pLogRecWiFi = (XIGO_LogRecordWiFi*)*pp;
        status = pLogRecWiFi->Create( cid, 0, pp );
    }
    return status;
}

XIGO_status_e XIGO_Destroy_LogRecordWiFi( void **pp )
{
    XIGO_status_e status = XIGO_FAILURE;
    
    if( pp != NULL )
    {
        XIGO_LogRecordWiFi *pLogRecWiFi = (XIGO_LogRecordWiFi*)*pp;
        status = pLogRecWiFi->Destroy( pp );
        delete (XIGO_LogRecordWiFi*)*pp;
    }
    return status;
}
