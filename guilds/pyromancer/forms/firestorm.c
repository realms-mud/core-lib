//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Firestorm Form");
    addSpecification("source", "pyromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form devastating firestorms.");

    addPrerequisite("/guilds/pyromancer/forms/inferno.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "pyromancer",
            "value": 23
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 50,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 24);
    addSpecification("additional spell point cost", 48);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::summon## a firestorm of ##Function##.");
}
