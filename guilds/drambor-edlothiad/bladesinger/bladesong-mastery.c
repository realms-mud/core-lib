//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bladesong Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with true mastery of the bladesong "
        "art. Having internalized every rhythm and "
        "melody of the ancient tradition, the "
        "bladesinger no longer consciously performs "
        "the song but rather becomes it, each "
        "heartbeat a note and each breath a measure "
        "in an endless martial symphony.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/"
        "bladesinger-elven-grace.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus defense", 3);
    addSpecification("bonus parry", 3);
}
