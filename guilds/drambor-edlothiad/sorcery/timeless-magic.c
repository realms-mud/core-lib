//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Timeless Magic");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with an understanding of timeless "
        "magic, sorcery that exists outside the "
        "normal flow of time. The battlemage's "
        "spells take on an ageless quality, their "
        "effects persisting with undiminished "
        "strength indefinitely.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "eternal-wisdom.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 6);
    addSpecification("bonus spell points", 35);
}
