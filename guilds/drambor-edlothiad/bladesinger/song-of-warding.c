//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Song of Warding");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the song of warding, the "
        "ultimate protective melody known to the "
        "bladesingers. This ancient song is said to "
        "have been first sung at the founding of the "
        "Drambor order, and its notes carry the "
        "weight of millennia of protective intent.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/"
        "harmonic-barrier.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 8);
    addSpecification("bonus resist physical", 8);
    addSpecification("bonus resist magical", 8);
}
