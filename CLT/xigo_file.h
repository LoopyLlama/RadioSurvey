//
//  xigo_file.h
//  CLT
//
//  Created by Jason Thomas on 11/28/14.
//  Copyright (c) 2014 3LS. All rights reserved.
//

#ifndef CLT_xigo_file_h
#define CLT_xigo_file_h

#include "xigo.h"

#define XIGO_IID_FILE 0x00000010
#define XIGO_CID_FILE 0x00000010

class XIGO_File : XIGO_Component {
public:
    Open( filename )
    Read( void *d, uint32 len, uint32 *num_read = NULL )
    Write( void *d, uint32 len, uint32 *num_written = NULL )
    Close( void )
    Seek
    Truncate
};

#endif
