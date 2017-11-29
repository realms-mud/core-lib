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
