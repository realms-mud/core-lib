//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Meditation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with elven meditation techniques that "
        "accelerate the recovery of magical energy. "
        "Through the waking dream state unique to "
        "elves, the battlemage can replenish spent "
        "power far more rapidly than practitioners "
        "of other races.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "deep-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal spell points rate", 5);
    addSpecification("bonus spell points", 15);
}
