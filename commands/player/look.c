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
        CommandType = "Interactions";
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
            tell_object(initiator, "\x1b[0;30;1mYou are blind.\x1b[0m\n");
        }
        else if (!initiator->canSee(1))
        {
            tell_object(initiator, "\x1b[0;30;1mIt is too dark.\x1b[0m\n");

            object *environmentInventory = filter(
                all_inventory(environment(initiator)),
                (: $1->isRealizationOfLiving() &&
                   !$1->hasTraitOfRoot("ethereal") &&
                   !$1->hasTraitOfRoot("undead") :));
            environmentInventory -= ({ initiator });

            if ((getTargetString(initiator, command) == "") &&
                initiator->hasTraitOfRoot("infravision") &&
                sizeof(environmentInventory))
            {
                string visibleList = "\x1b[0;30;1mYou can see objects faintly glowing in red:\n\x1b[0m";
                foreach(object environmentItem in environmentInventory)
                {
                    string shortDesc = environmentItem->short();
                    if (shortDesc && (shortDesc != ""))
                    {
                        visibleList += sprintf("\x1b[0;31m%s\n\x1b[0m", capitalize(shortDesc));
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

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Examine the details of another object or environment";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");

    switch (parsedFlag)
    {
        case "-b":
        {
            ret = "This option will display a brief description of "
                "the target of the examination. 'look -b' is synonymous "
                "with (and this flag is redundant for) the 'glance' "
                "command.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The look command (and all of its permutations) will "
        "describe the details of the target for the player, including "
        "other objects that might be in the target (if it's an environment "
        "or container, for example.)", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "Things that you can look at often have other possible interactions.";
}
