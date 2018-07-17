//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("Apprentice Wizard");
    addPermission("/", Read);
    addPermission("/players", None);
    addPermission("/log", None);
    addPermission("/players/$USER", Read | Write | Owner);
    addPermission("/secure", None);
    addPermission("/mail", None);
    addPermission("/banish", None);
    addPermission("/godstf", None);
    addPermission("/guild", None);
    addPermission("/lib/modules/secure", None);
    addPermission("/lib/tests/modules/secure", None);
    addPermission("/lib/dictionaries/groups", None);
    addPermission("/lib/tests/dictionaries/groups", None);
    addCommand("cat");
    addCommand("cd");
    addCommand("emote");
    addCommand("goto");
    addCommand("head");
    addCommand("light");
    addCommand("ls");
    addCommand("more");
    addCommand("people");
    addCommand("pwd");
    addCommand("set");
    addCommand("tail");
    addCommand("wiz");
}
