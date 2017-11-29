//*****************************************************************************
// Class: wizard
// File Name: wizard.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";
#include "/lib/modules/secure/wizard.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfWizard()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string wizardLevel()
{
    return wizardLevel ? wizardLevel : "player";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string wizardInformation()
{
    // TODO - add wizard info such as GM duties, etc.
    string ret = "";
    if (wizardLevel)
    {
        ret = sprintf("[0;30;1m%s is a mud wizard -> %s[0m\n",
            capitalize(this_object()->Pronoun()), validWizardLevels[wizardLevel]);
    }
    else
    {
        ret = sprintf("[0;30;1m%s is a Player.[0m\n",
            capitalize(this_object()->Pronoun()));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validWizardLevel(string level)
{
    return member(m_indices(validWizardLevels), level) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWizardLevel(string level, object granter)
{
    if (granter && validWizardLevel(level) && 
        (program_name(granter) == "lib/realizations/wizard.c"))
    {
        string *granterGroups = granter->groups() -
            ({ granter->wizardLevel() });

        int canGrantLevel = (member(granterGroups, level) > -1) &&
            interactive(granter);

        if (canGrantLevel)
        {
            wizardLevel = level;
            log_file("setWizardLevel", sprintf("%s promoted %s to %s.\n",
                granter->Name(), this_object()->Name(), level));
        }
        else
        {
            log_file("setWizardLevel", 
                sprintf("%s failed to promote %s to %s.\n",
                granter->Name(), this_object()->Name(), level));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *groups()
{
    string *wizardGroups = ({ });

    // Yes, these are supposed to fall through to the lower levels.
    switch (wizardLevel)
    {
        case "owner":
        {
            wizardGroups += ({ "owner" });
        }
        case "god":
        {
            // This is done instead of += to reverse the search order
            wizardGroups = ({ "god" }) + wizardGroups;
        }
        case "demigod":
        {
            wizardGroups = ({ "demigod" }) + wizardGroups;
        }
        case "archwizard":
        {
            wizardGroups = ({ "archwizard" }) + wizardGroups;
        }
        case "sage":
        {
            wizardGroups = ({ "sage" }) + wizardGroups;
        }
        case "elder":
        {
            wizardGroups = ({ "elder" }) + wizardGroups;
        }
        case "admin":
        {
            wizardGroups = ({ "admin" }) + wizardGroups;
        }
        case "senior":
        {
            wizardGroups = ({ "senior" }) + wizardGroups;
        }
        case "highwizard":
        {
            wizardGroups = ({ "highwizard" }) + wizardGroups;
        }
        case "creator":
        {
            wizardGroups = ({ "creator" }) + wizardGroups;
        }
        case "wizard":
        {
            wizardGroups = ({ "wizard" }) + wizardGroups;
        }
        case "apprentice":
        {
            wizardGroups = ({ "apprentice" }) + wizardGroups;
        }
        default:
        {
            wizardGroups = ({ "player" }) + wizardGroups;
        }
    }

    string *custom = customGroups(this_object());
    if (custom && sizeof(custom))
    {
        wizardGroups += custom;
    }
    return wizardGroups + ({ });
}

/////////////////////////////////////////////////////////////////////////////
private nomask object *groupObjects()
{
    object *list = ({});

    foreach(string group in groups())
    {
        string groupFile = sprintf(GroupObj, group);
        if (file_size(groupFile) > 0)
        {
            list += ({ load_object(groupFile) });
        }
    }
    return list;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string hasReadAccess(string path)
{
    string ret = 0;
    PathToCheck = path;

    object *filteredGroups = filter(groupObjects(),
        (: return $1->hasReadAccess(this_object(), PathToCheck); :));
    if(sizeof(filteredGroups))
    {
        ret = filteredGroups[0]->hasReadAccess(this_object(), path);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string groupReadAccess(string path)
{
    string ret = "";
    PathToCheck = path;

    object *filteredGroups = filter(groupObjects(),
        (: return $1->hasReadAccess(this_object(), PathToCheck); :));
    if (sizeof(filteredGroups))
    {
        ret = sprintf("R: %s", filteredGroups[0]->group());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string hasWriteAccess(string path)
{
    string ret = 0;
    PathToCheck = path;

    object *filteredGroups = filter(groupObjects(),
        (: return $1->hasWriteAccess(this_object(), PathToCheck); :));
    if(sizeof(filteredGroups))
    {
        ret = filteredGroups[0]->hasWriteAccess(this_object(), path);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string groupWriteAccess(string path)
{
    string ret = "";
    PathToCheck = path;

    object *filteredGroups = filter(groupObjects(),
        (: return $1->hasWriteAccess(this_object(), PathToCheck); :));
    if (sizeof(filteredGroups))
    {
        ret = sprintf("W: %s", filteredGroups[0]->group());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasOwnershipAccess(string path)
{
    PathToCheck = path;
    return sizeof(filter(groupObjects(),
        (: return $1->hasOwnershipAccess(this_object(), PathToCheck); :)));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasExecuteAccess(string command)
{
    PathToCheck = command;
    return sizeof(filter(groupObjects(),
        (: return $1->hasExecuteAccess(this_object(), PathToCheck); :)));
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string pwd(string newDirectory)
{
    if (newDirectory && hasReadAccess(newDirectory) &&
        (file_size(newDirectory) == -2))
    {
        workingDirectory = newDirectory;
    }
    else if (!workingDirectory)
    {
        workingDirectory = sprintf("/players/%s",
            lower_case(this_object()->RealName()));
    }
    return workingDirectory;
}