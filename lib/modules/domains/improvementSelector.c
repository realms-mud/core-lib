//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    Location = location;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Main Menu";
    Type = "Resources and Holdings";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object Service = getService("domain");
    if (Service)
    {
        Data = Service->getHoldingsMenu(User);
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Exit Resources and Holdings Menu",
        "type": "exit",
        "description": "This option lets you exit the resources "
            "and holdings menu.\n",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}
