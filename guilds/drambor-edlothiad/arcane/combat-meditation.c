//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Combat Meditation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of combat meditation "
        "techniques. By maintaining a deep meditative "
        "focus even in the chaos of battle, the "
        "battlemage can simultaneously channel arcane "
        "power while deflecting incoming blows with "
        "preternatural calm.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/combat-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus spell points", 20);
}
