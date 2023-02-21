//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/realizations/wizard");
    addPermission("/lib", Read);
    addPermission("/players", Read);
    allowInheritedPermissions();

    addPriviledgedEfun("file_size");
    addPriviledgedEfun("get_dir");
}
