//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilryth's Final Judgment");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of Ilryth's final judgment spell. The caster invokes the "
        "goddess's ultimate authority, pronouncing divine judgment upon all "
        "enemies as waves of holy radiance crash upon them repeatedly, "
        "executing that sentence with absolute finality.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 67 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/apocalyptic-tide.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 375);
    addSpecification("repeat effect", 4);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 200,
            "range": 200
        ]),
        ([
            "probability": 15,
            "base damage": 225,
            "range": 400
        ]),
        ([
            "probability": 5,
            "base damage": 250,
            "range": 600
        ])
    }));
    addSpecification("damage type", "good");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/holy-deluge.c",
            "name": "Holy Deluge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/sacred-flood.c",
            "name": "Sacred Flood",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/divine-retribution.c",
            "name": "Divine Retribution",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/divine-inundation.c",
            "name": "Divine Inundation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/offense/apocalyptic-tide.c",
            "name": "Apocalyptic Tide",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.025
        ])
    }));

    addSpecification("cooldown", 150);
    addSpecification("event handler", "ilrythsFinalJudgmentEvent");
    addSpecification("command template", "ilryth's final judgment");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## voice in solemn "
        "invocation as Ilyrth herself passes judgment. A pillar of "
        "blinding radiance descends from the heavens, carrying with it "
        "the crushing weight of the entire ocean.");
}
