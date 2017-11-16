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
        addCommandTemplate("quests");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    // This should always be true, but if not, the command should fail
    if (canExecuteCommand(command))
    {
        object selector = clone_object("/lib/modules/quests/questSelector.c");
        selector->registerEvent(this_object());
        move_object(selector, initiator);
        selector->initiateSelector(initiator);
        ret = 1;
    }
    return ret;
}