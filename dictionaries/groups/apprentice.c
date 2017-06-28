//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Apprentice Wizard");
    addPermission("/", Read);
    addPermission("/players", None);
    addPermission("/players/$USER", Read | Write | Owner);
    addPermission("/secure", None);
    addPermission("/mail", None);
    addPermission("/banish", None);
    addPermission("/godstf", None);
    addPermission("/guild", None);
}
