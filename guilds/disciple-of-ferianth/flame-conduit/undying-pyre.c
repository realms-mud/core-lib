//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Undying Pyre");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill transforms you into an undying "
        "pyre of sacred flame. While in conduit form, your flames never "
        "diminish.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 57
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/incandescent-soul.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus soak", 4);
    addSpecification("bonus heal hit points rate", 3);
}
