//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cleanly Habits");
    addSpecification("source", "background");
    addSpecification("description",
        "You maintain order and cleanliness in your surroundings.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus to intoxicated", 5);
    addSpecification("bonus to drugged", 5);
    addSpecification("bonus headache", 5);
    addSpecification("bonus resist disease", 2);
}
