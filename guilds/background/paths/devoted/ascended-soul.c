//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ascended Soul");
    addSpecification("source", "background");
    addSpecification("description", "Your soul has touched something divine, "
        "elevating you beyond mortal limitations.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 3);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus spell points", 15);

    addPrerequisite("/guilds/background/paths/devoted/transcendent-wisdom.c",
        (["type":"research"]));
}
