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
        CommandType = "Player R&D";
        addCommandTemplate("level up [-g ##Value##]");
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
        string *guilds = ({});
        string guild = 0;

        if (sizeof(regexp(({ command }), "-g (.*)")))
        {
            guild = regreplace(command, "level up -g (.+)$", "\\1");

            if (initiator->memberOfGuild(guild) &&
                (initiator->experienceToNextLevel(guild) <= 0))
            {
                guilds = ({ guild });
            }
        }
        else
        {
            guilds = filter(initiator->memberOfGuilds(),
                (: ($2->experienceToNextLevel($1) <= 0) :), initiator);
        }

        if (sizeof(guilds))
        {
            object selector = clone_object("/lib/modules/guilds/levelSelector.c");
            move_object(selector, initiator);
            selector->registerCompletionEvent(initiator, "onAdvancedLevel");
            selector->registerEvent(this_object());
            selector->guildsToAdvance(guilds, initiator);
            selector->initiateSelector(initiator);
            ret = 1;
        }
        else
        {
            notify_fail("You are not yet ready to advance in any guilds.\n");
        }
    }
    return ret;
}
