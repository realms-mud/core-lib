//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Long Distance");
    addSpecification("source", "background");
    addSpecification("description",
        "You can run, swim, or march for long periods without tiring.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 2);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus swimming", 1);

    addPrerequisite("/guilds/background/paths/athletic/iron-grip.c",
        (["type":"research"]));
}
