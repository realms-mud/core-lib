//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private mapping SectionData = 0;
private object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
private object SubselectorObj;

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
public nomask void setDetails(mapping data, string name, string selection)
{
    SectionData = data + ([]);
    SectionData["name"] = name;
    SectionData["selected section"] = selection;
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
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string choiceColor = member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"] ? "choice disabled" : "choice enabled";

    return sprintf("    [%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-26s", choiceColor, "selector", colorConfiguration),
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
            if (Data[selection]["type"] == "material")
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/materialsSelector.c");
                SubselectorObj->setMaterialData(Data[selection]["data"]);
                SubselectorObj->setLocation(Location);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
