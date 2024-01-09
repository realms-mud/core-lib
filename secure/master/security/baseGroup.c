//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/dictionaries/groups/baseGroup");
    addPermission("/lib/commands", Read);
    allowInheritedPermissions();

    addPriviledgedEfun("get_dir");
}
