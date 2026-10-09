//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mending Hand");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mending hand spell. Channeling the restorative "
        "pan of Bilanx's scale, the priest knits flesh and soothes wounds "
        "with a measured touch of balanced energy.");

    addPrerequisite("/guilds/hand-of-bilanx/healing-and-harm/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 10,
            "range": 10
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/healing-and-harm/scales-attunement.c",
            "name": "Scales Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/healing-and-harm/duality-of-touch.c",
            "name": "Duality of Touch",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/healing-and-harm/living-scale.c",
            "name": "Living Scale",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/healing-and-harm/first-truth-perfected.c",
            "name": "First Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/healing-and-harm/unity-of-flesh-and-spirit.c",
            "name": "Unity of Flesh and Spirit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "mendingHandEvent");
    addSpecification("command template", "mending hand [at ##Target##]");
    addSpecification("use ability message", "A soft silver light flows from "
        "##InitiatorPossessive::Name## hands as ##InitiatorSubjective## "
        "##Infinitive::mend## ##TargetName##'s wounds with Bilanx's "
        "balanced grace.");
}
