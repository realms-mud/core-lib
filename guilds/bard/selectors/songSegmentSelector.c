//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object SongTemplate;
private mapping SongData = ([]);
private int SettingDescription = 0;
private int DeletingSegment = 0;
private int minimumRangeValue;
private int maximumRangeValue;

/////////////////////////////////////////////////////////////////////////////
public nomask void setTemplate(object template)
{
    SongTemplate = template;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setData(mapping rangeData, mapping data)
{
    minimumRangeValue = rangeData["first"];
    maximumRangeValue = rangeData["last"];

    SongData = data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping segment()
{
    return SongData;
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

    if (info == "")
    {
        info = configuration->decorate("<None selected>",
            "failure message", "research", colorConfiguration);
    }

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
        "name": "Select Segment Details",
        "type": "segment type",
        "description": "Set or change the type of lyrical or instrumental "
            "component for this segment of the song.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Change lyrics/instrumental",
        "type": "name",
        "is disabled": SongData["research"] == 0,
        "description": "Set or change the lyrics or instrumental component "
            "for this segment of the song.\n"
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
        "description": "This option removes the song segment from the song.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Return to Edit Song Menu",
        "description": "This option leaves the segment composition menu.",
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
        if (SettingDescription)
        {
            ret = 0;
            SettingDescription = 0;
            SongData["description"] = selection;
        }
        else if (DeletingSegment)
        {
            if (sizeof(regexp(({ selection }), "[Yy]([Ee][Ss]|)")))
            {
                SongData["delete"] = 1;
                ret = 1;
            }
            else
            {
                tell_object(User, configuration->decorate(
                    "Deletion aborted.\n", "details",
                    "selector", colorConfiguration));
            }
            DeletingSegment = 0;
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
                        if (!Data[selection]["is disabled"])
                        {
                            SettingDescription = 1;
                            tell_object(User, configuration->decorate(
                                "Please enter the lyrics/descriptive text: \n",
                                "details", "selector", colorConfiguration));
                        }
                        break;
                    }
                    case "decrement":
                    case "increment":
                    {
                        if (!Data[selection]["is disabled"])
                        {
                            ret = 0;
                            SongData["reordered"] = Data[selection]["type"];
                            SongData["order in sequence"] =
                                Data[selection]["value"];
                        }
                        break;
                    }
                    case "delete":
                    {
                        DeletingSegment = 1;
                        tell_object(User, configuration->decorate(
                            "Are you sure you want to delete this segment?\n"
                            "This process cannot be undone. (y/n): ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "segment type":
                    {
                        SubselectorObj =
                            clone_object("/guilds/bard/selectors/segmentSelector.c");
                        SubselectorObj->setData(SongTemplate, SongData["type"]);
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
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        SongData["research"] = caller->research();
        if (!SongData["description"])
        {
            object researchItem = getDictionary("research")->researchObject(
                SongData["research"]);
            if (researchItem)
            {
                SongData["description"] =
                    researchItem->query("default composite description");
            }
        }
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected int handleSpecialSelection()
{
    return SettingDescription || DeletingSegment;
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
