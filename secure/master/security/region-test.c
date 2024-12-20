//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/tests/environment/regionTest");
    addPermission("/lib/generated_region", Read | Write);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("mkdir");
    addPriviledgedEfun("rmdir");
    addPriviledgedEfun("remove_file");
}
