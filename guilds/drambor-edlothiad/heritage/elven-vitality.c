//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Vitality");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research unlocks the natural "
        "vitality of the elven bloodline.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 25);
    addSpecification("bonus constitution", 1);
}
