//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("transport ##Target##");
        addCommandTemplate("trans ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("transport"))
    {
        string targetString = getTargetString(initiator, command);

        object *targets = filter(users(), (: $1->RealName() == $2 :), targetString);
        object target = 0;

        if (sizeof(targets))
        {
            target = targets[0];
        }
        else
        {
            target = find_living(targetString);
        }

        object destination = 0;
        if (target)
        {
            destination = environment(initiator);
        }
        if(destination)
        {
            ret = 1;
            displayMessage(sprintf("##InitiatorName## %s.\n",
                initiator->MagicalMessageOut()), target);
            move_object(target, destination);
            command("look", target);
            displayMessage(sprintf("##InitiatorName## %s.\n",
                initiator->MagicalMessageIn()), target);
        }
        else
        {
            notify_fail(sprintf("Could not transport '%s' here.\n", targetString));
        }
    }
    return ret;
}
