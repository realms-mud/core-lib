//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Undying Spirit");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research grants an undying spirit "
        "that defies destruction.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/immortal-constitution.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 100);
    addSpecification("bonus defense", 5);
    addSpecification("bonus constitution", 3);
}
