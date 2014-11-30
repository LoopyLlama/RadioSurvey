// ---------------------------------------------------------------------------------
//  xigo_factory.cpp
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------

#include "xigo_component.h"
#include "xigo_factory.h"
#include "xigo_factory_table.h"


XIGO_status_e XIGO_Factory_Create( uint32 cid, void **pp )
{
    int                       i                   = 0;
    uint32                    num_entries         = XIGO_Factory_TableNumEntries();
    XIGO_factory_component_t *pFactoryTableEntry  = NULL;
    XIGO_status_e             status              = XIGO_FAILURE;
    
    for( i=0; i<num_entries; i++ )
    {
        if( XIGO_Factory_TableEntry( i, &pFactoryTableEntry ) == XIGO_SUCCESS )
        {
            if( cid == pFactoryTableEntry->CID )
            {
                status = pFactoryTableEntry->Create( cid, pp );
                XIGO_Component *pComp = (XIGO_Component*)*pp;
                pComp->SetCID( cid );
                break;
            }
        }
    }
    return status;
}


XIGO_status_e XIGO_Factory_Destroy( void **pp )
{
    int                       i                   = 0;
    uint32                    num_entries         = XIGO_Factory_TableNumEntries();
    XIGO_factory_component_t *pFactoryTableEntry  = NULL;
    XIGO_status_e             status              = XIGO_FAILURE;
    XIGO_Component           *pComp               = (XIGO_Component*)*pp;
    
    for( i=0; i<num_entries; i++ )
    {
        if( XIGO_Factory_TableEntry( i, &pFactoryTableEntry ) == XIGO_SUCCESS )
        {
            uint32 cid = 0;
            if( pComp != NULL )
            {
                cid = pComp->GetCID();
                if( pComp->GetCID() == pFactoryTableEntry->CID )
                {
                    status = pFactoryTableEntry->Destroy( pp );
                    break;
                }
            }
        }
    }
    return status;
}
