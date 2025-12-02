//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Vessel");
    addSpecification("source", "background");
    addSpecification("description", "You have become a vessel for higher power, "
        "allowing divine energy to flow through you.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus charisma", 2);
    addSpecification("bonus theology", 2);

    addPrerequisite("/guilds/background/paths/devoted/root.c",
        (["type":"research"]));
}
