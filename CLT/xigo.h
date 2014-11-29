//
//  xigo.h
//  CLT
//
//  Created by Jason Thomas on 11/24/14.
//  Copyright (c) 2014 3LS. All rights reserved.
//

#ifndef CLT_xigo_h
#define CLT_xigo_h

#include "xigo_types.h"

class XIGO_Component {
public:
    virtual XIGO_status_e Create( uint32 cid, uint32 iid, void **pp ) = 0;
    virtual void          Destory( void **pp )                        = 0;
};

#endif
