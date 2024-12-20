//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addCommand("cc");
    addCommand("clone");
    addCommand("destruct");
    addCommand("patch");
    addCommand("mv");
    addCommand("cp");
    addCommand("rm");
    addCommand("show");
    addCommand("stat");
    addCommand("mkdir");
    addCommand("generate");
    addCommand("role");
    addCommand("list roles");
}
