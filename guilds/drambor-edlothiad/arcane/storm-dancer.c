//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Storm Dancer");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches "
        "the Storm Dancer combat stance, enhancing martial capability "
            "through arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/arcane-fury.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 140);
    addSpecification("stamina point cost", 70);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 18);
    addSpecification("bonus dodge", 12);

    addSpecification("command template", "storm dancer");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## the Storm Dancer stance, arcane energy "
            "surging through every movement.");
    addSpecification(
        "use ability deactivate message",
        "The Storm Dancer stance fades.");
}
