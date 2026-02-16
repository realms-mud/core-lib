//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serpentine Fury");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Primal rage fuels your serpent form, "
        "increasing the ferocity and speed of your strikes while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 15
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/venom-potency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 15,
        "Constrict": 15,
        "Spit Venom": 15,
        "Death Roll": 15,
        "Miasma": 15
    ]));
}
