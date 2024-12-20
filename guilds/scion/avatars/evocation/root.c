//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Energy Avatar");
    addSpecification("source", "Scion of Dhuras");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to summon an energy avatar.");

    addSpecification("number to summon", 1);
    addSpecification("persona", "scion of energy");

    addSpecification("modifiers", ([
        "/guilds/scion/avatars/common/evasion-i.c":({
            (["modifier": "bonus dodge",
               "value": 4 ]),
        }),
        "/guilds/scion/avatars/common/parry-i.c":({
            (["modifier": "bonus parry",
               "value": 4 ]),
        }),
        "/guilds/scion/avatars/common/defense-i.c":({
            (["modifier": "bonus defense",
               "value": 6 ]),
            (["modifier":"bonus soak",
               "value": 2 ]),
            (["modifier":"bonus no armor",
               "value": 4 ]),
        }),
        "/guilds/scion/avatars/common/spellcraft-i.c":({
            (["modifier": "bonus spellcraft",
               "value": 4 ]),
            (["modifier": "bonus evocation",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/attack-i.c":({
            (["modifier": "bonus attack",
               "value": 6 ]),
        }),
        "/guilds/scion/avatars/common/damage-i.c":({
            (["modifier": "bonus damage",
               "value": 3 ]),
        }),
        "/guilds/scion/avatars/evocation/mystic-touch.c":({
            (["modifier": "apply research",
               "value": "/guilds/scion/avatars/evocation/mystic-touch-spell.c" ]),
        }),
        "/guilds/scion/avatars/common/spellpoints-i.c":({
            (["modifier": "bonus spell points",
               "value": 100 ]),
        }),
        "/guilds/scion/avatars/common/hitpoints-i.c":({
            (["modifier": "bonus hit points",
               "value": 100 ]),
        }),
        "/guilds/scion/avatars/common/evasion-ii.c":({
            (["modifier": "bonus dodge",
               "value": 6 ]),
            (["modifier": "bonus dexterity",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/parry-ii.c":({
            (["modifier": "bonus parry",
               "value": 6 ]),
        }),
        "/guilds/scion/avatars/common/defense-ii.c":({
            (["modifier": "bonus defense",
               "value": 10 ]),
            (["modifier":"bonus soak",
               "value": 4 ]),
            (["modifier":"bonus no armor",
               "value": 6 ]),
            (["modifier": "bonus constitution",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/spellcraft-ii.c":({
            (["modifier": "bonus spellcraft",
               "value": 6 ]),
            (["modifier": "bonus evocation",
               "value": 4 ]),
            (["modifier": "bonus intelligence",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/attack-ii.c":({
            (["modifier": "bonus attack",
               "value": 8 ]),
            (["modifier": "bonus wisdom",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/damage-ii.c":({
            (["modifier": "bonus damage",
               "value": 4 ]),
            (["modifier": "bonus strength",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/spellpoints-ii.c":({
            (["modifier": "bonus spell points",
               "value": 150 ]),
        }),
        "/guilds/scion/avatars/common/hitpoints-ii.c":({
            (["modifier": "bonus hit points",
               "value": 150 ]),
        }),
        "/guilds/scion/avatars/evocation/energy-bolt.c":({
            (["modifier": "apply research",
               "value": "/guilds/scion/avatars/evocation/energy-bolt-spell.c" ]),
        }),
        "/guilds/scion/avatars/common/extra-attack.c":({
            (["modifier": "bonus evil attack",
               "value": 15 ]),
        }),
        "/guilds/scion/avatars/common/healing-rate-i.c":({
            (["modifier": "bonus heal hit points",
               "value": 10 ]),
            (["modifier":"bonus heal spell points",
               "value": 10 ]),
            (["modifier": "bonus heal hit points rate",
               "value": 5 ]),
            (["modifier":"bonus heal spell points rate",
               "value": 5 ]),
        }),
        "/guilds/scion/avatars/common/evasion-iii.c":({
            (["modifier": "bonus dodge",
               "value": 6 ]),
            (["modifier": "bonus dexterity",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/parry-iii.c":({
            (["modifier": "bonus parry",
               "value": 6 ]),
        }),
        "/guilds/scion/avatars/common/defense-iii.c":({
            (["modifier": "bonus defense",
               "value": 10 ]),
            (["modifier":"bonus soak",
               "value": 4 ]),
            (["modifier":"bonus no armor",
               "value": 6 ]),
            (["modifier": "bonus constitution",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/spellcraft-iii.c":({
            (["modifier": "bonus spellcraft",
               "value": 6 ]),
            (["modifier": "bonus evocation",
               "value": 4 ]),
            (["modifier": "bonus intelligence",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/attack-iii.c":({
            (["modifier": "bonus attack",
               "value": 8 ]),
            (["modifier": "bonus wisdom",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/damage-iii.c":({
            (["modifier": "bonus damage",
               "value": 4 ]),
            (["modifier": "bonus strength",
               "value": 2 ]),
        }),
        "/guilds/scion/avatars/common/spellpoints-iii.c":({
            (["modifier": "bonus spell points",
               "value": 250 ]),
        }),
        "/guilds/scion/avatars/common/hitpoints-iii.c":({
            (["modifier": "bonus hit points",
               "value": 250 ]),
        }),
        "/guilds/scion/avatars/evocation/kinetic-blast.c":({
            (["modifier": "apply research",
               "value": "/guilds/scion/avatars/evocation/kinetic-blast-spell.c" ]),
        }),
        "/guilds/scion/avatars/common/extra-attack-ii.c":({
            (["modifier": "bonus evil attack",
               "value": 25 ]),
        }),
        "/guilds/scion/avatars/common/healing-rate-ii.c":({
            (["modifier": "bonus heal hit points",
               "value": 10 ]),
            (["modifier":"bonus heal spell points",
               "value": 10 ]),
            (["modifier": "bonus heal hit points rate",
               "value": 5 ]),
            (["modifier":"bonus heal spell points rate",
               "value": 5 ]),
        }),
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");

    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 50);

    addSpecification("event handler", "energyAvatarEvent");
    addSpecification("command template", "energy avatar");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## "
        "##InitiatorWeapon## weapon and ##Infinitive::chant##. A ghostly, "
        "vaguely humainoid wisp of energy appears.");
}
