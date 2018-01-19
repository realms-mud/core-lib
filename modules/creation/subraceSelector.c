//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object RacialDictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Choose your subrace";
        AllowUndo = 0;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    if (Data[selection]["file"] != "none")
    {
        User->addTrait(Data[selection]["file"]);
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    RacialDictionary = load_object("/lib/dictionaries/racialDictionary.c");
    if (!RacialDictionary)
    {
        raise_error("raceSelector: ERROR - The racial dictionary is not present!\n");
    }
    Data = RacialDictionary->characterCreationSubraces(User->Race());

    if (!sizeof(Data))
    {
        notify("onSelectorCompleted");
    }
}
