//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Timeless Intellect");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research grants an intellect that "
        "transcends mortal understanding.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/elder-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 3);
    addSpecification("bonus wisdom", 3);
    addSpecification("bonus spell points", 75);
}
