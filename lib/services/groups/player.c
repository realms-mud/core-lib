//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Player");
    addPermission("/p/$ANY/$USER.o", Read);
    addPermission("/mail/$ANY/$USER.o", Read | Write);
    addPermission("/players/$ANY/.plan", Read);
    addPermission("/doc", Read);
}
