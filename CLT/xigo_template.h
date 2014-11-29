// ---------------------------------------------------------------------------------
//  xigo_template.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#ifndef CLT_xigo_template_h
#define CLT_xigo_template_h


// ---------------------------------------------------------------------------------
//
// ---------------------------------------------------------------------------------

/*
 File names:
 xigo_all_lower_case.h
 
 Static/Global names:
 XIGO_ALLUPPERKIND_MixedCaseName
 XIGO_type_t
 
 Class Names
 XIGO_MixedCase
 */

/*
 
 
 
 
 ==> xigo.h
 
 
 ==> xigo_logrecord.h
 
  
 ==> xigo_logfile.h
 
 
 #include "xigo.h"
 
 class XIGO_LogFile : XIGO_Component {
 private:
 XIGO_File file;
 public:
 Create( filename );
 Delete( filename );
 Add( XIGO_LogRecord *p );
 };
 
 ==> xigo_logrecord_wifi.h
 
 
 #include "xigo_logrecord.h"
 
 LOG_TYPES_e
 LOG_FORMAT_VERSION
 OR
 #define XIGO_LOG_FORMAT_VERSION 0x00000001
 
 
  
 
 
 ==> xigo_factory.cpp
 
 ==> coupled by headers
 
 #include "xigo_logrecord_wifi.h"
 
 class XIGO_LogRecord_WiFi : XIGO_LogRecord {
 public:
 Record( rssi, ssid );
 Serialize
 ToText
 };
 
 
 
 #define ENTRY( xx_name )  XIGO_IID_##xx_name, XIGO_Create##xx_name, XIGO_Destroy##xx_name
 
 ==> TEMPLATE this in each imp for a component
 
 TABLE_START
 ENTRY( File )
 ENTRY( LogRecord_WiFi )
 TABLE_END
 
 
 ==> coupled only by XIGO_Component
 XIGO_status_t XIGO_Factory_Create( uint32 cid, void **pp )
 {
 XIGO_status_t status = ENOCOMP;
 uint32        i;
 
 for( i=0; i<TABLE_NUM_RECORDS; i++ )
 {
 if( TABLE[i].id == cid )
 status = ENTRY_Create( cid, pp )
 break;
 }
 return status;
 }
 
 
 
 
 
 */


#endif
