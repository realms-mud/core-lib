//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Storm Conduit");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage "
        "to channel and conduct electrical storms through a wielded blade, "
        "becoming a living conduit for lightning.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/shock-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "two-handed sword", "short sword",
        "dagger" }) ]));

    addSpecification("bonus electricity attack", 8);
    addSpecification("bonus electricity enchantment", 6);
}
