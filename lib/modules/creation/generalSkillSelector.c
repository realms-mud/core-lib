//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/skillSelectorSubmenu.c";

/////////////////////////////////////////////////////////////////////////////
protected mapping skillMenuSetup()
{
    return SkillService ? 
        SkillService->creationListForSkillType("general", User) : ([]);
}
