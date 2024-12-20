//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/tests/commands/wizard/tailTest");
    addPermission("/players/earl", Read | Write);
    addPermission("/brokenFile.c", Read);

    addPriviledgedEfun("file_size");
    addPriviledgedEfun("copy_file");
    addPriviledgedEfun("remove_file");
}
