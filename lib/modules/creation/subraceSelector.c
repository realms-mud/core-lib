//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object RaceService;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    Description = "Choose your subrace";
    AllowUndo = 0;
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
    RaceService = getService("racial");
    if (!RaceService)
    {
        raise_error("raceSelector: ERROR - The race service is not present!\n");
    }
    Data = RaceService->characterCreationSubraces(User->Race());

    if (!sizeof(Data))
    {
        notifySynchronous("onSelectorCompleted");
    }
}
