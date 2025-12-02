//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/services/tradingService");
    addPermission("/lib/modules/domains/trading/ports", Read);
    addPermission("/lib/instances", Read);
    addPermission("/lib/tests", Read);
    addPermission("/areas", Read);
    addPermission("/guilds", Read);
    addPermission("/players", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
