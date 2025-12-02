//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Patient Study");
    addSpecification("source", "background");
    addSpecification("description",
        "You are methodical and thorough in your approach to learning.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus perception", 1);
}
