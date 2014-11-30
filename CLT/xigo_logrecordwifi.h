// ---------------------------------------------------------------------------------
//  xigo_logrecordwifi.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------
#ifndef CLT_xigo_logrecordwifi_h
#define CLT_xigo_logrecordwifi_h

#include "xigo_logrecord.h"

#define XIGO_IID_LogRecordWiFi 0x00000040
#define XIGO_CID_LogRecordWiFi 0x00000040

XIGO_COMPONENT_DECL_START( LogRecordWiFi )
   void Record( uint32 ssid, uint32 rssi );
   void ToTLV( XIGO_logrecord_t **ppRec );
   void ToText( XIGO_string_t **ppString );
XIGO_COMPONENT_DECL_END( LogRecordWiFi )

#endif
