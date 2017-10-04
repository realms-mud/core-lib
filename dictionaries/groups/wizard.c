//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Training Wizard");
    addPermission("/players", Read);
    addPermission("/players/$ANY/closed", None);
    addPermission("/players/$USER/closed", Read | Write | Owner);
    addPermission("/log", Read);
    addPermission("/log/$USER", Read | Write | Owner);
    addPermission("/log/$USER.rep", Read | Write | Owner);
    addPermission("/open", Read | Write);
}
