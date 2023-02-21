//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Admin Wizard");
    addPermission("/room", Read | Write);
    addPermission("/guilds", Read | Write);
    addPermission("/areas", Read | Write);
    addPermission("/tutorial", Read | Write);

    addCommand("snoop");
}
