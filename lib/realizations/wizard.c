//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    string ret = "";

    string colorConfiguration = colorConfiguration();
    object configuration = getDictionary("configuration");

    if (wizardLevel)
    {
        ret = configuration->decorate(sprintf("%s is a mud wizard -> ",
                capitalize(this_object()->Pronoun())),
                "roles", "wizard commands", colorConfiguration) +
            configuration->decorate(validWizardLevels[wizardLevel],
                wizardLevel, "wizard levels", colorConfiguration) + "\n";
    }
    else
    {
        ret = configuration->decorate(sprintf("%s is a Player.",
            capitalize(this_object()->Pronoun())),
            "roles", "wizard commands", colorConfiguration) + "\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validWizardLevel(string level)
{
    return member(m_indices(validWizardLevels), level) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int setWizardLevel(string level, object granter)
{
    int ret = 0;
    if (granter && validWizardLevel(level) && 
        (program_name(granter) == "/lib/realizations/wizard.c") &&
        (granter == this_player()) &&
        granter->hasExecuteAccess("promote"))
    {
        string *granterGroups = granter->groups(1) -
            ({ granter->wizardLevel() });

        int canGrantLevel = (member(granterGroups, level) > -1) &&
            interactive(granter);

        object logs = getDictionary("log");
        if (canGrantLevel)
        {
            ret = 1;
            wizardLevel = level;
            this_object()->save();
            logs->log("Promotions", sprintf("(%s) %s promoted %s to %s.\n",
                ctime(time()), granter->Name(), this_object()->Name(), level));
        }
        else
        {
            logs->log("Promotions", 
                sprintf("(%s) %s failed to promote %s to %s.\n",
                ctime(time()), granter->Name(), this_object()->Name(), level));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string *groups(int ignoreCustomGroups)
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
        case "emeritus":
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
    if (custom && sizeof(custom) && !ignoreCustomGroups)
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
        object groupObject;

        string error = catch (groupObject = load_object(groupFile));
        if (!error)
        {
            list += ({ groupObject });
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
        (: $1->hasExecuteAccess(this_object(), PathToCheck) :)));
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
