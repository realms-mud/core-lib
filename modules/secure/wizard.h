//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string GroupObj = "/lib/dictionaries/groups/%s.c";
private nosave string PathToCheck;

private nosave mapping validWizardLevels = ([ 
    "apprentice": "[0;31mApprentice Wizard[0m", 
    "wizard": "[0;31mTraining Wizard[0m",
    "creator": "[0;36mWizard[0m",
    "high wizard": "[0;36mHigh Wizard[0m",
    "senior": "[0;36;1mSenior Wizard[0m",
    "admin": "[0;33mAdministrative Wizard[0m", 
    "elder": "[0;33;1mElder Wizard[0m",
    "sage": "[0;33;1mSage Wizard[0m",
    "arch wizard": "[0;34;1mArch Wizard[0m", 
    "demi god": "[0;34;1mDemigod[0m", 
    "god": "[0;34;1mGod[0m", 
    "owner": "[0;34;1mThe Owner of the mud![0m"
]);

private string wizardLevel = 0;
private string *customGroups = ({});

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
