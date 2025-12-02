//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

object Configuration;

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("people [-w] [-p]");
    Configuration = getService("configuration");
}

/////////////////////////////////////////////////////////////////////////////
private string getPlayerStatus(object player)
{
    string playerStatus = " ";
    if (query_idle(player) > 300)
    {
        playerStatus = "I";
    }
    if ((member(inherit_list(player), "/lib/realizations/wizard.c") > -1) &&
        player->wizardStatus())
    {
        playerStatus = player->wizardStatus();
    }
    return playerStatus[0..0];
}

/////////////////////////////////////////////////////////////////////////////
private string getPlayerLevel(object player)
{
    string level = to_string(player->effectiveLevel());
    if (member(inherit_list(player), "/lib/realizations/wizard.c") > -1)
    {
        level = capitalize(player->wizardLevel());
    }
    return sprintf("%-10s", level);
}

/////////////////////////////////////////////////////////////////////////////
private string getPlayerInfo(object player, object initiator)
{
    string colorConfiguration = initiator->colorConfiguration();

    string address = Configuration->decorate(
        sprintf("%-16s", query_ip_number(player) || "<unknown>"),
        "ip address", "people", colorConfiguration);

    string name = Configuration->decorate(
        sprintf("%-20s", capitalize(player->RealName() || "Player logging in")),
        "name", "people", colorConfiguration);

    string level = Configuration->decorate(getPlayerLevel(player),
        "level", "people", colorConfiguration);

    string playerStatus = Configuration->decorate(getPlayerStatus(player),
        "status", "people", colorConfiguration);

    string location = Configuration->decorate((environment(player) ?
        object_name(environment(player)) : "<unknown>"),
        "location", "people", colorConfiguration);
    location = regreplace(location, "players/", "~");

    return address + name + level + playerStatus + "  " + location + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private object *getListOfUsers(string command)
{
    object *playerList = sort_array(users(),
        (: $1->effectiveLevel() < $2->effectiveLevel() :));

    object wizardService = getService("wizard");

    object *wizardList = sort_array(filter(playerList,
        (: (member(inherit_list($1), "/lib/realizations/wizard.c") > -1) :)),
        (: $3->getSortOrder($1) < $3->getSortOrder($2) :), wizardService);

    if (sizeof(regexp(({ command }), "-w")))
    {
        playerList = ({});
    }
    else
    {
        playerList -= wizardList;
    }

    if (sizeof(regexp(({ command }), "-p")))
    {
        wizardList = ({});
    }

    return wizardList + playerList;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("people"))
    {
        ret = 1;

        object *peopleList = getListOfUsers(command);

        string details = sprintf("There are %d players (%d active)\n"
            "%-16s%-20s%-10s   %s\n", sizeof(peopleList),
            sizeof(filter(peopleList, (: query_idle($1) < 300 :))),
            "IP Address", "Player Name", "Level", "Location");

        foreach(object player in peopleList)
        {
            if (objectp(player))
            {
                details += getPlayerInfo(player, initiator);
            }
        }
        tell_object(initiator, details);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display a wizard-specific view of currently logged-in people.";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-p":
        {
            ret = "Filter to only display players.";
            break;
        }
        case "-w":
        {
            ret = "Filter to only display wizards.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The people command displays a list of users currently "
        "logged in to the game, including their IP address and the "
        "environment the user is currently in.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: who";
}
