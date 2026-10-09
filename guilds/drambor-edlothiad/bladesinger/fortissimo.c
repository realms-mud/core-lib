//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fortissimo");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the fortissimo technique, the "
        "art of unleashing the bladesong at its "
        "fullest and most devastating volume. When "
        "the bladesinger chooses to abandon subtlety "
        "and pour all power into the song, the "
        "resulting crescendo strikes with the force "
        "of a thunderclap.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/"
        "bladesong-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 4);
}
