//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string SpellType = "ERROR";
private string Constraint = 0;
private mapping SpellData = ([]);
private int SettingName = 0;
private int SettingAlias = 0;
private int DeletingSpell = 0;

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
    SpellData = data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 1;
    SuppressColon = 1;
    Type = "Constructed Spell";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getSpellDetails(object spellRoot, 
    string colorConfiguration)
{
    return configuration->decorate("Spell Type: ",
                "field header", "research", colorConfiguration) +
            configuration->decorate(spellRoot->query("name"),
                "field data", "research", colorConfiguration) + "\n" +
            configuration->decorate("Spell Name: ",
                "field header", "research", colorConfiguration) +
            (SpellData["name"] ? configuration->decorate(SpellData["name"],
                    "field data", "research", colorConfiguration) :
                configuration->decorate("<Name Missing>",
                    "failure message", "research", colorConfiguration)) + "\n" +
            configuration->decorate("Spell Alias: ",
                "field header", "research", colorConfiguration) +
            (SpellData["alias"] ? configuration->decorate(SpellData["alias"],
                    "field data", "research", colorConfiguration) :
                configuration->decorate("<No Alias>",
                    "failure message", "research", colorConfiguration)) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCategoryFromRule(string rule)
{
    // Extract category from rule like "form must include only one of"
    return explode(rule, " ")[0];
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *getElementsForCategory(string category)
{
    if (!member(SpellData, "elements") || !pointerp(SpellData["elements"]))
    {
        return ({});
    }
    return filter(SpellData["elements"],
        (: $1["type"] == $2 :), category);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addCategoryOptions(string rule, string *items, 
    object spellRoot, int optionCount)
{
    string category = getCategoryFromRule(rule);
    mapping *existingElements = getElementsForCategory(category);
    
    object researchService = getService("research");

    // Show existing selections for this category
    foreach(mapping element in existingElements)
    {
        object researchObj = researchService->researchObject(element["research"]);
        string name = researchObj ? researchObj->query("name") : "Unknown";
        
        Data[to_string(optionCount)] = ([
            "name": sprintf("[%s] %s (selected)", capitalize(category), name),
            "description": sprintf("Select to remove %s from the spell.", name),
            "type": "remove",
            "category": category,
            "rule": rule,
            "value": element
        ]);
        optionCount++;
    }

    // Determine if we can add more based on rule type
    int canAddMore = 0;
    if (sizeof(regexp(({ rule }), "must include only one of")) ||
        sizeof(regexp(({ rule }), "can include only one of")))
    {
        canAddMore = (sizeof(existingElements) == 0);
    }
    else if (sizeof(regexp(({ rule }), "must include any of")) ||
             sizeof(regexp(({ rule }), "can include any of")))
    {
        canAddMore = 1;
    }

    if (canAddMore)
    {
        // Add option to select from available items
        Data[to_string(optionCount)] = ([
            "name": sprintf("Add %s component", capitalize(category)),
            "description": sprintf("Select a %s component for your spell.\n%s",
                category, rule),
            "type": "add",
            "category": category,
            "rule": rule,
            "items": items
        ]);
        optionCount++;
    }

    return optionCount;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addOtherMenuOptions()
{
    // Check if spell is valid (has required components)
    int hasForm = sizeof(getElementsForCategory("form")) > 0;
    int hasFunction = sizeof(getElementsForCategory("function")) > 0;
    int hasEffect = sizeof(getElementsForCategory("effect")) > 0;
    int isValid = hasForm && hasFunction && hasEffect && SpellData["name"];

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Set/change spell name",
        "type": "name",
        "description": "Set or change the name of the spell.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Set/change spell alias",
        "type": "alias",
        "description": "Set or change the alias of the spell. This alias "
            "can then be used as shorthand for casting the spell.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Save the spell",
        "type": "save",
        "is disabled": !isValid,
        "description": isValid ? 
            "This option saves the spell data and allows you "
                "to cast the spell at a later point in time.\n" :
            "Cannot save: spell requires a name, form, function, and at least one effect.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Delete the spell",
        "type": "delete",
        "is disabled": !SpellData["name"],
        "description": "This option deletes the spell.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Exit Menu",
        "description": "This option leaves the spell composition menu.",
        "type": "exit",
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    Description = 
        sprintf("%s Spell Menu", capitalize(SpellType)) + "\n";

    string colorConfiguration = User->colorConfiguration();

    if (mappingp(SpellData) && sizeof(SpellData) && Constraint)
    {
        object spellRoot = getService("research")->researchObject(Constraint);

        if (spellRoot)
        {
            Description += getSpellDetails(spellRoot, colorConfiguration);

            mapping rules = spellRoot->query("constructed rules");
            if (mappingp(rules))
            {
                int optionCount = 1;
                
                // Process each rule category
                foreach(string rule in sort_array(m_indices(rules), (: $1 > $2 :)))
                {
                    optionCount = addCategoryOptions(rule, rules[rule], 
                        spellRoot, optionCount);
                }
            }

            addOtherMenuOptions();
        }
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
            SpellData["name"] = selection;
        }
        else if (SettingAlias)
        {
            ret = 0;
            SettingAlias = 0;
            SpellData["alias"] = selection;
        }
        else if (DeletingSpell)
        {
            if (sizeof(regexp(({ selection }), "[Yy]([Ee][Ss]|)")))
            {
                User->deleteConstructedResearch(SpellData["name"]);
                ret = 1;
            }
            else
            {
                tell_object(User, configuration->decorate(
                    "Deletion aborted.\n", "details",
                    "selector", colorConfiguration));
            }
            DeletingSpell = 0;
        }
        else
        {
            ret = (Data[selection]["type"] == "exit") || (selection == "abort");

            if (!ret && (!member(Data[selection], "is disabled") || 
                !Data[selection]["is disabled"]))
            {
                switch (Data[selection]["type"])
                {
                    case "name":
                    {
                        SettingName = 1;
                        tell_object(User, configuration->decorate(
                            "Please enter the spell's new name: ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "alias":
                    {
                        SettingAlias = 1;
                        tell_object(User, configuration->decorate(
                            "Please enter the spell's new alias: ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "delete":
                    {
                        DeletingSpell = 1;
                        tell_object(User, configuration->decorate(
                            "Are you sure you want to delete this spell?\n"
                            "This process cannot be undone. (y/n): ", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "save":
                    {
                        ret = 1;
                        if (!SpellData["alias"])
                        {
                            SpellData["alias"] = SpellData["name"];
                        }
                        User->setConstructedResearch(SpellData["name"], SpellData);

                        tell_object(User, configuration->decorate(
                            "Spell saved.\n", "details",
                            "selector", colorConfiguration));
                        break;
                    }
                    case "add":
                    {
                        SubselectorObj =
                            clone_object("/lib/modules/guilds/selectors/constructedComponentSelector.c");
                        SubselectorObj->setCategory(Data[selection]["category"]);
                        SubselectorObj->setItems(Data[selection]["items"]);
                        SubselectorObj->setConstraint(Constraint);
                        move_object(SubselectorObj, User);
                        SubselectorObj->registerEvent(this_object());
                        SubselectorObj->initiateSelector(User);
                        break;
                    }
                    case "remove":
                    {
                        // Remove the element from the spell
                        SpellData["elements"] -= ({ Data[selection]["value"] });
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
        mapping element = caller->selectedComponent();
        
        if (mappingp(element) && sizeof(element))
        {
            if (!member(SpellData, "elements") || !pointerp(SpellData["elements"]))
            {
                SpellData["elements"] = ({});
            }
            SpellData["elements"] += ({ element });
        }

        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected int handleSpecialSelection()
{
    return SettingName || SettingAlias || DeletingSpell;
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
        configuration->decorate("%-40s", displayType, "selector",
            colorConfiguration),
        ((colorConfiguration == "none") && 
            (displayType == "choice disabled")) ? "(X)" : "   ");
}
