//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/dictionaries/tradingDictionary");
    addPermission("/lib/modules/domains/trading/ports", Read);
    addPermission("/lib/instances", Read);
    addPermission("/lib/tests", Read);
    addPermission("/areas", Read);
    addPermission("/guilds", Read);
    addPermission("/players", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
