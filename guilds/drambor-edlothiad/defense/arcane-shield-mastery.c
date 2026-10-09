//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Shield Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with complete mastery over arcane "
        "shielding techniques. The battlemage can "
        "maintain multiple overlapping layers of "
        "protective magic simultaneously, each "
        "reinforcing the others to create a defense "
        "far greater than the sum of its parts.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "aegis-of-resolve.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus resist magical", 4);
}
