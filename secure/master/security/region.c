//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/environment/region");
    addPermission("/lib", Read | Write);
    addPermission("/areas", Read | Write);
    addPermission("/guilds", Read | Write);
    addPermission("/players", Read | Write);
    addPermission("/tutorial", Read | Write);
    allowInheritedPermissions();

    addPriviledgedEfun("file_size");
    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("mkdir");
    addPriviledgedEfun("read_file");
    addPriviledgedEfun("write_file");
}
