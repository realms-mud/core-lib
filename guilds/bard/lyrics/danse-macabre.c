//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        summoningResearchItem::reset(arg);
        addSpecification("name", "Danse Macabre");
        addSpecification("source", "bard");
        addSpecification("composite research",
            "guilds/bard/compositions/root.c");
        addSpecification("composite type", "chorus lyric");
        addSpecification("default composite description", 
            "In skull forest, life has fled. Now I come to summon the dead.");

        addSpecification("description", "This skill provides the user with the "
            "knowledge of a skeleton-summoning chant.");

        addPrerequisite("level",
            (["type":"level",
                "guild": "bard",
                "value": 23
            ]));
        addPrerequisite("guilds/bard/lyrics/root.c",
            (["type":"research"]));

        addSpecification("number to summon", 2);
        addSpecification("persona level", 20);
        addSpecification("persona", "skeleton");

        addSpecification("modifiers", ([
            "guilds/bard/lyrics/boneflower.c":({
                (["modifier": "bonus attack",
                   "value": 25]),
                (["modifier": "bonus damage",
                   "value": 10]),
                (["modifier":"bonus hit points",
                   "value" : 350]),
            }),
            "guilds/bard/lyrics/ballad-of-the-bones.c":({
                (["modifier": "bonus resist acid",
                   "value": 10 ]),
                (["modifier": "bonus resist air",
                   "value": 10 ]),
                (["modifier": "bonus resist chaos",
                   "value": 10 ]),
                (["modifier": "bonus resist cold",
                   "value": 10 ]),
                (["modifier": "bonus resist earth",
                   "value": 10 ]),
                (["modifier": "bonus resist electricity",
                   "value": 10 ]),
                (["modifier": "bonus resist energy",
                   "value": 10 ]),
                (["modifier": "bonus resist fire",
                   "value": 10 ]),
                (["modifier": "bonus resist magical",
                   "value": 10 ]),
                (["modifier": "bonus resist physical",
                   "value": 10 ]),
                (["modifier": "bonus resist psionic",
                   "value": 10 ]),
                (["modifier": "bonus resist sonic",
                   "value": 10 ]),
                (["modifier": "bonus resist water",
                   "value": 10 ]),
                (["modifier":"bonus hit points",
                   "value" : 150]),
            }),
        ]));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addSpecification("spell point cost", 75);
        addSpecification("stamina point cost", 75);

        addSpecification("event handler", "danseMacabreEvent");
        addSpecification("use composite message", "##InitiatorName## "
            "darkly ##Infinitive::chant## `##CompositeSegment##'");
    }
}
