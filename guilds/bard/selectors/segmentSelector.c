//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SongTemplate;
private string Section;
private string Research = 0;
private string InstrumentType = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setData(object songTemplate, string section,
    string instrumentType)
{
    SongTemplate = songTemplate;
    Section = section;
    InstrumentType = instrumentType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string research()
{
    return Research;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string instrumentType()
{
    return InstrumentType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    SuppressColon = 1;
    Type = "Song";
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    Description = "Select Song Segment Menu" + "\n";

    object *potentialElements = SongTemplate->query("segments") ?
        getService("research")->getResearchItemsBySectionType(User,
            filter(SongTemplate->query("segments"),
                (: member(m_indices($1), $2) > -1 :), Section)[0][Section]
        ) : ({ });

    int optionCount = 1;
    if (sizeof(potentialElements))
    {
        potentialElements = sort_array(potentialElements,
            (: $1->query("name") > $2->query("name") :));

        foreach(object element in potentialElements)
        {
            Data[to_string(optionCount)] = ([
                "name": convertToTextOfLength(element->query("name"), 25),
                "description": regreplace(
                    getService("research")->getCompositeItemDetails(
                        ([ "research": program_name(element),
                           "type": Section
                        ]), colorConfiguration, configuration),
                        "       ", "", 1),
                "type": "select",
                "instrument type": element->query("composite class"),
                "is disabled": InstrumentType && 
                    (InstrumentType != element->query("composite class")) &&
                    ("lyric" != element->query("composite class")),
                "value": program_name(element)
            ]);
            optionCount++;
        }
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Return to Previous Menu",
        "description": "This option leaves the segment composition menu.",
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

        if (Data[selection]["type"] == "select")
        {
            ret = 1;
            Research = Data[selection]["value"];

            if (Data[selection]["instrument type"] != "lyric")
            {
                InstrumentType = Data[selection]["instrument type"];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s  ",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", displayType, "selector",
            colorConfiguration),
        ((colorConfiguration == "none") && 
            (displayType == "choice disabled")) ? "(X)" : "   ");
}
