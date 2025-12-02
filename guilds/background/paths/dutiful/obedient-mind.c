//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Obedient Mind");
    addSpecification("source", "background");
    addSpecification("description",
        "You are quick to follow instructions and adapt to structure.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus to intoxicated", 5);
    addSpecification("bonus to drugged", 5);
    addSpecification("bonus wisdom", 1);
}
