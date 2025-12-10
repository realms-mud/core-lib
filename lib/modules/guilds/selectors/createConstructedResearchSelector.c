//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string SpellType = "ERROR";
private string Constraint = 0;
private mapping SpellData = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    SpellType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setConstraint(string constraint)
{
    Constraint = constraint;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setData(mapping data)
{
    SpellData = data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 1;
    Type = "Constructed Spell";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = "Create New Constructed Spell";
    Data = ([]);

    int optionCount = 1;

    if (Constraint)
    {
        object spellRoot = getService("research")->researchObject(Constraint);

        if (spellRoot)
        {
            // For constructed spells, there's no template selection like songs.
            // We go directly to the edit selector with an empty spell structure.
            Data[to_string(optionCount)] = ([
                "name": sprintf("Create %s", spellRoot->query("name")),
                "description": sprintf("Select this option to create a new %s.",
                    spellRoot->query("name")),
                "type": "create",
                "is disabled": !User->isResearched(Constraint),
                "value": ([
                    "name": 0,
                    "alias": 0,
                    "constraint": Constraint,
                    "type": Constraint,
                    "elements": ({ })
                ])
            ]);
            optionCount++;
        }
    }
    
    Data[to_string(optionCount)] = ([
        "name": "Return To Previous Menu",
        "description": "This option leaves the spell creation menu.",
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
        if (!ret && !Data[selection]["is disabled"])
        {
            SubselectorObj =
                clone_object("/lib/modules/guilds/selectors/editConstructedResearchSelector.c");
            SubselectorObj->setType("create");
            SubselectorObj->setConstraint(Constraint);
            SubselectorObj->setData(Data[selection]["value"]);
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
        notifySynchronous("onSelectorCompleted");
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
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-40s", displayType, "selector",
            colorConfiguration),
        ((colorConfiguration == "none") && 
            (displayType == "choice disabled")) ? "(X)" : "   ");
}