//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ophidian Swiftness");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your serpent form moves with "
        "supernatural speed, your strikes becoming a blur of fangs and "
        "coils.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 35
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/world-serpent.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 2);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Fanged Bite": 1,
        "Constrict": 1,
        "Death Roll": 2,
        "Spit Venom": 2,
        "Miasma": 3
    ]));
}