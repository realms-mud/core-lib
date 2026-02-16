//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ember Heart");
    addSpecification("source", "therianthrope");
    addSpecification("description", "A core of smoldering embers burns within "
        "your chimera form, fueling your fire attacks and bolstering your "
        "defenses.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 47
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/tri-form-fury.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus fire enchantment", 1);
    addSpecification("bonus defense", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fire Breath": 25,
        "Inferno": 25,
    ]));
}
