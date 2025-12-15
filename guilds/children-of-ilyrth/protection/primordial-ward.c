//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "protection from the primordial waters of creation. The caster "
        "taps into the most ancient power of the sea.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/tidal-fortification.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 35);
    addSpecification("bonus resist magical", 6);
    addSpecification("bonus damage reflection", 3);

    addSpecification("affected research", ([
        "Shell of the Deep": 25,
        "Ilyryth's Aegis": 25,
        "Sanctuary of Waves": 25,
        "Tsunami Shield": 20
    ]));
    addSpecification("affected research type", "percentage");
}
