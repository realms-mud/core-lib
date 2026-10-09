//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immortal Heritage");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the full awakening of their "
        "immortal heritage. The elven body was "
        "never meant to age or fail, and through "
        "this research the battlemage reclaims "
        "that birthright, achieving a state of "
        "perpetual vitality that defies entropy.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "transcendent-grace.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 57
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus hit points", 50);
    addSpecification("bonus heal hit points rate", 5);
}
