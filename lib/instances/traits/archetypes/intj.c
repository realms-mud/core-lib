//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Architect");
    addSpecification("description", "Strategic, determined, and insightful, the Architect excels at planning "
        "and executing complex visions. They are independent and decisive, often "
        "seeing patterns and possibilities that others overlook. Their focus and "
        "ingenuity enable them to turn ambitious ideas into reality, making them "
        "formidable leaders and innovators.");
    addSpecification("root", "archetype");
}
