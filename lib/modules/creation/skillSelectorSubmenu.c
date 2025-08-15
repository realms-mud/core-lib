//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

protected object SkillService;
private string *ChosenSkills = ({});
private int isLevelAdvance = 0;
private int PossibleSkills = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void advanceLevel(int numSelections)
{
    isLevelAdvance = 1;
    PossibleSkills = numSelections;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping skillMenuSetup()
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    Description = "Select a skill to advance";
    AllowUndo = 0;
    NumColumns = 2;

    SkillService = getService("skills");
    if (!SkillService)
    {
        raise_error("skillSelectorSubmenu: ERROR - The skills service "
            "is not present!\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (isLevelAdvance)
    {
        Type = "Level up";
    }

    Data = skillMenuSetup();

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Return to previous menu",
        "description" : "Return to the main skill selection menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = 1;
    if (Data[selection]["name"] != "Return to previous menu")
    {
        string chosenSkill = lower_case(Data[selection]["skill"]);
        if (isLevelAdvance && (PossibleSkills > 0))
        {
            PossibleSkills--;
            User->advanceSkill(chosenSkill, 1);
            ChosenSkills += ({ chosenSkill });
            ret = (PossibleSkills <= 0);
        }
        else if (!User->getSkill(chosenSkill, 1))
        {
            ret = User->advanceSkill(chosenSkill, 1) ? 1 : -1;
            if (ret == 1)
            {
                ChosenSkills += ({ chosenSkill });
            }
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *selection()
{
    return ChosenSkills + ({});
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "    ";

    int skillLevel = User->getSkill(lower_case(Data[choice]["skill"]), 1);
    if (isLevelAdvance && skillLevel)
    {
        ret = configuration->decorate(sprintf("(%2d)", skillLevel),
            "selected", "selector", colorConfiguration);
    }
    else if (skillLevel)
    {
        ret = configuration->decorate(" (*)",
            "selected", "selector", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    string extraInfo = "";
    if (!isLevelAdvance)
    {
        extraInfo =
            configuration->decorate("You may only select a skill once. ",
                "instructions", "selector", colorConfiguration) +
            configuration->decorate("(*)", "selected", "selector",
                colorConfiguration) +
            configuration->decorate(" denotes an already-chosen skill.\n",
                "instructions", "selector", colorConfiguration);
    }
    else
    {
        extraInfo = 
            configuration->decorate("(##)", "selected", "selector",
                colorConfiguration) +
            configuration->decorate(sprintf(" denotes current skill level. "
                "You have %d point%s to spend.\n", PossibleSkills,
                PossibleSkills == 1 ? "" : "s"),
                "instructions", "selector", colorConfiguration); 
    }
    return extraInfo;
}
