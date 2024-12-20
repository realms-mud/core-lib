//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "caffeinated");
    addSpecification("description", "You are stimulated by a large intake of caffeine.");
    addSpecification("root", "biological");
    addSpecification("duration", 60);
}
