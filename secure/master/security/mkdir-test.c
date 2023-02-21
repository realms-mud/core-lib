//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/tests/commands/wizard/mkdirTest");
    addPermission("/players/earl", Read | Write);
    addPermission("/secure/newDir", Read);

    addPriviledgedEfun("rmdir");
    addPriviledgedEfun("file_size");
}
