//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Duty");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from a classical education and duty "
        "toward one's family.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus local history", 1);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus barter", 1);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus linguistics", 1);
    addSpecification("bonus philosophy", 1);
    addSpecification("bonus hunting", 1);
    addSpecification("bonus reading", 1);
    addSpecification("bonus writing", 1);
}
