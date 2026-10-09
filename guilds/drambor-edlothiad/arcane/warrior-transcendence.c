//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Warrior Transcendence");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with an understanding of warrior "
        "transcendence. At this stage of mastery, the "
        "division between martial and magical arts "
        "ceases to exist. The battlemage perceives "
        "combat as a single unified discipline where "
        "blade, body, and sorcery are indivisible.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "spell-infused-strikes.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 49
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus spellcraft", 4);
    addSpecification("bonus defense", 3);
}
