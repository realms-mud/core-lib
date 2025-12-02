//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/services/shopService");
    addPermission("/lib", Read);
    addPermission("/areas", Read);
    addPermission("/guilds", Read);
    addPermission("/players", Read);
    addPermission("/tutorial", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
