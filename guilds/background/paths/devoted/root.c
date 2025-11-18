//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Devotion");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from a life dedicated to spiritual seeking "
        "and contemplation of higher purpose.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus theology", 2);
    addSpecification("bonus philosophy", 1);
    addSpecification("bonus reading", 1);
    addSpecification("bonus perception", 1);
}
