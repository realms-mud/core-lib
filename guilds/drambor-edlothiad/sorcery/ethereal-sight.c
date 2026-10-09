//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ethereal Sight");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with ethereal sight, the ability to "
        "perceive magical energies directly. The "
        "battlemage sees the world overlaid with "
        "shimmering threads of power, allowing "
        "instant recognition of enchantments, "
        "wards, and hidden magical traps.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "elven-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 4);
    addSpecification("bonus spellcraft", 3);
}
