//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/tests/commands/wizard/headTest");

    addPermission("/players/earl", Read | Write);
    addPermission("/brokenFile.c", Read);

    addPriviledgedEfun("copy_file");
    addPriviledgedEfun("remove_file");
    addPriviledgedEfun("file_size");
}
