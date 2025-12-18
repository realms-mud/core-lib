//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Flame");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill transforms you into a true "
        "avatar of divine flame while in conduit form. You embody Ferianth's "
        "sacred fire in mortal form.");

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

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/eternal-ember.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 5);
    addSpecification("bonus spellcraft", 4);
    addSpecification("bonus resist fire", 5);
    addSpecification("penalty to resist water", 3);
    addSpecification("penalty to resist cold", 3);
}
