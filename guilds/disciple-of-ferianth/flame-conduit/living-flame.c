//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Living Flame");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill transforms you into living "
        "flame itself while in conduit form. Your body is no longer merely "
        "wreathed in fire - it IS fire given form by Ferianth's will.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 33
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/pyroclastic-form.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus fire attack", 25);
    addSpecification("bonus elemental fire", 4);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus resist fire", 3);
    addSpecification("penalty to resist water", 2);
}