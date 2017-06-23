//*****************************************************************************
// Class: wizard
// File Name: wizard.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";

private nosave string *validWizardLevels = ({ "apprentice", "wizard",
	"creator", "high wizard", "senior", "admin", "elder", "sage",
	"arch wizard", "demi god", "god", "owner" });

private string wizardLevel;
private string *customGroups = ({});

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfWizard()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string wizardInformation()
{
    return "";    
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validWizardLevel(string level)
{
	return member(validWizardLevels, level) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWizardLevel(string level, object granter)
{
	if (granter && validWizardLevel(level))
	{
		string *granterGroups = granter->groups() -
			({ granter->wizardLevel() });

		int canGrantLevel =
			(program_name(granter) == "lib/realizations/wizard.c") &&
			(member(granterGroups, level) > -1) &&
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
private nomask string *customGroups()
{
	return customGroups + ({ "baseGroup" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *groups()
{
	string *wizardGroups = ({ });

	// Yes, these are supposed to fall through to the lower levels.
	switch (wizardLevel)
	{
		case "owner":
		case "god":
		{
			wizardGroups += ({ "god" });
		}
		case "demi god":
		{
			wizardGroups += ({ "demigod" });
		}
		case "arch wizard":
		{
			wizardGroups += ({ "archwizard" });
		}
		case "sage":
		{
			wizardGroups += ({ "sage" });
		}
		case "elder":
		{
			wizardGroups += ({ "elder" });
		}
		case "admin":
		{
			wizardGroups += ({ "admin" });
		}
		case "senior":
		{
			wizardGroups += ({ "senior" });
		}
		case "high wizard":
		{
			wizardGroups += ({ "highwizard" });
		}
		case "creator":
		{
			wizardGroups += ({ "creator" });
		}
		case "wizard":
		{
			wizardGroups += ({ "wizard" });
		}
		default:
		{
			wizardGroups += ({ "apprentice" });
		}
	}

	return wizardGroups + customGroups();
}