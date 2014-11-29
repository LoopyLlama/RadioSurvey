//
//  main.cpp
//  CLT
//
//  Created by Jason Thomas on 11/24/14.
//  Copyright (c) 2014 3LS. All rights reserved.
//

#include <iostream>

#include "xigo.h"
#include "xigo_factory.h"

XIGO_status_e XIGO_Create_LogRecordWiFi( uint32 cid, void **pp )
{
    pp = NULL;
    pp = new XIGO_LogRecordWiFi();
    return pp != NULL ? XIGO_SUCCESS : XIGO_FAILURE;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
