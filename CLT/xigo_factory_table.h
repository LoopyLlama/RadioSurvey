// ---------------------------------------------------------------------------------
//  xigo_factory_table.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#ifndef CLT_xigo_factory_table_h
#define CLT_xigo_factory_table_h

#include "xigo_types.h"

typedef struct {
    uint32                  CID;
    XIGO_factory_create_t   Create;
    XIGO_factory_destroy_t  Destroy;
} XIGO_factory_component_t;

extern "C" uint32        XIGO_Factory_TableNumEntries( void );
extern "C" XIGO_status_e XIGO_Factory_TableEntry( uint32 index, XIGO_factory_component_t **ppComp );

#endif
