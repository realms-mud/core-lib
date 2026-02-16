//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Venom Potency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your connection to the serpent spirit "
        "deepens, intensifying the venom coursing through your fangs.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 13
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/fanged-bite.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus attack", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 15,
        "Constrict": 10,
        "Spit Venom": 15,
        "Death Roll": 10,
        "Miasma": 10
    ]));
}
