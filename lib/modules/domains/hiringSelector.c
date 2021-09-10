//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Type = "Hire Henchmen";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
    if (dictionary)
    {
        Data = dictionary->getHiringMenu(User);
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Exit Hiring Menu",
        "type": "exit",
        "description": "This option lets you exit the hiring menu.\n",
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
