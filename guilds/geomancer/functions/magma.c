//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Magma Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with molten rock "
        "drawn from deep beneath the earth.");

    addPrerequisite("/guilds/geomancer/functions/sand.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "fire");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 90,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 24);
    addSpecification("additional spell point cost", 45);

    addSpecification("combination descriptor", "molten magma");
}
