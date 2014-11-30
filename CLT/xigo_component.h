// ---------------------------------------------------------------------------------
//  xigo_component.h
//
//  CLT
//
//  Created by Jason Thomas on 10/15/14.
//  Copyright (c) 2014 XACTIGO. All rights reserved.
// ---------------------------------------------------------------------------------


#ifndef CLT_xigo_component_h
#define CLT_xigo_component_h

#include "xigo_types.h"

class XIGO_Component {
private:
    uint32 cid;
public:
    virtual uint32        GetCID( void ){ return cid; }
    virtual void          SetCID( uint32 new_iid ){ cid = new_iid; return; }
    
    virtual XIGO_status_e Create( uint32 cid, uint32 iid, void **pp = NULL ) = 0;
    virtual XIGO_status_e Destroy( void **pp )                               = 0;
};

#define XIGO_COMPONENT_DECL_START( xx_name )\
   class XIGO_##xx_name : XIGO_Component { \
   public: \
      XIGO_##xx_name(); \
      ~XIGO_##xx_name(); \
      XIGO_status_e Create( uint32 cid, uint32 iid, void **pp ); \
      XIGO_status_e Destroy( void **pp );

#define XIGO_COMPONENT_DECL_END( xx_name ) \
   };\
   extern "C" XIGO_status_e XIGO_Create_##xx_name( uint32 cid, void **pp );\
   extern "C" XIGO_status_e XIGO_Destroy_##xx_name( void **pp );

#endif
