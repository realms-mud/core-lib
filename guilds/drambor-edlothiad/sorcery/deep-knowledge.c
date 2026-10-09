//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Deep Knowledge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with deep knowledge of sorcerous "
        "principles. Beyond mere spellcasting, the "
        "battlemage begins to understand the "
        "underlying architecture of magic itself, "
        "perceiving the invisible threads that "
        "connect all things in the weave.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "arcane-lore.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus spell points", 10);
}
