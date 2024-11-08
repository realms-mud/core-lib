//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/environment/legacyRoomConverter");
    addPermission("/lib/environment/legacyRoomTemplate.c", Read);
    addPermission("/lib/tests", Read);
    addPermission("/players", Read);
    allowInheritedPermissions();

    addPriviledgedEfun("read_file");
}
