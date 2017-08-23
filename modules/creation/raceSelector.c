//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/baseSelector";

private object RacialDictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void init()
{
    Description = "Choose your race";
    AllowUndo = 0;

    RacialDictionary = load_object("/lib/dictionaries/racialDictionary.c");
    if (!RacialDictionary)
    {
        raise_error("raceSelector: ERROR - The racial dictionary is not present!\n");
    }
    Data = RacialDictionary->characterCreationRaces();
    "baseSelector"::init();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    return User->Race(lower_case(Data[selection]["name"])) ? 1 : -1;
}