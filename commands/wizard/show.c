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
        addCommandTemplate("show [##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private string decorateObject(object targetObject, object initiator)
{
    object dictionary = load_object("/lib/dictionaries/configurationDictionary.c");
    string objectName = object_name(targetObject);
    string configuration = initiator->colorConfiguration();
    string displayType = "other objects";

    if (sizeof(regexp(({ sprintf("players/%s", initiator->RealName()) }), objectName)))
    {
        displayType = "own objects";
    }
    else if (sizeof(regexp(({ "^guild/" }), objectName)))
    {
        displayType = "guild objects";
    }

    string itemDetails = "\n";
    string shortDesc = targetObject->short();
    if (shortDesc)
    {
        itemDetails = dictionary->decorate(sprintf(" (%s)\n", shortDesc),
            "environment", "show", configuration);
    }
    return dictionary->decorate("Item: ", "text", "show", configuration) +
        dictionary->decorate(objectName, displayType, "show", configuration) +
        itemDetails;
}

/////////////////////////////////////////////////////////////////////////////
private string objectDetails(object target, object initiator)
{
    object dictionary = load_object("/lib/dictionaries/configurationDictionary.c");
    string configuration = initiator->colorConfiguration();

    string ret = dictionary->divider(configuration);

    ret += decorateObject(target, initiator);

    object targetEnvironment = environment(target);
    if (targetEnvironment)
    {
        ret += dictionary->decorate("Environment: ", "text", "show", configuration) +
            dictionary->decorate(object_name(targetEnvironment) + "\n", "environment", "show", configuration);
    }

    ret += dictionary->divider(configuration);

    object *targetInventory = all_inventory(target);
    foreach(object item in targetInventory)
    {
        ret += decorateObject(item, initiator);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private object getBlueprintObject(string targetString, object initiator)
{
    object target = 0;

    if (!sizeof(regexp(({ targetString }), ".+\.c$")))
    {
        targetString += ".c";
    }

    if (file_size(targetString) > 0)
    {
        target = load_object(targetString);
    }
    else if (file_size(sprintf("%s/%s", initiator->pwd(),
        targetString)) > 0)
    {
        target = load_object(sprintf("%s/%s", initiator->pwd(),
            targetString));
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
private object getActualObject(string name, object initiator)
{
    object *targets = filter(users(), (: $1->RealName() == $2 :), name);
    object target = 0;

    if (sizeof(targets))
    {
        target = targets[0];
    }
    else
    {
        target = present(name, environment(initiator));
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
private object getObjectToDisplay(string targetString, object initiator)
{
    object target = getActualObject(targetString, initiator);
    if(!target)
    {
        target = getBlueprintObject(targetString, initiator);
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("show"))
    {
        string targetString = getTargetString(initiator, command);

        object target = 0;
        if (!targetString || (targetString == ""))
        {
            target = environment(initiator);
        }
        else
        {
            target = getObjectToDisplay(targetString, initiator);
        }

        if (target)
        {
            ret = 1;
            tell_object(initiator, objectDetails(target, initiator));
        }
        else
        {
            notify_fail(sprintf("Could not find '%s'.\n", targetString));
        }
    }
    return ret;
}
