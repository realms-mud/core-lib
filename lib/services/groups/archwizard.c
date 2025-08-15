//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Arch Wizard");
    addPermission("/", Read | Write);
    addPermission("/secure", None);
    addPermission("/godstf", None);
    addPermission("/lib/modules/secure", None);
    addPermission("/lib/modules/secure", None);
    addPermission("/lib/tests/modules/secure", None);
    addPermission("/lib/services/groups", None);
    addPermission("/lib/tests/services/groups", None);

    addCommand("query-snoop");
}
