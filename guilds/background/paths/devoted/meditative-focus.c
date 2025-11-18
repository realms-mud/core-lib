//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Meditative Focus");
    addSpecification("source", "background");
    addSpecification("description", "You enter a brief meditative state, "
        "restoring your mental clarity and spell points.");

    addPrerequisite("/guilds/background/paths/devoted/inner-peace.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 10);

    addSpecification("increase spell points", ({
        ([
            "probability": 100,
            "base damage": 15,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/devoted/enlightened-mind.c",
            "name": "Enlightened Mind",
            "formula": "additive",
            "base value": 1,
            "rate": 5.0
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "meditativeFocusEvent");
    addSpecification("command template", "meditative focus");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::enter## a meditative state, restoring mental clarity.");
}
