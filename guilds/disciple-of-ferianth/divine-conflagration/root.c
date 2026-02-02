//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Summon Flame Guardian");
    addSpecification("source", "disciple of ferianth");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of summoning a flame guardian - a divine servant of "
        "Ferianth formed of sacred fire. The guardian fights alongside "
        "its summoner and can be enhanced through further research.");

    addSpecification("number to summon", 1);
    addSpecification("maximum that can be summoned", 1);
    addSpecification("persona", "flame guardian");

    addSpecification("modifiers", ([
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-i.c":({
            (["modifier": "bonus hit points",
               "value": 100 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-ii.c":({
            (["modifier": "bonus hit points",
               "value": 150 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fortitude-iii.c":({
            (["modifier": "bonus hit points",
               "value": 200 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-i.c":({
            (["modifier": "bonus defense",
               "value": 5 ]),
            (["modifier": "bonus soak",
               "value": 2 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-ii.c":({
            (["modifier": "bonus defense",
               "value": 8 ]),
            (["modifier": "bonus soak",
               "value": 3 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-defense-iii.c":({
            (["modifier": "bonus defense",
               "value": 10 ]),
            (["modifier": "bonus soak",
               "value": 4 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-i.c":({
            (["modifier": "bonus attack",
               "value": 5 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-ii.c":({
            (["modifier": "bonus attack",
               "value": 8 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-iii.c":({
            (["modifier": "bonus attack",
               "value": 10 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-i.c":({
            (["modifier": "bonus damage",
               "value": 3 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-ii.c":({
            (["modifier": "bonus damage",
               "value": 5 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-damage-iii.c":({
            (["modifier": "bonus damage",
               "value": 7 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-i.c":({
            (["modifier": "bonus fire attack",
               "value": 10 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-ii.c":({
            (["modifier": "bonus fire attack",
               "value": 15 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/guardian-fire-iii.c":({
            (["modifier": "bonus fire attack",
               "value": 20 ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/searing-strikes.c":({
            (["modifier": "apply research",
               "value": "/guilds/disciple-of-ferianth/divine-conflagration/searing-strikes-spell.c" ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/blazing-wrath.c":({
            (["modifier": "apply research",
               "value": "/guilds/disciple-of-ferianth/divine-conflagration/blazing-wrath-spell.c" ]),
        }),
        "/guilds/disciple-of-ferianth/divine-conflagration/divine-immolation.c":({
            (["modifier": "apply research",
               "value": "/guilds/disciple-of-ferianth/divine-conflagration/divine-immolation-spell.c" ]),
        }),
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");

    addSpecification("spell point cost", 150);
    addSpecification("stamina point cost", 75);
    addSpecification("cooldown", 300);

    addSpecification("event handler", "summonFlameGuardianEvent");
    addSpecification("command template", "summon flame guardian");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon Ferianth's power. Sacred flames erupt "
        "from the ground and coalesce into a blazing guardian.");
}
