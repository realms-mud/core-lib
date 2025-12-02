//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Keen Observation");
    addSpecification("source", "background");
    addSpecification("description",
        "Your sharp eyes and attention to detail let you spot things others miss.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus spot", 1);
    addSpecification("bonus wisdom", 1);
}
