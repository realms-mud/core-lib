//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Torrent");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the divine torrent spell. The caster unleashes a "
        "stream of sacred energy that sears evil with Ilyrth's judgment.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/holy-deluge.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 28,
            "range": 55
        ]),
        ([
            "probability": 10,
            "base damage": 55,
            "range": 110
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
            "name": "divine essence",
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

    addSpecification("cooldown", 16);
    addSpecification("event handler", "divineTorrentEvent");
    addSpecification("command template", "divine torrent [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a torrent of sacred radiance that sears "
        "##TargetName## with Ilyrth's divine judgment.");
}
