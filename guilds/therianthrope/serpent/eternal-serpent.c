//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Serpent");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The physical and venomous paths of the "
        "serpent merge into one unified, eternal form. You are an avatar of "
        "ophidian destruction, wielding both crushing coils and lethal toxins "
        "with unmatched mastery.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 55
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/jormungandr.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 35,
        "Constrict": 35,
        "Spit Venom": 35,
        "Death Roll": 35,
        "Miasma": 35
    ]));
}
