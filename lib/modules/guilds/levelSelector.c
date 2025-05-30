//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public void guildsToAdvance(string *guildList, object user)
{
    if (sizeof(guildList))
    {
        string *guilds = user->memberOfGuilds();
        foreach(string guild in guilds)
        {
            Data[to_string(sizeof(Data) + 1)] = ([
                "name": sprintf("Advance %s level", guild),
                "type": guild,
                "description": sprintf("This option lets you advance your "
                    "level in the %s guild.\n", guild),
                "canShow": (member(guildList, guild) > -1)
            ]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Main Menu";
    Type = "Advancement";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Exit Advancement Menu",
        "type": "exit",
        "description": "This option lets you exit the guild advancement menu.\n",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");
        if (!ret && Data[selection]["canShow"])
        {
            SubselectorObj = 
                clone_object("/lib/modules/guilds/advanceLevelSelector.c");
            SubselectorObj->setGuild(Data[selection]["type"]);
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayText = configuration->decorate("%s", "choice enabled",
        "selector", colorConfiguration);
    if (!Data[choice]["canShow"])
    {
        displayText = configuration->decorate("%-40s ", "choice disabled",
            "selector", colorConfiguration) +
            configuration->decorate("(Need More Experience)", "note", "selector",
                colorConfiguration);
    }

    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice), displayText, displayDetails(choice));
}
