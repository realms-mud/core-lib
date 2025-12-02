//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battlefield Command");
    addSpecification("source", "background");
    addSpecification("description",
        "You can direct allies and adapt tactics in the heat of battle.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus defense class", 1);
}
