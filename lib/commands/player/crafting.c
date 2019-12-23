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
        CommandType = "Player R&D";
        addCommandTemplate("crafting");
        addCommandTemplate("craft");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object selector = clone_object("/lib/modules/crafting/craftingSelector.c");
        move_object(selector, initiator);
        selector->registerEvent(this_object());
        selector->initiateSelector(initiator);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Enter the crafting subsystem menu";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The crafting command is used to create items - be they "
        "armor, weapons, potions, or other tangible items. A menu is "
        "displayed through which the player can navigate to create "
        "any item they wish - so long as they have the materials to "
        "make it, have the requisite skills, and have researched the "
        "proper knowledge.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: research";
}
