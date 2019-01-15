//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("destruct ##Target##");
        addCommandTemplate("unmake ##Target##");
        addCommandTemplate("dest ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
private object getDestructTarget(string command, object initiator)
{
    string targetString = getTargetString(initiator, command);

    object target = present(targetString, initiator) ||
        present(targetString, environment(initiator)) ||
        find_object(targetString);

    if (!target)
    {
        string targetPath = initiator->hasReadAccess(targetString);

        if (targetPath && (file_size(targetPath) > 0))
        {
            catch (target = load_object(targetPath));
        }
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void destroyItem(object item)
{
    object *subItems = deep_inventory(item);
    if (sizeof(subItems))
    {
        foreach(object subItem in subItems)
        {
            destruct(subItem);
        }
    }
    destruct(item);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("destruct"))
    {
        object target = getDestructTarget(command, initiator);

        if (objectp(target))
        {
            ret = 1;

            if (target->isRealizationOfPlayer())
            {
                target->save();
            }

            string currentLocation = object_name(environment(initiator));

            object *containedItems = all_inventory(target);
            object *movedItems = ({});

            if (sizeof(containedItems))
            {
                foreach(object item in containedItems)
                {
                    if (item->isRealizationOfPlayer())
                    {
                        movedItems += ({ item });
                        move_object(item, "/secure/master.c");
                    }
                    else
                    {
                        // This has to be nested to most cleanly separate
                        // players and their stuff from "just stuff"
                        destroyItem(item);
                    }
                }
            }

            tell_object(initiator, sprintf("Destroying object '%O'.\n",
                target));
            destruct(target);

            if (sizeof(movedItems))
            {
                foreach(object item in movedItems)
                {
                    move_object(item, currentLocation);
                }
            }
        }
        else
        {
            notify_fail(sprintf("Could not find a '%s' to destroy.\n",
                getTargetString(initiator, command)));
        }
    }
    return ret;
}
