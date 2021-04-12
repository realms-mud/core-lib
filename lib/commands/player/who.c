//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "General";
    addCommandTemplate("who [-w] [-p] [-r ##Value##] [-g ##Value##]");
}

/////////////////////////////////////////////////////////////////////////////
private string getPlayerInfo(object player)
{
    string pretitle = player->Pretitle() || "";
    string title = player->Title() || "";
    if (sizeof(pretitle) > 20)
    {
        pretitle = pretitle[0..16] + "...";
    }
    string ret = sprintf("%s%s%s",
        ((pretitle != "") ? pretitle + " " : ""),
        capitalize(player->RealName() || "Player logging in"),
        ((title != "") ? " " + title : ""));

    if (sizeof(ret) > 55)
    {
        ret = ret[0..51] + "...";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object *playerList = sort_array(users(),
            (: $1->effectiveLevel() < $2->effectiveLevel() :));

        object wizardDictionary = load_object("/lib/dictionaries/wizardDictionary.c");
        object configDictionary = load_object("/lib/dictionaries/configurationDictionary.c");

        object *wizardList = sort_array(filter(playerList,
            (: (member(inherit_list($1), "lib/realizations/wizard.c") > -1) :)),
            (: $3->getSortOrder($1) < $3->getSortOrder($2) :), wizardDictionary);

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

        if (sizeof(regexp(({ command }), "-r [^-]+( -|)")))
        {
            string race = regreplace(command, "who.* -r *([^-]+)( -.*|$)", "\\1");

            playerList = filter(playerList, (: $1->Race() == race :), race);
            wizardList = filter(wizardList, (: $1->Race() == race :), race);
        }

        if (sizeof(regexp(({ command }), "-g [^-]+( -|)")))
        {
            string guild = regreplace(command, "who.* -g *([^-]+)( -.*|$)", "\\1");

            playerList = filter(playerList, (: $1->memberOfGuild($2) :), guild);
            wizardList = filter(wizardList, (: $1->memberOfGuild($2) :), guild);
        }

        string whoList = "";
        foreach(object wizard in wizardList)
        {
            string wizardName = getPlayerInfo(wizard);

            whoList += sprintf("%-55s (%s)\n", wizardName, 
                configDictionary->decorate(
                    wizardDictionary->getWizardTitle(wizard),
                    wizard->wizardLevel(), "wizard levels", 
                    initiator->colorConfiguration()));
        }

        if (sizeof(whoList) && sizeof(playerList) && sizeof(wizardList))
        {
            whoList += configDictionary->divider(initiator->colorConfiguration(),
                initiator->charsetConfiguration());
        }

        foreach(object player in playerList)
        {
            string playerName = getPlayerInfo(player);
            whoList += configDictionary->decorate(
                sprintf("%-55s (Level %d)\n", playerName,
                player->effectiveLevel()), "any", "player guilds",
                initiator->colorConfiguration());
        }

        tell_object(initiator, whoList);
        ret = 1;
    }
    return ret;
}


/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display a list of currently logged-in users.";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-*[a-zA-Z]+).*", "\\1");

    switch (parsedFlag)
    {
        case "-w":
        {
            ret = "This option will filter the who list to only show wizards.";
            break;
        }
        case "-p":
        {
            ret = "This option will filter the who list to only show players.";
            break;
        }
        case "-r":
        {
            ret = "This option will filter the who list to only show "
                "members of the specified race.";
            break;
        }
        case "-g":
        {
            ret = "This option will filter the who list to only show "
                "members of the specified guild.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Who will display a list of all players currently "
        "on-line.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: tell, shout, say";
}
