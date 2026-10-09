//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Battle Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents supreme mastery "
        " of battle magic.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/overwhelming-force.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 10);
    addSpecification("bonus magical essence", 8);
    addSpecification("bonus spell points", 75);
}
