//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("unmute [-a(ll|)] [-b(usy|)] [-s(houts*|)] "
            "[-c(han|hannels*|)] [##Target##]");
        addCommandTemplate("set unsilence [-a(ll|)] [-s(houts*|)] "
            "[-c(han|hannels*|)] [##Target##]");
        addCommandTemplate("set busy off");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        if (initiator->isBusy() && ((command == "set busy off") ||
            sizeof(regexp(({ command }), "-b(usy)*"))))
        {
            initiator->toggleBusy();
            tell_object(initiator, "Your status is no longer set to busy.\n");
        }
        else
        {
            string targetName = regreplace(command,
                "(unmute|set unsilence) (-[a-z]+)* *([A-Za-z]+)$", "\\3", 1);

            initiator->unblock(targetName);
            tell_object(initiator, sprintf("You are no longer blocking %s.\n",
                capitalize(targetName)));
        }
    }
    return ret;
}
