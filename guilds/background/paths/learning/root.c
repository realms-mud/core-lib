//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Learning");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from a classical education.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus local history", 1);
    addSpecification("bonus astronomy", 1);
    addSpecification("bonus chemistry", 1);
    addSpecification("bonus geology", 1);
    addSpecification("bonus mathematics", 1);
    addSpecification("bonus linguistics", 1);
    addSpecification("bonus philosophy", 1);
    addSpecification("bonus physics", 1);
    addSpecification("bonus reading", 1);
    addSpecification("bonus writing", 1);
}
