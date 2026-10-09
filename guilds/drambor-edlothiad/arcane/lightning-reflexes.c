//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lightning Reflexes");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches "
        "the Lightning Reflexes combat stance, enhancing martial capability "
            "through arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/whirlwind-stance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);
    addSpecification("stamina point cost", 45);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 10);
    addSpecification("bonus defense", 8);

    addSpecification("command template", "lightning reflexes");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## the Lightning Reflexes stance, arcane energy "
            "surging through every movement.");
    addSpecification(
        "use ability deactivate message",
        "The Lightning Reflexes stance fades.");
}
