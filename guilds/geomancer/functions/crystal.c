//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crystal Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with razor-sharp "
        "crystalline shards.");

    addPrerequisite("/guilds/geomancer/functions/stone.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 9
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "energy");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 35,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 8);
    addSpecification("additional spell point cost", 15);

    addSpecification("combination descriptor", "crystalline shards");
}
