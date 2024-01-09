//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/commands/wizard/rm");
    addPermission("/", Read | Write);

    addPriviledgedEfun("rmdir");
    addPriviledgedEfun("remove_file");
    addPriviledgedEfun("file_size");
    addPriviledgedEfun("get_dir");
}
