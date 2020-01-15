//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("lib/tests/support/master/preloadHelper");
    addPermission("/", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
    addPriviledgedEfun("read_file");
}
