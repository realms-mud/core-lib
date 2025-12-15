//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Insight");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "first glimpse of Ilyrth's wisdom. The caster begins to perceive "
        "the world with heightened awareness, sensing the subtle currents "
        "of fate that flow through all things.");

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 2);
    addSpecification("bonus divination", 1);
}
