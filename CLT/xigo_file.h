// ---------------------------------------------------------------------------------
//  xigo_file.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#ifndef CLT_xigo_file_h
#define CLT_xigo_file_h

#include "xigo_types.h"
#include "xigo_component.h"
#include "xigo_string.h"

#define XIGO_IID_File 0x00000050
#define XIGO_CID_File 0x00000050

typedef void* XIGO_filehandle_t;

typedef enum {
    SET,
    CUR,
    END
} XIGO_filewhence_e;

XIGO_COMPONENT_DECL_START( File )
private:
   XIGO_filehandle_t fileHandle;
public:
   XIGO_status_e Open( XIGO_string_t filename, const char *mode );
   XIGO_status_e Close( void );
   XIGO_status_e Read( void *d, uint32 len, uint32 *num_read = NULL );
   XIGO_status_e Write( void *d, uint32 len, uint32 *num_written = NULL );
   XIGO_status_e Seek( uint32 offset, XIGO_filewhence_e whence );
XIGO_COMPONENT_DECL_END( File )

#endif
