//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aegis of the Ancients");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the aegis of the ancients, a "
        "protective technique dating back to the "
        "first elven kingdoms. It channels the "
        "accumulated wisdom of countless generations "
        "into a layered defense that adapts to each "
        "new threat as it is encountered.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "elven-ward-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist magical", 6);
}
