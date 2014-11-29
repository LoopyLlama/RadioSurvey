//
//  xigo_logrecordwifi.h
//  CLT
//
//  Created by Jason Thomas on 11/29/14.
//  Copyright (c) 2014 3LS. All rights reserved.
//

#ifndef CLT_xigo_logrecordwifi_h
#define CLT_xigo_logrecordwifi_h

#include "xigo_logrecord.h"

#define XIGO_IID_LOG_RECORD_WIFI 0x00000040
#define XIGO_CID_LOG_RECORD_WIFI 0x00000040

class XIGO_LogRecordWiFi : XIGO_LogRecord {

public:
    
    XIGO_LogRecordWiFi();
    ~XIGO_LogRecordWiFi();
    
    XIGO_status_e Create( uint32 cid, uint32 iid, void **pp );
    void          Destory( void **pp );
    
    void Record( uint32 ssid, uint32 rssi );
    void ToTLV( XIGO_logrecord_t **ppRec );
    void ToText( XIGO_string_t **ppString );
};


#endif
