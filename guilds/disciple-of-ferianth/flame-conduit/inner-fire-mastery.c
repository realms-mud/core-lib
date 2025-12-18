//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inner Fire Mastery");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides deeper understanding "
        "of channeling Ferianth's sacred fire through your transformed body, "
        "enhancing the power of your flame conduit abilities.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/flame-burst.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    // Enhances form-only active abilities
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Flame Burst": 10,
        "Immolating Grasp": 10,
        "Blazing Teleport": 10,
        "Inferno Nova": 10,
        "Phoenix Rebirth": 5
    ]));
}
