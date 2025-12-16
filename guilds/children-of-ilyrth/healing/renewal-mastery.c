//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Renewal Mastery");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "mastery over the arts of renewal. The caster becomes a conduit "
        "for Ilyrth's restorative power, healing with greater efficiency.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/seas-bounty.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 5);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus magical essence", 4);
    addSpecification("bonus heal hit points", 3);
    addSpecification("bonus heal spell points", 2);
    addSpecification("bonus heal stamina", 2);

    addSpecification("affected research", ([
        "Wellspring of Life": 25,
        "Ilryth's Blessing": 25,
        "Deluge of Healing": 25,
        "Oceans Embrace": 25,
        "Tidal Salvation": 20
    ]));
    addSpecification("affected research type", "percentage");
}
