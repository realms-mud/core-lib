//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Curious Mind");
    addSpecification("source", "background");
    addSpecification("description",
        "You are always eager to learn and explore new ideas.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus local history", 1);
    addSpecification("bonus astronomy", 1);
}
