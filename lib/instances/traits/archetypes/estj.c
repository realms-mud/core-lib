//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Overseer");
    addSpecification("description", "Decisive, organized, and dependable, the Overseer values order and tradition. "
        "They are skilled at managing people and resources, ensuring that tasks are completed efficiently. "
        "Their strong sense of duty and leadership inspires confidence and stability in those around them.");
    addSpecification("root", "archetype");
}
