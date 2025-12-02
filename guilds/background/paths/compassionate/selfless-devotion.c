//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Selfless Devotion");
    addSpecification("source", "background");
    addSpecification("description", "You have learned to put others before "
        "yourself without hesitation.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus wisdom", 1);

    addPrerequisite("/guilds/background/paths/compassionate/shared-burden.c",
        (["type":"research"]));
}
