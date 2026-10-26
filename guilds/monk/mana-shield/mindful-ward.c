//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Shield");
    addSpecification("source", "monk");
    addSpecification("description",
        "A measured breath draws your inner current beyond the skin. "
        "Pale strands of chi interlace around you, turning aside the world's "
        "violence before it can disturb the stillness within.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":1
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/root.c", ([
        "type":"research"
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);

    addSpecification("command template", "mana shield");
    addSpecification("usage summary", "mana shield");

    addSpecification("bonus resist acid", 1);
    addSpecification("bonus resist air", 1);
    addSpecification("bonus resist chaos", 1);
    addSpecification("bonus resist cold", 1);
    addSpecification("bonus resist earth", 1);
    addSpecification("bonus resist electricity", 1);
    addSpecification("bonus resist energy", 1);
    addSpecification("bonus resist evil", 1);
    addSpecification("bonus resist fire", 1);
    addSpecification("bonus resist good", 1);
    addSpecification("bonus resist magical", 1);
    addSpecification("bonus resist neutral", 1);
    addSpecification("bonus resist physical", 1);
    addSpecification("bonus resist psionic", 1);
    addSpecification("bonus resist undead", 1);
    addSpecification("bonus resist water", 1);

    addSpecification("modifiers", ({
        ([
            "type":"research",
            "name":"Ward Anatomy",
            "research item":"/guilds/monk/mana-shield/ward-anatomy.c",
            "base value":2,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Recovery Cycle",
            "research item":"/guilds/monk/mana-shield/recovery-cycle.c",
            "base value":2,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":3,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Disruption Theory",
            "research item":"/guilds/monk/mana-shield/disruption-theory.c",
            "base value":4,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Lucid Refuge",
            "research item":"/guilds/monk/mana-shield/lucid-refuge.c",
            "base value":5,
            "formula":"additive",
            "rate":1.0
        ])
    }));

    addSpecification("trait", "/guilds/monk/mana-shield/ward-trait.c");

    addSpecification("use ability activate message",
        "A luminous shield of woven chi surrounds ##InitiatorName##.");
    addSpecification("use ability deactivate message",
        "The mana shield around ##InitiatorName## unravels into light.");
}
