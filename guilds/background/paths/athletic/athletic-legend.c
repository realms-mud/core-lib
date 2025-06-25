//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Athletic Legend");
    addSpecification("source", "background");
    addSpecification("description",
        "Your athletic prowess is the stuff of legend, inspiring awe in all "
        "who witness your feats.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus hit points", 5);

    addPrerequisite("/guilds/background/paths/athletic/unstoppable-force.c",
        (["type":"research"]));
}
