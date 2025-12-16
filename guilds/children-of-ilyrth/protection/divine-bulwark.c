//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Bulwark");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "Ilryth's divine bulwark. The goddess strengthens all of the "
        "caster's protective barriers with her sacred power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 29 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/sanctuary-of-waves.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus magical essence", 4);
    addSpecification("bonus soak", 5);

    addSpecification("affected research", ([
        "Maelstrom Barrier": 25,
        "Ilyryth's Aegis": 25,
        "Sanctuary of Waves": 25,
        "Tsunami Shield": 20
    ]));
    addSpecification("affected research type", "percentage");
}
