//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heart of Cinders");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill transforms your heart into "
        "a burning core of divine cinders. While in conduit form, your "
        "inner fire sustains you.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 21
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/blazing-soul.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
    addSpecification("bonus evocation", 3);
    addSpecification("bonus heal hit points rate", 1);
}
