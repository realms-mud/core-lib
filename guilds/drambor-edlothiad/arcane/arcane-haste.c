//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Haste");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches "
        "the Arcane Haste combat stance, enhancing martial capability "
            "through arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/arcane-speed.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 4);
    addSpecification("bonus dodge", 3);

    addSpecification("command template", "arcane haste");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## the Arcane Haste stance, arcane energy "
            "surging through every movement.");
    addSpecification(
        "use ability deactivate message",
        "The Arcane Haste stance fades.");
}
