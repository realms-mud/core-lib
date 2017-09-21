//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("inventory [-v]");
        addCommandTemplate("i [-v]");
        addCommandTemplate("inven [-v]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    // This should always be true, but if not, the command should fail
    if(canExecuteCommand(command) && initiator->has("inventory"))
    {
        ret = 1;

        int verbose = sizeof(regexp(({ command }), "-v"));
        tell_object(initiator, initiator->inventoryText(verbose));
    }
    return ret;
}
