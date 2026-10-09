//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Ward Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with complete mastery of elven warding "
        "arts. The battlemage can now weave, layer, "
        "and reinforce protective wards with such "
        "speed and precision that maintaining "
        "multiple simultaneous barriers requires no "
        "more effort than breathing.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "greater-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus resist physical", 3);
}
