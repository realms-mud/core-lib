//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("transport ##Target##");
    addCommandTemplate("trans ##Target##");
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
            target = findLiving(targetString);
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

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Transport the specified target object to the wizard's environment.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The transport command will move the specified living "
        "object to the wizard's environment.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: goto";
}
