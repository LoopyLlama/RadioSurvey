// ---------------------------------------------------------------------------------
//  xigo_factory.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#ifndef CLT_xigo_factory_h
#define CLT_xigo_factory_h

#include "xigo_types.h"

#define XIGO_IID_MAX 0xFFFFFFFF

extern "C" XIGO_status_e XIGO_Factory_Create( uint32 cid, void **pp );
extern "C" XIGO_status_e XIGO_Factory_Destroy( void **pp );

typedef XIGO_status_e (*XIGO_factory_create_t) ( uint32 cid, void **pp );
typedef XIGO_status_e (*XIGO_factory_destroy_t)(             void **pp );

#define XIGO_FACTORY_CREATE( xx_name ) \
   XIGO_status_e XIGO_Create_##xx_name( uint32 cid, void *pp ) \
   { \
      pp = NULL; \
      *pp = new XIGO_##xx_name(); \
      return ( pp != NULL ) ? XIGO_SUCCESS : XIGO_FAILURE; \
   }

#endif
