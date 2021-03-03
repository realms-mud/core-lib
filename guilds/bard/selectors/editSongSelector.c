//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string SongSegmentType = "ERROR";
private mapping SongData = ([]);
private int SettingName = 0;
private int SettingAlias = 0;
private int DeletingSong = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    SongSegmentType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setData(mapping data)
{
    SongData = data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        NumColumns = 1;
        SuppressColon = 1;
        Type = "Song";
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int GetExistingElementsForSongSection(string section,
    mapping SongData)
{
    mapping *elements = filter(SongData["elements"],
        (: $1["type"] == $2 :), section);

    int optionCount = sizeof(Data) + 1;

    foreach(mapping element in elements)
    {
        string info = regreplace(getDictionary("research")->getCompositeItemDetails(
            element, colorConfiguration, configuration), "^       ", "", 1);
        info = regreplace(info, "\n *$", "", 1);

        Data[to_string(optionCount)] = ([
            "name": info,
            "description": "Select this option to edit or remove",
            "type": "modify",
            "value": element
        ]);
        optionCount++;
    }

    return optionCount;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getSongDetails(object songTemplate, 
    string colorConfiguration)
{
    return configuration->decorate("Song Type: ",
                "field header", "research", colorConfiguration) +
            configuration->decorate(songTemplate->query("name"),
                "field data", "research", colorConfiguration) + "\n" +
            configuration->decorate("Song Name: ",
                "field header", "research", colorConfiguration) +
            (SongData["name"] ? configuration->decorate(SongData["name"],
                    "field data", "research", colorConfiguration) :
                configuration->decorate("<Name Missing>",
                    "failure message", "research", colorConfiguration)) + "\n" +
            configuration->decorate("Song Alias: ",
                "field header", "research", colorConfiguration) +
            (SongData["alias"] ? configuration->decorate(SongData["alias"],
                    "field data", "research", colorConfiguration) :
                configuration->decorate("<No Alias>",
                    "failure message", "research", colorConfiguration)) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping addSongSegmentOption(string segment, 
    object songTemplate)
{
    int optionCount = GetExistingElementsForSongSection(segment,
        SongData);

    return ([ to_string(optionCount): ([
        "name": sprintf("Add %s segment", segment),
        "description": sprintf("Select this option to add a new "
            "%s segment to your song.", segment),
        "type": "add",
        "value": ([
            "type": songTemplate,
            "segment": segment,
            "order in sequence": sizeof(filter(SongData["elements"],
                (: $1["type"] == $2 :), segment))
        ])
    ]) ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addOtherMenuOptions()
{
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Set/change song name",
        "type": "name",
        "description": "Set or change the name of the song.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Set/change song alias",
        "type": "alias",
        "description": "Set or change the alias of the song. This alias "
            "can then be used as shorthand for performing the song.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Save the song",
        "type": "save",
        "is disabled": (!SongData["name"] || !sizeof(SongData["elements"])),
        "description": "This option saves the song data and allows you "
            "to perform the song at a later point in time.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Delete the song",
        "type": "delete",
        "is disabled": !SongData["name"],
        "description": "This option saves the song data and allows you "
            "to perform the song at a later point in time.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Exit Menu",
        "description": "This option leaves the song composition menu.",
        "type": "exit",
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    Description = 
        sprintf("%s Song Menu", capitalize(SongSegmentType)) + "\n";

    string colorConfiguration = User->colorConfiguration();

    if (mappingp(SongData) && sizeof(SongData) && member(SongData, "type"))
    {
        object songTemplate = getDictionary("research")->researchObject(
            SongData["type"]);

        Description += getSongDetails(songTemplate, colorConfiguration);

        if (songTemplate && songTemplate->query("segments"))
        {
            foreach(string segment in songTemplate->query("segments"))
            {
                Data += addSongSegmentOption(segment, songTemplate);
            }
        }

        addOtherMenuOptions();
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    printf("Selection = %O\n", selection);
    if (User)
    {
        if (SettingName)
        {
            ret = 0;
            SettingName = 0;
            SongData["name"] = selection;
        }
        else if (SettingAlias)
        {
            ret = 0;
            SettingAlias = 0;
            SongData["alias"] = selection;
        }
        else if (DeletingSong)
        {
            if (sizeof(regexp(({ selection }), "[Yy]([Ee][Ss]|)")))
            {
                User->deleteCompositeResearch(SongData["name"]);
                ret = 1;
            }
            else
            {
                tell_object(User, configuration->decorate(
                    "Deletion aborted.\n", "details",
                    "selector", colorConfiguration));
            }
            DeletingSong = 0;
        }
        else
        {
            ret = (Data[selection]["type"] == "exit") || (selection == "abort");

            if (!ret)
            {
                if (Data[selection]["type"] == "name")
                {
                    SettingName = 1;
                    tell_object(User, configuration->decorate(
                        "Please enter the song's new name: ", "details",
                        "selector", colorConfiguration));
                }
                if (Data[selection]["type"] == "alias")
                {
                    SettingAlias = 1;
                    tell_object(User, configuration->decorate(
                        "Please enter the song's new alias: ", "details",
                        "selector", colorConfiguration));
                }
                if (Data[selection]["type"] == "delete")
                {
                    DeletingSong = 1;
                    tell_object(User, configuration->decorate(
                        "Are you sure you want to delete this song?\n"
                        "This process cannot be undone. (y/n): ", "details",
                        "selector", colorConfiguration));
                }
                if (Data[selection]["type"] == "save")
                {
                    User->setCompositeResearch(SongData["name"], SongData);

                    tell_object(User, configuration->decorate(
                        "Song saved.\n", "details",
                        "selector", colorConfiguration));
                }
            }
        }

        if (!ret)
        {
            setUpUserForSelection();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        SongData = caller->songData();
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected int handleSpecialSelection()
{
    return SettingName || SettingAlias || DeletingSong;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj) || handleSpecialSelection();
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", displayType, "selector",
            colorConfiguration),
        ((colorConfiguration == "none") && 
            (displayType == "choice disabled")) ? "(X)" : "   ");
}
