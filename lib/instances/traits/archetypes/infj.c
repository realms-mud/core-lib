//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Advocate");
    addSpecification("description", "Compassionate, insightful, and driven "
        "by a strong sense of duty, the Advocate is a natural leader who "
        "seeks to inspire and protect others. They are empathetic and "
        "diplomatic, often serving as a guiding force in their community. "
        "Their intuition and idealism are matched by a practical approach "
        "to helping those in need.");
    addSpecification("root", "archetype");
}
