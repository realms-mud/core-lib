//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shield of Ages");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research grants the battlemage "
        "knowledge of an ancient protective ward, a shield of ages that has "
        "endured through countless battles.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/mystic-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 8);
    addSpecification("bonus resist magical", 6);
    addSpecification("bonus damage reflection", 5);
}
