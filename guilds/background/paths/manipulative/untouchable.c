//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Untouchable");
    addSpecification("source", "background");
    addSpecification("description",
        "You are nearly impossible to outwit or manipulate.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist psionic", 5);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus wisdom", 1);
}
