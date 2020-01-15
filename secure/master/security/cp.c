//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("lib/commands/wizard/cp");
    addPermission("/", Read | Write);

    addPriviledgedEfun("copy_file");
    addPriviledgedEfun("file_size");
}
