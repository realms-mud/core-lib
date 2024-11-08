//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/core/stateMachine");
    addPermission("/lib", Read);
    addPermission("/areas", Read);
    addPermission("/guilds", Read);
    addPermission("/players", Read);
    addPermission("/tutorial", Read);
    allowInheritedPermissions();

    addPriviledgedEfun("file_size");
}
