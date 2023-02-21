//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
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
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    return User->Gender(lower_case(Data[selection]["name"])) != 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "Available traits later in character creation cover gender identity concerns.\n";
}
