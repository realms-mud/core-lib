//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gentle Touch");
    addSpecification("source", "background");
    addSpecification("description",
        "Your hands know how to comfort and heal. Through countless hours "
        "tending wounds and soothing pain, you've developed an intuitive "
        "understanding of the body's needs.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus anatomy and physiology", 2);
    addSpecification("bonus herbalism", 1);
}
