//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string GroupObj = "/lib/dictionaries/groups/%s.c";
private nosave string PathToCheck;

private nosave mapping validWizardLevels = ([ 
    "apprentice": "\x1b[0;31mApprentice Wizard\x1b[0m", 
    "wizard": "\x1b[0;31mTraining Wizard\x1b[0m",
    "creator": "\x1b[0;36mWizard\x1b[0m",
    "emeritus": "\x1b[0;36mEmeritus Wizard\x1b[0m",
    "high wizard": "\x1b[0;36mHigh Wizard\x1b[0m",
    "senior": "\x1b[0;36;1mSenior Wizard\x1b[0m",
    "admin": "\x1b[0;33mAdministrative Wizard\x1b[0m", 
    "elder": "\x1b[0;33;1mElder Wizard\x1b[0m",
    "sage": "\x1b[0;33;1mSage Wizard\x1b[0m",
    "arch wizard": "\x1b[0;34;1mArch Wizard\x1b[0m", 
    "demi god": "\x1b[0;34;1mDemigod\x1b[0m", 
    "god": "\x1b[0;34;1mGod\x1b[0m", 
    "owner": "\x1b[0;34;1mThe Owner of the mud!\x1b[0m"
]);

private string wizardLevel = 0;
private string *customGroups = ({});
private string workingDirectory = 0;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadWizard(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        wizardLevel = persistence->extractSaveData("wizard level", data);
        customGroups = persistence->extractSaveData("custom groups", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendWizard()
{
    return ([
        "wizard level": wizardLevel,
        "custom groups": customGroups
    ]);
}
