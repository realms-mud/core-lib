//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Warrior");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the secrets of the eternal warrior "
        "tradition. Through centuries of accumulated "
        "elven martial wisdom, the battlemage learns "
        "to sustain peak combat effectiveness "
        "indefinitely, drawing upon arcane reserves "
        "to replenish what exertion depletes.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "arcane-endurance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 40);
    addSpecification("bonus heal hit points rate", 5);
}
