//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib//dictionaries/regions/region-types.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRegionType(string type)
{
    return member(regionTypes, type);
}
