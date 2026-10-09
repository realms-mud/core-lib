//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Combat Focus");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches "
        "the Combat Focus combat stance, enhancing martial capability "
            "through arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/arcane-haste.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 6);
    addSpecification("bonus damage", 3);

    addSpecification("command template", "combat focus");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## the Combat Focus stance, arcane energy "
            "surging through every movement.");
    addSpecification(
        "use ability deactivate message",
        "The Combat Focus stance fades.");
}
