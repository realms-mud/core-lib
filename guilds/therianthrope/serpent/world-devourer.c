//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "World Devourer");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your serpent form reaches its ultimate "
        "potential, embodying the primordial world devourer of legend. "
        "Your coils can crush mountains, your venom can dissolve anything, "
        "and your scales are harder than any known material.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 67
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/serpent-ascendant.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 200);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus fangs attack", 30);
    addSpecification("bonus constriction attack", 30);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 35,
        "Constrict": 35,
        "Spit Venom": 35,
        "Death Roll": 35,
        "Miasma": 35
    ]));
}