//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frozen Wasteland");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of endless frozen wasteland - "
        "the bitter cold seeping into bones, frost creeping across skin, the "
        "certainty of freezing to death alone. The horror manifests as "
        "intense cold damage. It can be used alone or as part of a "
        "combination attack.");
    addSpecification("usage summary", "Nightmare imagery of freezing that "
        "adds cold damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/drowning-depths.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 47
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 95,
            "range": 190
        ]),
        ([
            "probability": 20,
            "base damage": 190,
            "range": 380
        ])
    }));

    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 80);
    addSpecification("cooldown", 20);

    addSpecification("event handler", "frozenWastelandEvent");
    addSpecification("command template", "frozen wasteland [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::strand## ##TargetName## in the nightmare of a frozen "
        "wasteland, phantom ice seeping into ##TargetPossessive## very soul.");
    addSpecification("use combination message", "##Infinitive::freeze## "
        "in nightmare cold");
}
