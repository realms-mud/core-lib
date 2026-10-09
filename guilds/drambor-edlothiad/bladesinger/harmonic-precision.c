//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harmonic Precision");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research sharpens the battlemage's "
        "ability to weave precise harmonics into bladesong, enhancing accuracy "
        "and the efficacy of defensive maneuvers.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/elven-war-dance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus parry", 5);
    addSpecification("bonus dodge", 3);
}
