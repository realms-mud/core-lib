//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Innovator");
    addSpecification("source", "background");
    addSpecification("description",
        "You are creative and inventive, always seeking new solutions.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus engineering", 5);
}
