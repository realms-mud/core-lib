//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string GroupObj = "/lib/dictionaries/groups/%s.c";
private nosave string PathToCheck;

private nosave string *validWizardLevels = ({ "apprentice", "wizard",
    "creator", "high wizard", "senior", "admin", "elder", "sage",
    "arch wizard", "demi god", "god", "owner" });

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
