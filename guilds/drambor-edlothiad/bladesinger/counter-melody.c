//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Counter Melody");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the bladesinger "
        "to weave a counter melody into their bladesong, a defensive harmony "
        "that disrupts and negates incoming attacks.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/harmonic-flow.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus damage reflection", 3);
}
