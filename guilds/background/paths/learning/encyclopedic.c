//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Encyclopedic");
    addSpecification("source", "background");
    addSpecification("description",
        "You have a vast store of knowledge on a wide range of topics.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
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
