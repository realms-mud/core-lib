//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enlightened Mind");
    addSpecification("source", "background");
    addSpecification("description", "Your spiritual practice has sharpened "
        "your mental faculties and deepened your understanding.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus wisdom", 1);

    addPrerequisite("/guilds/background/paths/devoted/meditative-focus.c",
        (["type":"research"]));
}
