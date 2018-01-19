//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

protected object SkillDictionary;
private string ChosenSkill = 0;

/////////////////////////////////////////////////////////////////////////////
protected mapping skillMenuSetup()
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Select a skill to advance";
        AllowUndo = 0;
        NumColumns = 2;

        SkillDictionary = load_object("/lib/dictionaries/skillsDictionary.c");
        if (!SkillDictionary)
        {
            raise_error("skillSelectorSubmenu: ERROR - The skills dictionary is not present!\n");
        }
        Data = skillMenuSetup();

        Data[to_string(sizeof(Data) + 1)] = ([
            "name":"Return to previous menu",
                "description" : "Return to the main skill selection menu.\n"
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = 1;
    if (Data[selection]["name"] != "Return to previous menu")
    {
        ChosenSkill = lower_case(Data[selection]["name"]);
        if (!User->getSkill(ChosenSkill, 1))
        {
            ret = User->advanceSkill(ChosenSkill, 1) ? 1 : -1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selection()
{
    return ChosenSkill;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if (User->getSkill(lower_case(Data[choice]["name"]), 1))
    {
        ret = "[0;34;1m(*)[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "You may only select a skill once. [0;34;1m(*)[0m [0;32;1m"
        "denotes an already-chosen skill.\n";
}
