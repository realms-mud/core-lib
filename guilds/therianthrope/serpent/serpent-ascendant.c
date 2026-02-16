//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serpent Ascendant");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You have ascended beyond mere "
        "therianthropic transformation. Your serpent form is a force of "
        "primal nature itself, moving with impossible speed and striking "
        "with the fury of the ancient wyrms.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 61
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/eternal-serpent.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 175);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus defense", 6);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 30,
        "Constrict": 30,
        "Spit Venom": 30,
        "Death Roll": 30,
        "Miasma": 30
    ]));
}
