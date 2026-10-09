//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Song");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings a haunting song of "
        "glacial cold, channelling it into a single enemy. Deals cold "
        "damage over time as the frost takes hold.");

    addPrerequisite("singing",
        (["type": "skill", "value": 5]));
    addPrerequisite("/guilds/runeskald/song-of-power/dirge-of-ruin.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sing frost song ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## a glacial lament that chills ##TargetName## to the bone.");

    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 20,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 50
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ])
    }));
}
