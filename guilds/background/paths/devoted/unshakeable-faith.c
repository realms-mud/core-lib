//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unshakeable Faith");
    addSpecification("source", "background");
    addSpecification("description", "Your faith is an unbreakable shield "
        "against doubt and fear.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus hit points", 10);

    addPrerequisite("/guilds/background/paths/devoted/spiritual-fortitude.c",
        (["type":"research"]));
}
