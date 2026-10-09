//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Whirlwind Stance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches "
        "the Whirlwind Stance combat stance, enhancing martial capability "
            "through arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/combat-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);
    addSpecification("stamina point cost", 35);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 8);
    addSpecification("bonus dodge", 6);

    addSpecification("command template", "whirlwind stance");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## the Whirlwind Stance stance, arcane energy "
            "surging through every movement.");
    addSpecification(
        "use ability deactivate message",
        "The Whirlwind Stance stance fades.");
}
