// ---------------------------------------------------------------------------------
//  xigo_factory_table.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------

#include "xigo_types.h"
#include "xigo_factory.h"
#include "xigo_factory_table.h"

#include "xigo_logrecordwifi.h"
#include "xigo_file.h"
#include "xigo_time.h"

#define XIGO_FACTORY_TABLE       XIGO_factory_component_t xigo_factory_table[] = {
#define XIGO_FACTORY_TABLE_END   XIGO_IID_MAX, NULL, NULL };
#define XIGO_COMPONENT( xx_name ) XIGO_IID_##xx_name, XIGO_Create_##xx_name, XIGO_Destroy_##xx_name,

XIGO_FACTORY_TABLE
    XIGO_COMPONENT( LogRecordWiFi )
    XIGO_COMPONENT( File )
    XIGO_COMPONENT( Time )
XIGO_FACTORY_TABLE_END

uint32 XIGO_Factory_TableNumEntries( void )
{
    return sizeof( xigo_factory_table) / sizeof( XIGO_factory_component_t) - 1;
}

XIGO_status_e XIGO_Factory_TableEntry( uint32 index, XIGO_factory_component_t **ppComp )
{
    *ppComp = &xigo_factory_table[ index ];
    return XIGO_SUCCESS;
}