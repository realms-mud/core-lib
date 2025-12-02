//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Attentive Listener");
    addSpecification("source", "background");
    addSpecification("description",
        "You pay close attention to others, rarely missing important details.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus listen", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus wisdom", 1);

    addPrerequisite("/guilds/background/paths/dutiful/steady-hand.c",
        (["type":"research"]));
}
