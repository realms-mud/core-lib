//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Lineage");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research embodies the eternal "
        "lineage of the elven people.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/firstborn-legacy.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 67
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 3);
    addSpecification("bonus dexterity", 3);
    addSpecification("bonus constitution", 3);
    addSpecification("bonus intelligence", 3);
}
