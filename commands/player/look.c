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
        addCommandTemplate("look [-b] [(at|in) ##Target##]");
        addCommandTemplate("l [-b] [(at|in) ##Target##]");
        addCommandTemplate("examine [-b] [##Target##]");
        addCommandTemplate("exa [-b] [##Target##]");
        addCommandTemplate("glance [(at|in) ##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        if (initiator->hasTraitOfRoot("blind"))
        {
            tell_object(initiator, "[0;30;1mYou are blind.[0m\n");
        }
        else if (!initiator->canSee())
        {
            tell_object(initiator, "[0;30;1mIt is too dark.[0m\n");

            object *environmentInventory = filter(
                all_inventory(environment(initiator)),
                (: $1->isRealizationOfLiving() &&
                   !$1->hasTraitOfRoot("ethereal") &&
                   !$1->hasTraitOfRoot("undead") :));

            if ((getTargetString(initiator, command) == "") &&
                initiator->hasTraitOfRoot("infravision") &&
                sizeof(environmentInventory))
            {
                string visibleList = "[0;30;1mYou can see objects faintly glowing in red:\n[0m";
                foreach(object environmentItem in environmentInventory)
                {
                    string shortDesc = environmentItem->short();
                    if (shortDesc && (shortDesc != ""))
                    {
                        visibleList += sprintf("[0;31m%s\n[0m", capitalize(shortDesc));
                    }
                }

                if (visibleList != "")
                {
                    tell_object(initiator, visibleList);
                }
            }
        }
        else
        {
            object target = getTarget(initiator, command);
            if (!target && (getTargetString(initiator, command) == ""))
            {
                target = environment(initiator);
            }

            int brief = sizeof(regexp(({ command }), "-b")) ||
                sizeof(regexp(({ command }), "glance"));

            if (target)
            {
                string longDesc = target->long(brief);
                if (longDesc)
                {
                    tell_object(initiator, longDesc);
                }
            }
            else
            {
                tell_object(initiator, sprintf("There is no '%s' here.\n",
                    getTargetString(initiator, command)));
            }
        }
    }
    return ret;
}
