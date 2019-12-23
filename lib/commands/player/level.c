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

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Brings up the 'level up' menu.";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");

    switch (parsedFlag)
    {
        case "-g":
        {
            ret = "This option short-circuits the main levelling menu and "
                "displays the sub-menu for the specified guild.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Level up allows a player to advance in a guild or "
        "multiple guilds when they have earned enough experience to do so. "
        "Through this menu, a player can choose to advance skills, "
        "attributes, select research trees, and gain research / guild "
        "abilities or traits.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: score, research, skills, traits";
}
