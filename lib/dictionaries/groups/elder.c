//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Elder Wizard");
    addPermission("/mail", Read);
    addPermission("/lib", Read);
    addPermission("/log", Read);
    addPermission("/", Read | Write);
    addPermission("/players/$ANY/closed", None);
    addPermission("/players/$USER/closed", Read | Write | Owner);
    addPermission("/secure", None);
    addPermission("/godstf", None);
    addPermission("/lib/modules/secure", None);
    addPermission("/lib/tests/modules/secure", None);
    addPermission("/lib/dictionaries/groups", None);
    addPermission("/lib/tests/dictionaries/groups", None);
    addCommand("hiz");
    addCommand("reboot");
    addCommand("promote");
    addCommand("create-role");
}
