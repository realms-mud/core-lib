//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind of the Ancients");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research connects to the vast "
        "intellect of the ancient elves.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/lorekeepers-mind.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus spell points", 50);
}
