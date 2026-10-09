//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Fury");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches "
        "the Arcane Fury combat stance, enhancing martial capability through "
            "arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/lightning-reflexes.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 110);
    addSpecification("stamina point cost", 55);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 14);
    addSpecification("bonus damage", 8);

    addSpecification("command template", "arcane fury");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## the Arcane Fury stance, arcane energy surging "
            "through every movement.");
    addSpecification(
        "use ability deactivate message",
        "The Arcane Fury stance fades.");
}
