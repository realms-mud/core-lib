//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

protected object TraitDictionary;
private string ChosenTrait = 0;
private int PointsRemaining = 0;

/////////////////////////////////////////////////////////////////////////////
protected mapping traitMenuSetup()
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPointsRemaining(int points)
{
    PointsRemaining = points;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Select a trait to add";
        AllowUndo = 0;
        NumColumns = 2;

        TraitDictionary = load_object("/lib/dictionaries/traitsDictionary.c");
        if (!TraitDictionary)
        {
            raise_error("skillSelectorSubmenu: ERROR - The skills dictionary is not present!\n");
        }
        Data = traitMenuSetup();

        Data[to_string(sizeof(Data) + 1)] = ([
            "name":"Return to previous menu",
            "description": "Return to the main skill selection menu.\n"
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = 1;
    if (Data[selection]["name"] != "Return to previous menu")
    {
        ChosenTrait = Data[selection]["file"];
        if (!User->isTraitOf(ChosenTrait))
        {
            if (PointsRemaining >=
                TraitDictionary->traitObject(ChosenTrait)->query("cost"))
            {
                ret = User->addTrait(ChosenTrait) ? 1 : -1;
            }
            else
            {
                tell_object(User, "You do not have enough available trait points.\n"
                    "If you wish to have this trait, purchase a negative cost trait\n"
                    "or traits to cover the difference.\n");
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
public nomask string selection()
{
    return ChosenTrait;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if (User->isTraitOf(Data[choice]["file"]))
    {
        ret = "\x1b[0;34;1m(*)\x1b[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "You may only select a trait once. \x1b[0;34;1m(*)\x1b[0m \x1b[0;32;1m"
        "denotes an already-chosen trait.\n";
}
