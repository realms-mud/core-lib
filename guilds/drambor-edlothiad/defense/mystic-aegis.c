//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Aegis");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of the mystic aegis "
        "technique. This ancient defensive art creates "
        "an invisible lattice of protective energy "
        "that surrounds the battlemage at all times, "
        "deflecting minor attacks and weakening "
        "major ones before they connect.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "arcane-shield-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus resist physical", 5);
}
