//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Daedrun's Lament");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "Let the ice descend on the weak and the broken...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of Daedrun's Lament, a lyrical style of potent magic "
        "that crushes a foe's defenses.");

    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 7
        ]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "bard",
          "value": 7 ]));

    addPrerequisite("/guilds/bard/lyrics/demoralizing-lyric.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-might.c",
            "name": "Daedrun's Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-sorrow.c",
            "name": "Daedrun's Sorrow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-regret.c",
            "name": "Daedrun's Regret",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-despair.c",
            "name": "Daedrun's Despair",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/compositions/abac.c",
            "name": "ABAC",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1
        ]),
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "dancing",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type":"attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ]), 
    }));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 40);

    addSpecification("penalty to defense", 1);
    addSpecification("penalty to resist acid", 2);
    addSpecification("penalty to resist air", 2);
    addSpecification("penalty to resist chaos", 2);
    addSpecification("penalty to resist cold", 2);
    addSpecification("penalty to resist disease", 2);
    addSpecification("penalty to resist earth", 2);
    addSpecification("penalty to resist electricity", 2);
    addSpecification("penalty to resist energy", 2);
    addSpecification("penalty to resist evil", 2);
    addSpecification("penalty to resist fire", 2);
    addSpecification("penalty to resist good", 2);
    addSpecification("penalty to resist magical", 2);
    addSpecification("penalty to resist neutral", 2);
    addSpecification("penalty to resist paralysis", 2);
    addSpecification("penalty to resist physical", 2);
    addSpecification("penalty to resist poison", 2);
    addSpecification("penalty to resist psionic", 2);
    addSpecification("penalty to resist sonic", 2);
    addSpecification("penalty to resist undead", 2);
    addSpecification("penalty to resist water", 2);

    addSpecification("duration", 20);

    addSpecification("event handler", "daedrunsLyricEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::intone##, '##CompositeSegment##'");
}
