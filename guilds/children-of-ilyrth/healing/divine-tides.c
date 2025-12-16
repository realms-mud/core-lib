//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Tides");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "the supreme knowledge of Ilyrth's divine tides. The caster has "
        "become one with the goddess's eternal ocean, their healing magic "
        "flowing with the power of the divine tides themselves.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 63 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/oceans-heart.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 8);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus elemental water", 6);
    addSpecification("bonus magical essence", 6);
    addSpecification("bonus heal hit points", 5);
    addSpecification("bonus heal spell points", 4);
    addSpecification("bonus heal hit points rate", 3);
    addSpecification("bonus spell points", 30);

    addSpecification("affected research", ([
        "Oceans Embrace": 25,
        "Tidal Salvation" : 25,
        "Ilryth's Miracle" : 35,
        "Tsunami of Life" : 25,
        "Ilryth's Embrace" : 25
    ]));
    addSpecification("affected research type", "percentage");
}
