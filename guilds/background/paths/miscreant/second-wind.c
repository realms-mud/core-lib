//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Second Wind");
    addSpecification("source", "background");
    addSpecification("description",
        "You recover from exhaustion and injury more quickly than most.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus constitution", 1);
}
