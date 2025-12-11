//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Category = "";
private string *Items = ({});
private string Constraint = "";
private mapping SelectedComponent = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask void setCategory(string category)
{
    Category = category;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setItems(string *items)
{
    Items = items;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setConstraint(string constraint)
{
    Constraint = constraint;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping selectedComponent()
{
    return SelectedComponent + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    Type = "Component";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = sprintf("Select %s Component", capitalize(Category));
    Data = ([]);

    object researchService = getService("research");
    int optionCount = 1;

    foreach(string item in sort_array(Items, (: $1 > $2 :)))
    {
        object researchObj = researchService->researchObject(item);
        if (researchObj)
        {
            int isResearched = User->isResearched(item);
            string name = researchObj->query("name");
            
            Data[to_string(optionCount)] = ([
                "name": name,
                "description": researchObj->query("description") + "\n" +
                    researchObj->conciseResearchDetails(),
                "type": "select",
                "is disabled": !isResearched,
                "research": item,
                "category": Category
            ]);
            optionCount++;
        }
    }
    
    Data[to_string(optionCount)] = ([
        "name": "Return To Previous Menu",
        "description": "This option returns to the spell editing menu.",
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
            SelectedComponent = ([
                "research": Data[selection]["research"],
                "type": Data[selection]["category"]
            ]);
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-28s", displayType, "selector",
            colorConfiguration),
        ((colorConfiguration == "none") && 
            (displayType == "choice disabled")) ? "(X)  " : "     ");
}
