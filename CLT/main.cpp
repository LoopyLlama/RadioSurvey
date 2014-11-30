// ---------------------------------------------------------------------------------
//  main.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------
#include <iostream>

#include "xigo.h"
#include "xigo_factory.h"
#include "xigo_logrecordwifi.h"
#include "xigo_file.h"
#include "xigo_time.h"

int main(int argc, const char * argv[])
{
    XIGO_status_e       status   = XIGO_FAILURE;
    XIGO_LogRecordWiFi *pRecWifi = NULL;
    XIGO_File          *pFile    = NULL;
    XIGO_Time          *pTime    = NULL;
    
    std::cout << "XACTIGO!\n";
    
    status = XIGO_Factory_Create( XIGO_CID_LogRecordWiFi, (void**)&pRecWifi );
    std::cout << "Create: " << status << "\n";
    
    status = XIGO_Factory_Destroy( (void**)&pRecWifi );
    std::cout << "Destroy: " << status << "\n";

    status = XIGO_Factory_Create( XIGO_CID_File, (void**)&pFile );
    std::cout << "Create: " << status << "\n";
    
    status = pFile->Open( (XIGO_string_t)"foo.log", "w" );
    std::cout << "Open: " << status << "\n";
    
    char buffer1[ 100 ] = {
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
        0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, '\n',
    };
    
    pFile->Write( buffer1, 100 );
    
    pFile->Seek( 20, SET );
    
    char buffer2[ 10 ] = {
        0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42
    };
    
    pFile->Write( buffer2, 10 );
    
    status = pFile->Close();
    std::cout << "Close: " << status << "\n";
    
    status = pFile->Open( (XIGO_string_t)"foo.log", "r" );
    std::cout << "Open2: " << status << "\n";
    
    char buffer3[ 50 ] = {
        0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43,
        0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43,
        0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43,
        0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43,
        0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, '\n', 0x00
    };
    
    pFile->Seek( 0, SET );
    status = pFile->Read( buffer3, 48 );
    
    std::cout << "Buffer: " << buffer3;

    status = pFile->Close();
    std::cout << "Close2: " << status << "\n";
    
    status = XIGO_Factory_Destroy( (void**)&pFile );
    std::cout << "Destroy: " << status << "\n";
    
    status = XIGO_Factory_Create( XIGO_CID_Time, (void**)&pTime );
    std::cout << "Create: " << status << "\n";
    
    XIGO_time_ms_t ms1;
    pTime->Get( &ms1 );
    std::cout << "Time in ms 1: " << ms1 << "\n";
    
    int i;
    for( i=0; i<1000000/2; i++);
    
    XIGO_string_t str = buffer3;
    XIGO_time_ms_t ms2;
    pTime->GetTimestamp( &ms2, str );
    std::cout << "Time stamp 2: " << str << " " << ms2 << std::endl;
    
    
    pTime->ConvertMillisecondTimeToString( &ms1, str );
    std::cout << "Time stamp 1: " << str << " " << ms1 << std::endl;
    
    
    status = XIGO_Factory_Destroy( (void**)&pTime );
    std::cout << "Destroy: " << status << "\n";
    
    
    std::cout << "End\n";
    return 0;
}
