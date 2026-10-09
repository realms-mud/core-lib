//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Flow");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "maintain a steady flow of mana during combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/focused-channeling.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 20);
    addSpecification("bonus magical essence", 3);
}
