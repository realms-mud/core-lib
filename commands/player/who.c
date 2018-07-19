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
        addCommandTemplate("who [-w] [-r ##Race##] [-g ##Guild##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private string getPlayerInfo(object player)
{
    string pretitle = player->Pretitle() || "";
    string title = player->Title();
    if (sizeof(pretitle) > 20)
    {
        pretitle = pretitle[0..16] + "...";
    }
    string ret = sprintf("%s%s%s",
        ((pretitle != "") ? pretitle + " " : ""),
        capitalize(player->RealName()),
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
        playerList -= wizardList;

        string whoList = "";
        foreach(object wizard in wizardList)
        {
            string wizardName = getPlayerInfo(wizard);

            whoList += sprintf("%-55s (%s)\n", wizardName, 
                configDictionary->decorate(
                    wizardDictionary->getWizardTitle(wizard),
                    wizard->wizardLevel(), "wizard levels", 
                    wizard->colorConfiguration()));
        }

        if (sizeof(whoList))
        {
            whoList += "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n";
        }

        foreach(object player in playerList)
        {
            string playerName = getPlayerInfo(player);

            whoList += sprintf("%-55s (Level %d)\n", playerName,
                player->effectiveLevel());
        }

        tell_object(initiator, whoList);
        ret = 1;
    }
    return ret;
}
