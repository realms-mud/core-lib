//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Analytical");
    addSpecification("source", "background");
    addSpecification("description",
        "You excel at breaking down complex problems and finding solutions.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus mathematics", 1);
}
