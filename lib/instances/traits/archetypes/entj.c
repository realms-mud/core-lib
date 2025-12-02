//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Commander");
    addSpecification("description", "Strategic, assertive, and confident, "
        "the Commander is a natural leader who excels at organizing people "
        "and resources to achieve ambitious goals. They are decisive and "
        "logical, often inspiring others with their vision and determination. "
        "Commanders thrive in challenging situations and are driven to turn "
        "ideas into reality.");
    addSpecification("root", "archetype");
}
