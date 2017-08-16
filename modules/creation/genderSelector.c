//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/baseSelector";

/////////////////////////////////////////////////////////////////////////////
public nomask void init()
{
    Description = "Choose your biological sex";
    AllowUndo = 0;

    Data = ([
        "1":([
            "name":"Male",
                "description" : "Do you really need a description?"
        ]),
        "2":([
            "name":"Female",
                "description" : "Do you really need a description?"
        ])
    ]);
    "baseSelector"::init();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    return User->Gender(to_int(selection)) != 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "Available traits later in character creation cover gender identity concerns.\n";
}