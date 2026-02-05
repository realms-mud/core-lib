//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crushing Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with the crushing "
        "pressure of the deep earth, capable of pulverizing armor.");

    addPrerequisite("/guilds/geomancer/functions/entombing.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "bludgeon");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 65,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 16);
    addSpecification("additional spell point cost", 30);

    addSpecification("combination descriptor", "crushing depths");
}