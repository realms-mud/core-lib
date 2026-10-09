//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Footwork");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the precise "
        "elven footwork essential to "
        "bladesinging.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/bladesong-initiation.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus dexterity", 1);
}
