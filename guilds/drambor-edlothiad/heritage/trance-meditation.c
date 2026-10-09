//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Trance Meditation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the elven "
        "trance, restoring body and mind.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/elven-vitality.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points", 5);
    addSpecification("bonus heal spell points", 5);
}
