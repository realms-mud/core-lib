//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/services/attacksService");
    addPermission("/lib/services/attacks", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
