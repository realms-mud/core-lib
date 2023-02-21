//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

mapping WizardGroups = ([
    "apprentice":([
        "name": "Apprentice Wizard",
        "sort order": 10,
    ]),
    "wizard":([
        "name": "Training Wizard",
        "sort order": 20,
    ]),
    "creator":([
        "name": "Wizard",
        "sort order": 30,
    ]),
    "emeritus":([
        "name": "Emeritus Wizard",
        "sort order": 30,
    ]),
    "high wizard":([
        "name": "High Wizard",
        "sort order": 40,
    ]),
    "senior":([
        "name": "Senior Wizard",
        "sort order": 50,
    ]),
    "admin":([
        "name": "Admin Wizard",
        "sort order": 60,
    ]),
    "elder":([
        "name": "Elder Wizard",
        "sort order": 70,
    ]),
    "sage":([
        "name": "Sage Wizard",
        "sort order": 80,
    ]),
    "arch wizard":([
        "name": "Arch Wizard",
        "sort order": 90,
    ]),
    "demi god":([
        "name": "Demi God",
        "sort order": 100,
    ]),
    "god":([
        "name": "God",
        "sort order": 110,
    ]),
    "owner":([
        "name": "Mud Owner",
        "sort order": 120,
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

/////////////////////////////////////////////////////////////////////////////
public nomask int getSortOrder(object wizard)
{
    int ret = 0;

    if (wizard && (member(inherit_list(wizard), "/lib/realizations/wizard.c") > -1) &&
        member(WizardGroups, wizard->wizardLevel()))
    {
        ret = WizardGroups[wizard->wizardLevel()]["sort order"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getWizardTitle(object wizard)
{
    string ret = "Player";

    if (wizard && (member(inherit_list(wizard), "/lib/realizations/wizard.c") > -1) &&
        member(WizardGroups, wizard->wizardLevel()))
    {
        ret = WizardGroups[wizard->wizardLevel()]["name"];
    }
    return ret;
}
