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
        CommandType = "Wizard";
        addCommandTemplate("goto ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("goto"))
    {
        string targetString = getTargetString(initiator, command);
        object target = find_player(targetString) ||
            find_living(targetString);

        object destination = 0;
        if (target)
        {
            destination = environment(target) || target;
        }
        else if(file_size(targetString) > 0)
        {
            destination = load_object(targetString);
        }
        else if (file_size(sprintf("%s/%s", initiator->pwd(),
            targetString)) > 0)
        {
            destination = load_object(sprintf("%s/%s", initiator->pwd(),
                targetString));
        }
        if(destination)
        {
            ret = 1;
            displayMessage(sprintf("##InitiatorName## %s\n",
                initiator->MagicalMessageOut()), initiator);
            move_object(initiator, destination);
            displayMessage(sprintf("##InitiatorName## %s\n",
                initiator->MagicalMessageIn()), initiator);
        }
        else
        {
            notify_fail(sprintf("Could not go to '%s'.\n", targetString));
        }
    }
    return ret;
}
