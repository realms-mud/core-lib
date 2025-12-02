//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Second granted research");
    addSpecification("source", "quests");
    addSpecification("description", "This is granted research");
    addSpecification("scope", "self");
    addSpecification("research type", "granted");
    addSpecification("bonus strength", 2);
    addSpecification("bonus long sword", 5);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus weapon attack", 2);
}
