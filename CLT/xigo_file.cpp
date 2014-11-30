// ---------------------------------------------------------------------------------
//  xigo_file.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#include <stdio.h>

#include "xigo_file.h"

XIGO_File::XIGO_File()
{
    
}

XIGO_File::~XIGO_File()
{
    
}

XIGO_status_e XIGO_Create_File( uint32 cid, void **pp )
{
    XIGO_status_e status = XIGO_FAILURE;
    
    *pp = new XIGO_File();
    if( pp != NULL )
    {
        XIGO_File *pFile = (XIGO_File*)*pp;
        status = pFile->Create( cid, 0, pp );
    }
    return status;
}

XIGO_status_e XIGO_Destroy_File( void **pp )
{
    XIGO_status_e status = XIGO_FAILURE;
    
    if( pp != NULL )
    {
        XIGO_File *pFile = (XIGO_File*)*pp;
        status = pFile->Destroy( pp );
        delete (XIGO_File*)*pp;
    }
    return status;
}

XIGO_status_e XIGO_File::Create( uint32 cid, uint32 iid, void **pp )
{
    return XIGO_SUCCESS;
}

XIGO_status_e XIGO_File::Destroy( void **pp )
{
    return XIGO_SUCCESS;
}

XIGO_status_e XIGO_File::Open( XIGO_string_t filename, const char *mode )
{
    FILE          *fp     = NULL;
    XIGO_status_e  status = XIGO_FAILURE;
    
    fp = fopen ( filename, mode );
    
    if( fp != NULL )
    {
        status = XIGO_SUCCESS;
    }

    fileHandle = (XIGO_filehandle_t)fp;
    
    return status;
}

XIGO_status_e XIGO_File::Close( void )
{
    return ( fclose( (FILE*)fileHandle ) == 0 ) ? XIGO_SUCCESS : XIGO_FAILURE;
}

XIGO_status_e XIGO_File::Read( void *d, uint32 len, uint32 *num_read )
{
    int num;
    
    num = (int)fread( d, (size_t)1, (size_t)len, (FILE*)fileHandle );

    if( num_read != NULL )
    {
        *num_read = num;
    }
    return (num  == len) ? XIGO_SUCCESS : XIGO_FAILURE;
}

XIGO_status_e XIGO_File::Write( void *d, uint32 len, uint32 *num_written )
{
    int num = 0;
    
    num = (int)fwrite( d, (size_t)1, (size_t)len, (FILE *)fileHandle );
    
    if( num_written != NULL )
    {
        *num_written = num;
    }
    return ( num == len ) ? XIGO_SUCCESS : XIGO_FAILURE;
}

XIGO_status_e XIGO_File::Seek( uint32 offset, XIGO_filewhence_e whence )
{
    XIGO_status_e status = XIGO_SUCCESS;
    int           origin;
    int           result;
 
    if( whence == SET )
    {
        origin = SEEK_SET;
    }
    else if( whence == CUR )
    {
        origin = SEEK_CUR;
    }
    else if( whence == END )
    {
        origin = SEEK_END;
    }
    else
    {
        origin = SEEK_SET;
        status = XIGO_FAILURE;
    }
    
    if( status == XIGO_SUCCESS )
    {
        result = fseek( (FILE*)fileHandle, (long)offset, (int)origin );
        status = ( result == 0 ) ? XIGO_SUCCESS : XIGO_FAILURE;
    }
    
    return status;
}