//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Peak Performance");
    addSpecification("source", "background");
    addSpecification("description",
        "You can push your body to its absolute limits, achieving feats of "
        "strength, speed, and stamina.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus stamina points", 3);
}
