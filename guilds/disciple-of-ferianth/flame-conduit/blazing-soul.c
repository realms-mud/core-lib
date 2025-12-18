//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Soul");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill ignites your very soul with "
        "Ferianth's divine fire. While in conduit form, your magical prowess "
        "is enhanced.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 17
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/burning-aura.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 3);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus damage", 1);
}
