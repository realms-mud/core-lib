//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Firstborn Legacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research unlocks the full legacy "
        "of the Firstborn elves.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/elder-blood.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 63
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 4);
    addSpecification("bonus wisdom", 4);
    addSpecification("bonus charisma", 4);
}
