//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

mapping WizardGroups = ([
    "apprentice":([
        "name": "Apprentice Wizard",
    ]),
    "wizard":([
        "name": "Training Wizard",
    ]),
    "creator":([
        "name": "Wizard",
    ]),
    "high wizard":([
        "name": "High Wizard",
    ]),
    "senior":([
        "name": "Senior Wizard",
    ]),
    "admin":([
        "name": "Admin Wizard",
    ]),
    "elder":([
        "name": "Elder Wizard",
    ]),
    "sage":([
        "name": "Sage Wizard",
    ]),
    "arch wizard":([
        "name": "Arch Wizard",
    ]),
    "demi god":([
        "name": "Demi God",
    ]),
    "god":([
        "name": "God",
    ]),
    "owner":([
        "name": "Mud Owner",
    ])
]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidFaction(string type)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isWizLocked()
{
    return 0;
}