//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        persistedActiveResearchItem::reset(arg);
        addSpecification("name", "Counterspell Knell");
        addSpecification("source", "bard");
        addSpecification("composite research",
            "guilds/bard/compositions/root.c");
        addSpecification("composite type", "instrumental rhythm");
        addSpecification("composite class", "percussion");
        addSpecification("default composite description",
            "syncopated low 4/4 groove");

        addSpecification("description", "This skill provides the user with the "
            "knowledge of creating basic percussive elements for songs. These "
            "provide a boost to all allies' defense against non-physical damage.");

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "bard",
            "value": 17
        ]));

        addSpecification("limited by", ([
            "equipment":({ "instrument: percussion" }),
        ]));

        addPrerequisite("guilds/bard/percussion/fell-beat.c",
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/bard/percussion/beat-of-baxeros.c",
                "name": "beat-of-baxeros",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.5
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/percussion/baxteros-meter.c",
                "name": "baxteros-meter",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/percussion/duotime-drive.c",
                "name": "duotime-drive",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/percussion/percussion-mastery.c",
                "name": "percussion-mastery",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/compositions/verse-chorus-bridge.c",
                "name": "verse-chorus-bridge",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.1
            ]),
            ([
                "type": "skill",
                "name": "instrument: percussion",
                "formula": "additive",
                "rate": 0.10
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
            ([
                "type":"attribute",
                "name": "dexterity",
                "formula": "additive",
                "rate": 0.05
            ]), 
        }));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addSpecification("spell point cost", 50);

        addSpecification("bonus resist acid", 50);
        addSpecification("bonus resist air", 50);
        addSpecification("bonus resist chaos", 50);
        addSpecification("bonus resist cold", 50);
        addSpecification("bonus resist disease", 50);
        addSpecification("bonus resist earth", 50);
        addSpecification("bonus resist electricity", 50);
        addSpecification("bonus resist energy", 50);
        addSpecification("bonus resist evil", 50);
        addSpecification("bonus resist fire", 50);
        addSpecification("bonus resist good", 50);
        addSpecification("bonus resist magical", 50);
        addSpecification("bonus resist neutral", 50);
        addSpecification("bonus resist paralysis", 50);
        addSpecification("bonus resist physical", 50);
        addSpecification("bonus resist poison", 50);
        addSpecification("bonus resist psionic", 50);
        addSpecification("bonus resist sonic", 50);
        addSpecification("bonus resist undead", 50);
        addSpecification("bonus resist water", 50);

        addSpecification("duration", 6);

        addSpecification("event handler", "counterspellKnellEvent");
        addSpecification("use composite message", "##InitiatorName## "
            "rhythmically ##Infinitive::beat## ##InitiatorPossessive## "
            "##InitiatorWeapon## in a ##CompositeSegment##.");    
    }
}
