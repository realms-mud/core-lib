//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Restoration");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "the exalted knowledge of becoming an avatar of restoration. The "
        "caster embodies Ilyrth's healing aspect, channeling her divine "
        "power with incredible potency.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 41 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/healing-maelstrom.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 6);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus elemental water", 4);
    addSpecification("bonus magical essence", 4);
    addSpecification("bonus heal hit points", 4);
    addSpecification("bonus spell points", 20);

    addSpecification("affected research", ([
        "Ilryth's Blessing":25,
        "Deluge of Healing" : 25,
        "Oceans Embrace" : 25,
        "Tidal Salvation" : 25,
        "Ilryth's Miracle" : 20
    ]));
    addSpecification("affected research type", "percentage");
}
