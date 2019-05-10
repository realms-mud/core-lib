//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/domains.h"

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getDomainUpgrades(string location, string type)
{
    return ([
        "keep": "stone keep",
        "northwest tower": "ballista northwest tower",
    ]);
}
