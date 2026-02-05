//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cloud Form");
    addSpecification("source", "pyromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form clouds of fire.");

    addPrerequisite("/guilds/pyromancer/forms/touch.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "pyromancer",
            "value": 3
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 14,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 6);
    addSpecification("additional spell point cost", 12);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::create## a cloud of ##Function##.");
}
