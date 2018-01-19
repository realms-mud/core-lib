//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private string TargetString;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("get [-a] [##Item##] [from ##Target##]");
        addCommandTemplate("pick up [-a] ##Item##");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object *getAll(object initiator, object source)
{
    object *targets = filter(all_inventory(source),
        (: $1->get() :));
    if (!sizeof(targets))
    {
        notify_fail("There is nothing to get.\n");
    }
    return targets;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object *getAllOfSpecificId(object initiator, object source)
{
    object *targets = filter(all_inventory(source),
        (: $1->get() && $1->id(TargetString) :));

    if (!sizeof(targets))
    {
        notify_fail(sprintf("Could not find any '%s' to get.\n",
            TargetString));
    }
    return targets;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object *getSpecificItem(object initiator, object source, string targetString)
{
    object *targets = ({});
    object target = present(targetString, source) ||
        present(targetString, initiator);

    if (target)
    {
        if (target->get())
        {
            targets += ({ target });
        }
        else
        {
            notify_fail("You cannot get that.\n");
        }
    }
    else
    {
        notify_fail(sprintf("Could not find '%s'.\n", TargetString));
    }
    return targets;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getObjects(object initiator, object source, object *targets)
{
    int ret = 0;
    if (sizeof(targets))
    {
        ret = 1;
        foreach(object target in targets)
        {
            if (function_exists("canGet", source) &&
                !source->canGet(target))
            {
                tell_object(initiator, "You cannot get that.\n");
            }
            else if (initiator->canCarry(target))
            {
                move_object(target, initiator);
                displayMessage("##InitiatorName## ##Infinitive::pick## up " +
                    target->query("name") + ".\n", initiator);
            }
            else
            {
                tell_object(initiator, "You cannot carry any more weight.\n");
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private object getSource(object initiator, string command)
{
    object source = environment(initiator);
    if (sizeof(regexp(({ command }), "from .+")))
    {
        string from = regreplace(command, ".*from (.+)", "\\1", 1);
        TargetString = regreplace(TargetString, "(.+) from .*", "\\1", 1);

        source = present(from, environment(initiator)) ||
            present(from, initiator);

        if (!source && environment(initiator)->isEnvironmentalElement(from))
        {
            source = environment(initiator)->getEnvironmentalElement(from);
        }
        if (source && ((function_exists("isContainer", source) &&
            !source->isContainer()) || source->isRealizationOfLiving()))
        {
            source = 0;
            notify_fail("The 'from' item is not a valid container.\n");
        }
    }

    return source;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object *targets = ({});
        TargetString = getTargetString(initiator, command);

        object source = getSource(initiator, command);

        if (source)
        {
            if (TargetString == "all")
            {
                targets += getAll(initiator, source);
            }
            else if (sizeof(regexp(({ command }), "-a")))
            {
                targets += getAllOfSpecificId(initiator, source);
            }
            else
            {
                targets += getSpecificItem(initiator, source, TargetString);
            }
        }
        targets -= ({ 0 });

        ret = getObjects(initiator, source, targets);
    }

    return ret;
}
