//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Battle Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents legendary "
        "mastery  of battle magic, known only to the greatest battlemages.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/elven-devastation.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 15);
    addSpecification("bonus magical essence", 12);
    addSpecification("bonus spell points", 100);
}
