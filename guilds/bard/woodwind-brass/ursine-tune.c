//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Ursine Tune");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental solo");
    addSpecification("composite class", "woodwind");
    addSpecification("default composite description",
        "Dm7 arpeggio");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a great-bear-summoning arpeggio that can be played with "
        "woodwind and brass instruments.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 31
    ]));

    addPrerequisite("guilds/bard/woodwind-brass/root.c",
        (["type":"research"]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: woodwind", "instrument: brass" }),
        "environment": ({ "forest", "hilly forest", "mountainous forest",
            "rural", "hilly rural", "forest village", "riverside forest",
            "rocky lakeside forest", "sandy lakeside forest",
            "elvish forest" })
    ]));

    addSpecification("number to summon", 1);
    addSpecification("maximum that can be summoned", 2);
    addSpecification("persona", "brown bear");

    addSpecification("modifiers", ([
        "guilds/bard/woodwind-brass/creatures-of-might.c":({
            (["modifier": "bonus strength",
               "value": 4 ]),
            (["modifier": "bonus dexterity",
               "value": 4 ]),
            (["modifier": "bonus attack",
               "value": 10 ]),
            (["modifier": "bonus damage",
               "value": 6 ]),
            (["modifier":"bonus hit points",
               "value" : 250]),
        }),
        "guilds/bard/woodwind-brass/denizens-dance.c":({
            (["modifier": "bonus attack",
               "value": 20 ]),
            (["modifier": "bonus damage",
               "value": 10 ]),
            (["modifier":"bonus defense",
               "value": 10 ]),
            (["modifier":"bonus hit points",
               "value" : 400]),
        }),
        "guilds/bard/woodwind-brass/bears-dance.c":({
            (["modifier": "bonus heal hit points",
               "value": 10 ]),
            (["modifier":"bonus heal spell points",
               "value": 10 ]),
            (["modifier": "bonus heal hit points rate",
               "value": 5 ]),
            (["modifier":"bonus heal spell points rate",
               "value": 5 ]),
        }),
        "guilds/bard/woodwind-brass/dexterous-denizens.c":({
            (["modifier": "bonus dexterity",
               "value": 6 ]),
            (["modifier":"bonus dodge",
               "value": 10 ]),
            (["modifier":"bonus no armor",
               "value": 10 ]),
        }),
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 75);
    addSpecification("stamina point cost", 50);

    addSpecification("event handler", "creaturesOfTheForestEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::play## a ##CompositeSegment## on "
        "##InitiatorPossessive## ##InitiatorWeapon##.");
}
