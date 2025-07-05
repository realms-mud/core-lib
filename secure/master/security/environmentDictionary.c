//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/dictionaries/environmentDictionary");
    addPermission("/lib/dictionaries", Read);
    addPermission("/lib/environment", Read);
    addPermission("/lib/modules/domains", Read);
    addPermission("/lib/items", Read);
    addPermission("/lib/tests", Read);
    addPermission("/areas", Read);
    addPermission("/guilds", Read);
    addPermission("/players", Read);
    addPermission("/tutorial", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
