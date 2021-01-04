//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string MaterialType;
private string Selection;
private mapping MaterialData = 0;
private object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

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
public nomask void setMaterialData(string type, mapping data)
{
    MaterialType = type;
    MaterialData = data;
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
        Description = "Materials";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && MaterialData)
    {
        Description = "Select Material:\n" +
            configuration->decorate(format(sprintf("From this menu, you can "
                "select the type of %s to construct with for your %s "
                "of your %s project at %s.", MaterialType,
                MaterialData["selected section"], MaterialData["name"],
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration);

        Data = dictionary->getMaterialsOfType(MaterialType, User,
            MaterialData);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";

    return sprintf("    [%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", displayType, "selector", colorConfiguration),
        displayDetails(choice),
        Data[choice]["layout panel"] || "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return configuration->decorate("P", "note", "selector", colorConfiguration) +
        configuration->decorate(" denotes unrealized prerequisites.\n",
            "details", "selector", colorConfiguration) +
        configuration->decorate("M", "note", "selector", colorConfiguration) +
        configuration->decorate(" denotes that proper quantities of the "
            "material requirements are missing.\n",
            "details", "selector", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string *flags = ({});

    if (member(Data[choice], "prerequisites met") &&
        !Data[choice]["prerequisites met"])
    {
        flags += ({ "P" });
    }
    if (member(Data[choice], "has materials") &&
        !Data[choice]["has materials"])
    {
        flags += ({ "M" });
    }
    string ret = sizeof(flags) ? configuration->decorate(sprintf("(%s)",
        implode(flags, ",")), "note", "selector", colorConfiguration) : "     ";

    if (sizeof(flags) == 1)
    {
        ret += "  ";
    }
    return member(Data[choice], "canShow") ? ret : "";
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");

        if (!ret && Data[selection]["canShow"])
        {
            Selection = Data[selection]["type"];
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string selection()
{
    return Selection;
}

/////////////////////////////////////////////////////////////////////////////
public string materialType()
{
    return MaterialType;
}
