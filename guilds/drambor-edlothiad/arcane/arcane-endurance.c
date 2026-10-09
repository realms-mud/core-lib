//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Endurance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of arcane endurance "
        "techniques. Through the sustained channeling "
        "of low-level restorative magic into one's "
        "own body, the battlemage greatly enhances "
        "physical stamina and resilience, allowing "
        "prolonged combat without fatigue.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "arcane-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus stamina points", 30);
    addSpecification("bonus hit points", 30);
}
