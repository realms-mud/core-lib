//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        NumColumns = 2;
        Description = "Compose Songs Main Menu";
        Type = "Song";
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    mapping currentSongs = User->getOptionsForCompositeResearch(
        "/guilds/bard/compositions/root.c");

    int optionCount = 1;

    if (sizeof(currentSongs))
    {
        string *keys = sort_array(m_indices(currentSongs), (: $1 > $2 :));
        foreach(string song in keys)
        {
            Data[to_string(optionCount)] = ([
                "name": sprintf("Modify '%s'", convertToTextOfLength(song, 20)),
                "description": 
                    getDictionary("research")->getCompositeDescription(
                        Type, song, currentSongs[song]),
                "type": "modify",
                "value": currentSongs[song] + ([ "name": song ])
            ]);
            optionCount++;
        }
    }
    Data[to_string(optionCount)] = ([
        "name": "Create New Song",
        "description": "This option allows the bard to create a new "
            "song that can be performed.",
        "type": "create",
        "value": ([])
    ]);
    Data[to_string(optionCount + 1)] = ([
        "name": "Exit Song Menu",
        "description": "This option leaves the song composition menu.",
        "type": "exit",
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");
        if (!ret)
        {
            if (Data[selection]["type"] == "create")
            {
                SubselectorObj =
                    clone_object("/guilds/bard/selectors/createSongSelector.c");
                SubselectorObj->setType(Data[selection]["type"]);
                SubselectorObj->setData(Data[selection]["value"]);
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
            else
            {
                SubselectorObj =
                    clone_object("/guilds/bard/selectors/editSongSelector.c");
                SubselectorObj->setType(Data[selection]["type"]);
                SubselectorObj->setData(Data[selection]["value"]);
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
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
    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", "choice enabled", "selector", 
            colorConfiguration),
        " ");
}
