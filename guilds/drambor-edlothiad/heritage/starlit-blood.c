//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Starlit Blood");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with an awakening of the starlit blood "
        "that flows through elven veins. This ancient "
        "vitality, said to be a gift from the first "
        "stars, suffuses the battlemage with radiant "
        "energy that enhances both magical capacity "
        "and physical endurance.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "elven-poise.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 30);
    addSpecification("bonus hit points", 20);
}
