//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object RaceService;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    Description = "Choose your race";
    AllowUndo = 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    RaceService = getService("racial");
    if (!RaceService)
    {
        raise_error("raceSelector: ERROR - The race service is not present!\n");
    }

    Data = RaceService->characterCreationRaces(User);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    return User->Race(lower_case(Data[selection]["name"])) ? 1 : -1;
}
