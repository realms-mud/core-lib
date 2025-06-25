//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Armor Training");
    addSpecification("source", "background");
    addSpecification("description",
        "You are trained in the use of armor, moving efficiently while "
        "protected.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus plate armor", 1);
    addSpecification("bonus chainmail", 1);
    addSpecification("bonus defense class", 1);

    addPrerequisite("/guilds/background/paths/martial/drill-discipline.c",
        (["type":"research"]));
}
