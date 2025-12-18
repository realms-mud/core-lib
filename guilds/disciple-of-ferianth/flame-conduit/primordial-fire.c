//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Fire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill connects you to the primordial "
        "fire that existed before creation. While in conduit form, you wield "
        "fire in its purest, most ancient form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 51
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/sun-touched.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 5);
    addSpecification("bonus destruction", 4);
    addSpecification("bonus damage", 3);
}
