//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/groups/baseGroup.c";

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
    addPermission("/lib/services/groups", None);
    addPermission("/lib/tests/services/groups", None);
    addCommand("hiz");
    addCommand("reboot");
    addCommand("promote");
    addCommand("create-role");
}
