//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Longevity");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the regenerative benefits of elven "
        "longevity. The near-immortal lifespan of "
        "elves is not merely a matter of time but "
        "of constant renewal. The battlemage learns "
        "to harness this innate vitality to recover "
        "from wounds with remarkable speed.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "ancient-fortitude.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 8);
    addSpecification("bonus heal spell points rate", 5);
}
