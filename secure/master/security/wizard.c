//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("lib/realizations/wizard");
    addPermission("/lib/dictionaries/groups", Read);
    addPermission("/lib/commands", Read);
    allowInheritedPermissions();

    addPriviledgedEfun("file_size");
    addPriviledgedEfun("get_dir");
}
