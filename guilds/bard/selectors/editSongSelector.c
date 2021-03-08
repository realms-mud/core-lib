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
    mapping SongData, object songTemplate)
{
    mapping *elements = filter(SongData["elements"],
        (: $1["type"] == $2 :), section);

    int optionCount = sizeof(Data) + 1;
    
    int firstEntry = sizeof(elements) ?
        elements[0]["order in sequence"] : 1;
    int lastEntry = sizeof(elements) ?
        elements[sizeof(elements) - 1]
        ["order in sequence"] : 1;

    foreach(mapping element in elements)
    {
        string info = regreplace(getDictionary("research")->getCompositeItemDetails(
            element, colorConfiguration, configuration), "^       ", "", 1);
        info = regreplace(info, "\n *$", "", 1);

        Data[to_string(optionCount)] = ([
            "name": info,
            "description": "Select this option to edit or remove",
            "type": "modify",
            "range": ([
                "first": firstEntry,
                "last": lastEntry,
            ]),
            "template": songTemplate,
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
        SongData, songTemplate);

    mapping *matchingSegments = filter(SongData["elements"],
        (: $1["type"] == $2 :), segment);

    int firstEntry = sizeof(matchingSegments) ?
        matchingSegments[0]["order in sequence"] : 1;
    int lastEntry = sizeof(matchingSegments) ?
        matchingSegments[sizeof(matchingSegments) - 1]
        ["order in sequence"] : 1;

    return ([ to_string(optionCount): ([
        "name": sprintf("Add %s segment", segment),
        "description": sprintf("Select this option to add a new "
            "%s segment to your song.", segment),
        "type": "add",
        "range": ([
            "first": firstEntry,
            "last": lastEntry,
        ]),
        "template": songTemplate,
        "value": ([
            "research": 0,
            "description": 0,
            "add": 1,
            "type": segment,
            "order in sequence": lastEntry
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
        "description": "This option deletes the song.\n"
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
                switch (Data[selection]["type"])
                {
                    case "name":
                    {
                        SettingName = 1;
                        tell_object(User, configuration->decorate(
                            "Please enter the song's new name: ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "alias":
                    {
                        SettingAlias = 1;
                        tell_object(User, configuration->decorate(
                            "Please enter the song's new alias: ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "delete":
                    {
                        DeletingSong = 1;
                        tell_object(User, configuration->decorate(
                            "Are you sure you want to delete this song?\n"
                            "This process cannot be undone. (y/n): ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "save":
                    {
                        User->setCompositeResearch(SongData["name"], SongData);

                        tell_object(User, configuration->decorate(
                            "Song saved.\n", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "add":
                    case "modify":
                    {
                        SubselectorObj =
                            clone_object("/guilds/bard/selectors/songSegmentSelector.c");
                        SubselectorObj->setTemplate(Data[selection]["template"]);
                        SubselectorObj->setData(Data[selection]["range"],
                            Data[selection]["value"]);
                        move_object(SubselectorObj, User);
                        SubselectorObj->registerEvent(this_object());
                        SubselectorObj->initiateSelector(User);
                        break;
                    }
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
private nomask void renumberSongElements()
{
    int currentElementNumber = 1;
    SongData["elements"] = sort_array(SongData["elements"],
        (: (($1["order in sequence"] == $2["order in sequence"]) ?
            (member($1, "reordered") ? 1 : 0 )
            : ($1["order in sequence"] > $2["order in sequence"])) :));

    foreach(mapping element in SongData["elements"])
    {
        element["order in sequence"] = currentElementNumber;
        m_delete(element, "reordered");
        currentElementNumber++;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        mapping element = caller->segment();
        
        if (member(element, "delete"))
        {
            SongData["elements"] -= ({ element });
        }
        else if (member(element, "add"))
        {
            m_delete(element, "add");
            SongData["elements"] += ({ element });
        }
        if (member(element, "reordered"))
        {
            if (element["reordered"] == "decrement")
            {
                element["order in sequence"] -= 1;
            }
            element["reordered"] = 1;
        }

        renumberSongElements();
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
