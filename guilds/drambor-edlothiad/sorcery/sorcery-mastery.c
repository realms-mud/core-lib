//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sorcery Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with true mastery of elven sorcery. "
        "Spells that once required intense focus "
        "now flow as naturally as speech, and the "
        "battlemage can weave complex enchantments "
        "while simultaneously maintaining flawless "
        "combat awareness.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "eternal-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus spell points", 30);
}
