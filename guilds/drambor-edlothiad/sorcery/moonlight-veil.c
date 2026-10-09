//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Moonlight Veil");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the moonlight veil, a subtle "
        "defensive sorcery woven from starlight "
        "and shadow. This shimmering aura cloaks "
        "the battlemage in pale luminescence that "
        "confuses the aim of enemies and dulls the "
        "edge of incoming spells.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "spell-reservoir.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus resist magical", 4);
}
