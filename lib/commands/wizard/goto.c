//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("goto ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("goto"))
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
            destination = environment(target) || target;
        }
        else
        {
            if (!sizeof(regexp(({ targetString }), ".+\.c$")))
            {
                targetString += ".c";
            }

            if (file_size(targetString) > 0)
            {
                destination = load_object(targetString);
            }
            else if (file_size(sprintf("%s/%s", initiator->pwd(),
                targetString)) > 0)
            {
                destination = load_object(sprintf("%s/%s", initiator->pwd(),
                    targetString));
            }
        }
        if(destination)
        {
            ret = 1;
            displayMessage(sprintf("##InitiatorName## %s.\n",
                initiator->MagicalMessageOut()), initiator);
            move_object(initiator, destination);
            command("look", initiator);
            displayMessage(sprintf("##InitiatorName## %s.\n",
                initiator->MagicalMessageIn()), initiator);
        }
        else
        {
            notify_fail(sprintf("Could not go to '%s'.\n", targetString));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Go to the specified target object";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The goto command will move the wizard to the specified "
        "environment or person. If the target is an in-game person, the "
        "command will place the wizard in the same environment as the target. "
        "If the target is a file or a non-player object, the command will "
        "place the wizard inside the selected file or object.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: transport";
}
