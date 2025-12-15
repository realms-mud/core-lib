//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oceans Heart");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "the knowledge of the ocean's heart - the very center of Ilyrth's "
        "divine power. The caster's healing magic reaches its apex, flowing "
        "with the strength of the deepest seas.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 51 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/avatar-of-restoration.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 7);
    addSpecification("bonus elemental water", 5);
    addSpecification("bonus divine essence", 5);
    addSpecification("bonus heal hit points", 5);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus spell points", 25);

    addSpecification("affected research", ([
        "Deluge of Healing": 25,
        "Oceans Embrace" : 25,
        "Tidal Salvation" : 25,
        "Ilryth's Miracle" : 25,
        "Tsunami of Life" : 20
    ]));
    addSpecification("affected research type", "percentage");
}
