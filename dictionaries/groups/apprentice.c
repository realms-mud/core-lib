//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
	setName("Apprentice Wizard");
	addPermission("/", Read);
	addPermission("/secure/player", None);
	addPermission("/secure/player/files/some", Read);
	addPermission("/players/$ANY/closed", None);
	addPermission("/players/$USER", Read | Write | Owner);
	addPermission("/open", Read | Write);
}