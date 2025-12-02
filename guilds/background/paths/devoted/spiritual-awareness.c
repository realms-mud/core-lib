//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spiritual Awareness");
    addSpecification("source", "background");
    addSpecification("description", "You are attuned to the spiritual forces "
        "that others cannot perceive.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus philosophy", 1);
}
