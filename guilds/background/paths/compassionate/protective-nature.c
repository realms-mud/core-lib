//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Protective Nature");
    addSpecification("source", "background");
    addSpecification("description", "You move into a protective stance, "
        "positioning yourself to better shield your allies from harm.");

    addPrerequisite("/guilds/background/paths/compassionate/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 8);
    addSpecification("stamina point cost", 10);

    addSpecification("bonus defense", 5);
    addSpecification("bonus parry", 5);
    addSpecification("penalty to attack", 5);
    addSpecification("duration", 10);

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ])
    }));

    addSpecification("event handler", "protectiveNatureEvent");
    addSpecification("command template", "protective nature");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::move## into a protective stance.");
}
