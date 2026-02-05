//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Combustion");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This skill provides the user with "
        "knowledge of combustion that enhances the pyromancer's flame-based "
        "abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 21
        ]));

    addPrerequisite("/guilds/pyromancer/flame/pyrostatics.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ignite": 25,
        "Scorching Mist": 25,
        "Blazing Wave": 25,
        "Flame Discharge": 25,
        "Flash Fire": 25,
        "Blazing Swarm": 25,
        "Firestorm": 25,
        "Flame Bolt": 25,
        "Flame Lash": 25,
        "Flame Shards": 25,
        "Flame Whip": 25,
        "Raging Inferno": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
