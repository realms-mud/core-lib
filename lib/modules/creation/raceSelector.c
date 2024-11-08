//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object RacialDictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    Description = "Choose your race";
    AllowUndo = 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    RacialDictionary = load_object("/lib/dictionaries/racialDictionary.c");
    if (!RacialDictionary)
    {
        raise_error("raceSelector: ERROR - The racial dictionary is not present!\n");
    }

    Data = RacialDictionary->characterCreationRaces(User);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    return User->Race(lower_case(Data[selection]["name"])) ? 1 : -1;
}
