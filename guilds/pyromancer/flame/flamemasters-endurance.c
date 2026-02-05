//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flamemaster's Endurance");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to further decrease the cooldown for which they can use their "
        "flame attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 33
        ]));
    addPrerequisite("/guilds/pyromancer/flame/flamemasters-finesse.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Scorching Mist": 10,
        "Blazing Wave": 10,
        "Flame Discharge": 10,
        "Firestorm": 10,
        "Flame Bolt": 10,
        "Flame Whip": 10,
        "Raging Inferno": 10,
        "Blazing Swarm": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
