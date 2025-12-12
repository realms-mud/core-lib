//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mist Form");
    addSpecification("source", "aquamancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that envelop a foe in a cloud of magical mist.");

    addPrerequisite("/guilds/aquamancer/forms/touch.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 3
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 12,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 5);
    addSpecification("additional spell point cost", 8);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::envelop## ##TargetName## in a swirling mist of ##Function##.");
}
