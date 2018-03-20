//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include "/lib/include/itemFormatters.h"

private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Player Information";
        addCommandTemplate("vitals");

        Dictionary = load_object("/lib/dictionaries/commandsDictionary.c");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;

        tell_object(initiator, initiator->vitals());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand)
{
    return "Display a character's vitals";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand)
{
    return format("The vitals command displays information about your current hit "
        "points, spell points, and stamina points levels.\n\nFor example:\n> "
        "vitals", 78) + "[0;31m|[0m  [0;36mHit Points: [0;35;1m==[0;31m........[0m"
        "[0;36m   Spell Points: [0;35;1m========[0;31m..[0m       "
        "[0;36mStamina: [0;35;1m==========[0m [0;31m|[0m\n[0;31m|"
        "              [0;33m30 / 121                    122 / 152 "
        "                96 / 96   [0;31m|[0m\n";
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand)
{
    return "See also: score";
}
