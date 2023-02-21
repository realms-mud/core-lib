//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/tests/modules/secure/fakeDatabase");
    addPermission("/log", Read | Write);
    addPermission("/secure/simulated-efuns/database/", Read);

    addPriviledgedEfun("read_file");
    addPriviledgedEfun("write_file");
}
