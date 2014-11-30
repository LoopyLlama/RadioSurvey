// ---------------------------------------------------------------------------------
//  xigo_logrecord.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------

#ifndef CLT_xigo_logrecord_h
#define CLT_xigo_logrecord_h

#include "xigo_component.h"
#include "xigo_types.h"
#include "xigo_time.h"
#include "xigo_string.h"
#include "xigo_location.h"

// ---------------------------------------------------------------------------------
// Log Record Format
//      uint32     type     - from xigo_logtypes.h
//      uint32     len      - length of 4 byte aligned value field in octets
//      uint8[len] value    - From ToTLV method
// ---------------------------------------------------------------------------------
typedef struct {
    uint32  type;
    uint32  len;
    uint8   value[4];
} XIGO_logrecord_t;

// ---------------------------------------------------------------------------------
// Header
// ---------------------------------------------------------------------------------
#define XIGO_IID_LOG_RECORD_HEADER 0x00000030
#define XIGO_CID_LOG_RECORD_HEADER 0x00000030

class XIGO_LogRecordHeader : XIGO_Component {
public:
    XIGO_LogRecordHeader();
    ~XIGO_LogRecordHeader();
    
    XIGO_status_e Create( uint32 cid, uint32 iid, void **pp );
    XIGO_status_e Destroy( void **pp );

    void GetHeader( XIGO_LogRecordHeader *p );
    void SetTimeStamp( XIGO_time_ms_t time );
    void SetLocation( XIGO_location_t location );
    void SetRecordNumber( uint32 num );
    
    void ToTLV( XIGO_logrecord_t **ppRec );
    void ToText( XIGO_string_t **ppString );
};


// ---------------------------------------------------------------------------------
// Records
// ---------------------------------------------------------------------------------
#define XIGO_IID_LOG_RECORD 0x00000020
#define XIGO_CID_LOG_RECORD 0x00000020

class XIGO_LogRecord : XIGO_Component {
private:
    // XIGO_LogRecordHeader *pHeader;
public:
    
    XIGO_LogRecord();
    ~XIGO_LogRecord();
   
    virtual XIGO_status_e Create( uint32 cid, uint32 iid, void **pp = NULL );
    virtual XIGO_status_e Destroy( void **pp );
   
    void Record( uint32 value );
    
    void ToTLV( XIGO_logrecord_t **ppRec );
    void ToText( XIGO_string_t **ppString );

};


#endif
