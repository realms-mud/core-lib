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
        addCommandTemplate("clone ##Target##");
        addCommandTemplate("cl ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("clone"))
    {
        string target = getTargetString(initiator, command);
        if ((sizeof(target) < 2) || 
            (target[(sizeof(target) - 2)..(sizeof(target) - 1)] != ".c"))
        {
            target += ".c";
        }
        string targetPath = initiator->hasReadAccess(target);

        if (targetPath)
        {
            if (file_size(targetPath) > 0)
            {
                object newObj = clone_object(targetPath);
                if (newObj)
                {
                    ret = 1;
                    move_object(newObj, (newObj->get() ? initiator :
                        environment(initiator)));
                    tell_object(initiator, sprintf("Cloned object '%s'.\n",
                        targetPath));
                }
                else
                {
                    notify_fail(sprintf("Error cloning object: %s\n", targetPath));
                }
            }
            else
            {
                notify_fail(sprintf("The passed value: '%s' is not a file.\n",
                    targetPath));
            }
        }
        else
        {
            notify_fail("You do not have the read access for that.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Clone an object into the game.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The clone command takes a blueprint program as input and "
        "instantiates an instance and places it into the game provided that "
        "the wizard has read access to the file in question. If the object is "
        "carryable, such as a piece of armor or a potion, the item will be "
        "placed in the wizard's inventory. If it is not, it will be placed "
        "in the wizard's environment.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: destruct";
}
