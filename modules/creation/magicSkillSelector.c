//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/skillSelectorSubmenu.c";

/////////////////////////////////////////////////////////////////////////////
protected mapping skillMenuSetup()
{
    return SkillDictionary ? 
        SkillDictionary->creationListForSkillType("magic") : ([]);
}