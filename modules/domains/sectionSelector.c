//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private mapping SectionData = 0;
private object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
private object SubselectorObj;
private string ConfirmChoice;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    mapping info = dictionary->getPlayerHolding(User, location);
    if (mappingp(info))
    {
        Location = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setDetails(mapping data, string name, string selection,
    mapping selectedSections)
{
    SectionData = data + ([]);
    SectionData["name"] = name;
    SectionData["selected section"] = selection;
    SectionData["selected sections"] = selectedSections;
    SectionData["selected materials"] = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        NumColumns = 2;
        Description = "Building Sections";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && SectionData)
    {
        Description = (member(SectionData, "name") ?
            (dictionary->generateTitle(SectionData["name"]) + ":\n") :
            "Building Sections:\n") +
            configuration->decorate(format(sprintf("From this menu, you can "
                "select the materials to construct with and style of %s "
                "to build for your %s project at %s.",
                SectionData["selected section"], SectionData["name"],
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration) + "\n" +
            dictionary->getBuildSectionInfo(User, SectionData) + "\n";

        Data = dictionary->getBuildSectionMenu(User, Location,
            SectionData);

        ConfirmChoice = to_string(sizeof(Data) + 1);

        Data[ConfirmChoice] = ([
            "name":"Begin Construction",
            "type": "construct",
            "description": "This option lets you begin construction on "
                "the building component.\n",
            "is disabled" : !dictionary->beginConstructionIsEnabled(SectionData),
            "canShow": 1
        ]);

        Data[to_string(sizeof(Data) + 1)] = ([
            "name":"Exit Section Menu",
            "type" : "exit",
            "description" : "This option lets you exit the building "
                "projects menu.\n",
            "canShow" : 1
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        SectionData["selected materials"][caller->materialType()] =
            caller->selection();
    }
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = sprintf("%9s", "");
    if ((Data[choice]["type"] == "construct") && Data[choice]["is disabled"] &&
        (User->colorConfiguration() == "none"))
    {
        ret = sprintf("%-9s", "N/A");
    }
    else if (Data[choice]["type"] == "material")
    {
        ret = configuration->decorate(sprintf("%-9s",
            (!Data[choice]["is disabled"] && (
                member(SectionData["selected materials"], 
                    Data[choice]["material type"]) && 
                Data[choice]["selected material"])) ?
            SectionData["selected materials"][Data[choice]["material type"]] :
            (Data[choice]["is disabled"] ? "N/A" : "none")),
            "selected", "selector", colorConfiguration);
    }
    else if (member(SectionData, "chosen section") &&
        (Data[choice]["type"] == SectionData["chosen section"]))
    {
        ret = configuration->decorate(sprintf("%-9s",
            (User->charsetConfiguration() == "unicode") ? "     (\xe2\x80\xa0) " :
            "     (*) "),
            "selected", "selector", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string choiceColor = member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"] ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-23s", choiceColor, "selector", colorConfiguration),
        displayDetails(choice),
        Data[choice]["layout panel"] || "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");

        if (!ret)
        {
            if (Data[selection]["type"] == "construct")
            {
                ret = !Data[selection]["is disabled"];
            }
            else if (!Data[selection]["is disabled"] &&
                (Data[selection]["type"] == "material"))
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/materialsSelector.c");
                SubselectorObj->setMaterialData(
                    Data[selection]["material type"], SectionData);
                SubselectorObj->setLocation(Location);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
            else if(!Data[selection]["is disabled"])
            {
                ret = 0;
                SectionData["chosen section"] = Data[selection]["type"];
                SectionData["selected materials"] = ([]);
                setUpUserForSelection();
            }
        }
        else
        {
            SectionData = ([]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getSectionData()
{
    return SectionData + ([]);
}
