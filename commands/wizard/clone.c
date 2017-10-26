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
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("clone"))
    {
        object group = load_object("/lib/dictionaries/groups/baseGroup.c");
        string targetPath = group->getFullyQualifiedPath(initiator, 
                getTargetString(initiator, command));

        if (initiator->hasReadAccess(targetPath))
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
