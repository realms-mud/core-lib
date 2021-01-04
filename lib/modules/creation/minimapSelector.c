//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        SuppressColon = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = "Would you like to display a mini map in room\n"
        "descriptions that support it?\nWithout mini map:\n";

    load_object(StartLocation());

    object exampleRoom = 
        load_object("/areas/eledhel/southern-city/12x1.c");

    User->setMiniMap("off", 1);
    Description += exampleRoom->long(0, User) + "With mini map:\n";

    User->setMiniMap("on", 1);
    Description += exampleRoom->long(0, User);

    Data = ([
        "1":([
            "name":"Turn Mini Map On",
            "description" : "This option turns on mini map display.\n",
            "value": "on"
        ]),
        "2":([
            "name":"Leave Mini Map Off",
            "description" : "This option turns off mini map display.\n",
            "value": "off",
        ]),
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    User->setMiniMap(Data[selection]["value"], 1);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "You can change this value after character creation "
        "using the 'set' command.\n";
}
