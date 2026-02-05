//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno Form");
    addSpecification("source", "pyromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form infernos of fire.");

    addPrerequisite("/guilds/pyromancer/forms/vortex.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "pyromancer",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 42,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 20);
    addSpecification("additional spell point cost", 40);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::engulf## ##TargetName## in an inferno of ##Function##.");
}
