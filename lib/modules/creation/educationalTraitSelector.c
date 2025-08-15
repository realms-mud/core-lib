//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/traitSelectorSubmenu.c";

/////////////////////////////////////////////////////////////////////////////
protected mapping traitMenuSetup()
{
    return TraitService ? 
        TraitService->creationListForTraitType("educational") : ([]);
}
