//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Information";
    addCommandTemplate("quests");
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
        object selector = clone_object("/lib/modules/quests/questSelector.c");
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
    return "Enter the quests subsystem menu";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The quests menu allows a player to track their current "
        "(and completed) quests and journal their progress through the "
        "various quests they have been given.", 78);
}
