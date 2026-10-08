//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

public nomask void SetupCommand()
{
    CommandType = "Interactions";
    addCommandTemplate("protect ##Target##");
}

public nomask int execute(string command, object initiator)
{
    int ret = 0;
    if (canExecuteCommand(command))
    {
        object ally = getTarget(initiator, command);
        if (objectp(ally) && ally != initiator &&
            function_exists("combatOpponents", ally))
        {
            object *attackers = ally->combatOpponents();
            if (sizeof(attackers))
            {
                ret = initiator->protectAlly(ally, attackers[0]);
            }
        }
        if (!ret)
        {
            notify_fail("There is no fight here in which you can intervene.\n");
        }
    }
    return ret;
}

protected string synopsis(string command, string colors)
{
    return "Intervene in an ally's fight and take over their opponent.";
}
