//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Senior Wizard");
    addPermission("/players", Read | Write);
    addPermission("/players/$ANY/closed", None);
    addPermission("/players/$USER/closed", Read | Write | Owner);
}
