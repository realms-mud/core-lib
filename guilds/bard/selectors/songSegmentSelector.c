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
private int minimumRangeValue;
private int maximumRangeValue;

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    SongSegmentType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setData(mapping rangeData, mapping data)
{
    minimumRangeValue = rangeData["first"];
    maximumRangeValue = rangeData["last"];

    printf("first = %d, last = %d\n", minimumRangeValue, maximumRangeValue);
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
private nomask string getSegmentDetails()
{
    string colorConfiguration = User->colorConfiguration();

    string info = regreplace(
        getDictionary("research")->getCompositeItemDetails(
            SongData, colorConfiguration, configuration),
        "       ", "", 1);

    return configuration->decorate("Segment Type: ",
            "field header", "research", colorConfiguration) +
        regreplace(info, "\n *$", "", 1) + "\n" +
        configuration->decorate("Order in sequence: ",
            "field header", "research", colorConfiguration) + 
        configuration->decorate(to_string(SongData["order in sequence"]),
            "field data", "research", colorConfiguration) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addOtherMenuOptions()
{
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Set/change song segment",
        "type": "name",
        "description": "Set or change the name of the song.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Decrement segment ordering",
        "type": "decrement",
        "is disabled": SongData["order in sequence"] <= minimumRangeValue,
        "value": SongData["order in sequence"] - 1,
        "description": "Move this song segment to a point earlier in the "
            "section.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Increment segment ordering",
        "type": "increment",
        "is disabled": SongData["order in sequence"] >= maximumRangeValue,
        "value": SongData["order in sequence"] + 1,
        "description": "Move this song segment to a point later in the "
            "section.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Delete song segment",
        "type": "delete",
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
    Description = "Song Segment Menu" + "\n" +
        getSegmentDetails();

    addOtherMenuOptions();
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
                    case "increment":
                    case "decrement":
                    {
                        ret = 0;
                        SongData["order in sequence"] =
                            Data[selection]["value"];
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
                    case "modify":
                    {
                        break;
                    }
                    case "add":
                    {
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
