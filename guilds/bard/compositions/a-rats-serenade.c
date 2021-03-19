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
        addSpecification("name", "A Rat's Serenade");
        addSpecification("source", "bard");
        addSpecification("composite research",
            "guilds/bard/compositions/root.c");
        addSpecification("composite type", "instrumental rhythm");
        addSpecification("default composite description", 
            "slightly discordant Gm7b4 arpeggio");

        addSpecification("description", "This skill provides the user with the "
            "knowledge of a rat-summoning arpeggio that can be played with "
            "woodwind and brass instruments.");

        addPrerequisite("guilds/bard/compositions/root.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ 
            "instrument: woodwind", "instrument: brass" })]));

        addSpecification("number to summon", 3);
        addSpecification("persona level", 1);
        addSpecification("persona", "rat");

        addSpecification("modifiers", ([
            "guilds/bard/compositions/rous.c":({
                (["modifier": "bonus strength",
                   "value": 3]),
                (["modifier": "bonus dexterity",
                   "value": 3]),
                (["modifier": "bonus attack",
                   "value": 5]),
                (["modifier": "bonus damage",
                   "value": 3]),
                (["modifier":"bonus hit points",
                   "value" : 100]),
            }),
            "guilds/bard/compositions/king-rodent.c":({
                (["modifier": "bonus attack",
                   "value": 10 ]),
                (["modifier": "bonus damage",
                   "value": 6 ]),
                (["modifier":"bonus defense",
                   "value" : 6]),
                (["modifier":"bonus hit points",
                   "value" : 250]),
            }),
        ]));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addSpecification("spell point cost", 15);
        addSpecification("stamina point cost", 15);

        addSpecification("event handler", "ratsSerenadeEvent");
        addSpecification("use composite message", "##InitiatorName## "
            "##Infinitive::play## a ##CompositeSegment## on "
            "##InitiatorPossessive## ##InitiatorWeapon##.");
    }
}
