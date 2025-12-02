//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef wizardModule_h
#define wizardModule_h

private nosave string GroupObj = "/lib/services/groups/%s.c";
private nosave string PathToCheck;

private nosave mapping validWizardLevels = ([ 
    "apprentice": "Apprentice Wizard", 
    "wizard": "Training Wizard",
    "creator": "Wizard",
    "emeritus": "Emeritus Wizard",
    "high wizard": "High Wizard",
    "senior": "Senior Wizard",
    "admin": "Administrative Wizard", 
    "elder": "Elder Wizard",
    "sage": "Sage Wizard",
    "arch wizard": "Arch Wizard", 
    "demi god": "Demigod", 
    "god": "God", 
    "owner": "The Owner of the mud!"
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

#endif
