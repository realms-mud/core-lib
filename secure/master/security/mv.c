//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/commands/wizard/mv");
    addPermission("/", Read | Write);

    addPriviledgedEfun("file_size");
    addPriviledgedEfun("rename_from");
    addPriviledgedEfun("rename_to");
}
