//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Depths");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "eternal protection of the ocean depths. The caster's spirit becomes "
        "as unfathomable as the deepest trenches.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 41 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/primordial-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 40);
    addSpecification("bonus spell points", 25);
    addSpecification("bonus resist magical", 8);

    addSpecification("affected research", ([
        "Shell of the Deep": 25,
        "Ilyryth's Aegis": 25,
        "Tsunami Shield": 25,
        "Ilyryth's Sanctuary": 20
    ]));
    addSpecification("affected research type", "percentage");
}
