//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("lib/commands/commandRegistry");
    addPermission("/lib/commands", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
