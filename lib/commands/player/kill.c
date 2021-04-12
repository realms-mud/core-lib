//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Interactions";
    addCommandTemplate("kill ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    object target = getTarget(initiator, command);

    if (target && canExecuteCommand(command) && 
        !initiator->spellAction() && !initiator->isInCombatWith(target)
        && !initiator->isDead())
    {
        if ((target->onKillList() && !target->isRealizationOf("player")) ||
            (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
                target->onKillList() && initiator->onKillList()))
        {
            ret = 1;
            tell_object(initiator, sprintf("You attack %s.\n", target->Name()));
            say(sprintf("%s attacks %s.\n", initiator->Name(), target->Name()));
            initiator->attack(target);
            if (objectp(target))
            {
                target->attack(initiator);
            }
            initiator->spellAction(1);
        }
        else
        {
            notify_fail("Both the initiator and target must be on the kill list.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Initiate combat with another character";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Kill will initiate combat with the specified target "
        "with several caveats:\n1. Some environments can prevent combat "
        "from being initiated.\n2. Characters that are members of your "
        "faction or a faction you are friendly with cannot be attacked "
        "unless a deliberate setting change is first made.\n3. You can "
        "only attack other players if both you and your intended target "
        "have set the pvp flag. Once this is done, it is permanent.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: set";
}
