//
//  xigo_factory.h
//  CLT
//
//  Created by Jason Thomas on 11/27/14.
//  Copyright (c) 2014 3LS. All rights reserved.
//

#ifndef CLT_xigo_factory_h
#define CLT_xigo_factory_h

#include "xigo_types.h"

extern "C" XIGO_status_e XIGO_Factory_Create( uint32 cid, void **pp );
extern "C" XIGO_status_e XIGO_Factory_Destroy( void **pp );

#define XIGO_FACTORY_CREATE( xx_name ) \
   XIGO_status_e XIGO_Create_##xx_name( uint32 cid, void *pp ) \
   { \
      pp = NULL; \
      *pp = new XIGO_##xx_name(); \
      return ( pp != NULL ) ? XIGO_SUCCESS : XIGO_FAILURE; \
   }

#endif
