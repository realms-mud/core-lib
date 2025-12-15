//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oceans Wisdom");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of the ocean's timeless wisdom. Ilyrth's followers learn "
        "to perceive the world through the goddess's eyes, gaining insight "
        "into the hidden truths that lie beneath the surface.");

    addSpecification("research type", "tree root");
    addSpecification("research cost", 1);
}
