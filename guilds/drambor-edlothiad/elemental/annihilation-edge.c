//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Annihilation Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the enchantment "
        "of a blade with the raw energy of annihilation, granting devastat- "
        "ingly enhanced cutting power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/oblivion-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "two-handed sword", "short sword",
        "dagger" }) ]));

    addSpecification("bonus damage", 12);
    addSpecification("bonus energy attack", 10);
}
