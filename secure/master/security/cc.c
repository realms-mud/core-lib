//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/commands/wizard/cc");
    addPermission("/", Read);
    addPermission("/log", Read | Write);

    addPriviledgedEfun("remove_file");
    addPriviledgedEfun("read_file");
    addPriviledgedEfun("file_size");
    addPriviledgedEfun("get_dir");
}
