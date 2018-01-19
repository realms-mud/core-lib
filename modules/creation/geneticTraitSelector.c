//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/traitSelectorSubmenu.c";

/////////////////////////////////////////////////////////////////////////////
protected mapping traitMenuSetup()
{
    return TraitDictionary ? 
        TraitDictionary->creationListForTraitType("genetic") : ([]);
}