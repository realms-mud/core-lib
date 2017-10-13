//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/baseSelector.c";

private object Dictionary;
private string Source;
private string ChosenItem;

/////////////////////////////////////////////////////////////////////////////
public nomask void setSource(string source)
{
    Source = source;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping researchMenuSetup(string type)
{
    return Dictionary->getResearchOfType(type, User);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Select a research item to view in more detail";
        AllowUndo = 0;
        NumColumns = 2;
        Type = "Research";
        Dictionary = load_object("/lib/dictionaries/researchDictionary.c");

        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!Source)
    {
        raise_error("ERROR: researchSubselector.c - The source has not been "
            "set.\n");
    }
    Data = researchMenuSetup(Source);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Return to previous menu",
        "description" : "Return to the main research menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = 1;
    if (Data[selection]["name"] != "Return to previous menu")
    {
        ChosenItem = lower_case(Data[selection]["name"]);
 /*       if (!User->getSkill(ChosenSkill, 1))
        {
            ret = User->advanceSkill(ChosenSkill, 1) ? 1 : -1;
        }
        else
        {
            ret = 0;
        }*/
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selection()
{
    return ChosenItem;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if (User->isResearched(Data[choice]["type"]) || (member(
        User->availableResearchTrees(), Data[choice]["type"]) > -1))
    {
        ret = "[0;34;1m (*)[0m";
    }
    else if (User->isResearching(Data[choice]["type"]))
    {
        ret = "[0;35m (!)[0m";
    }
    else if (!User->canResearch(Data[choice]["type"]) &&
        (Data[choice]["name"] != "Return to previous menu"))
    {
        ret = "[0;31m (X)[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while "
        "[0;35m(!)[0m[0;32;1m denotes research in progress.\nResearch denoted "
        "[0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n";
}
