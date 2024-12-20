//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Social";
    addCommandTemplate("guild [-g ##Value##] [.*]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        string *guilds = initiator->memberOfGuilds();
        if (!sizeof(guilds))
        {
            guilds += ({ "guildless" });
        }

        string guild;
        if (sizeof(regexp(({ command }), "-g (" + implode(guilds, "|") + ")")))
        {
            guild = regreplace(command, "^guild -g (" + implode(guilds, "|") + ").*", "\\1");
        }
        else
        {
            guild = initiator->primaryGuild();
        }

        string message = 0;
        if (sizeof(regexp(({ command }), "^guild (.+)")))
        {
            ret = 1;
            message = regreplace(command, "^guild (-g " + implode(guilds, "|") + ")* *(.*)", "\\2");

            object channels = load_object("/lib/dictionaries/channelDictionary.c");
            if (channels && sizeof(message))
            {
                channels->broadcastMessage(guild, message, initiator);
            }
        }
        else
        {
            notify_fail("What do you want to say on the guild line?\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return configuration->decorate("<Message to speak>",
        "wildcard", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Send a message to every logged-in player of your guild";
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
            ret = "This option will allow you to specify a specific guild "
                "that you wish to send a message to. If this option is not "
                "passed, the message will be sent to your primary guild.\n";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Guild allows a player to display a message to all players "
        "of their guild who are currently logged on.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: tell, whisper, reply, say, race, faction, party, "
        "and shout";
}
