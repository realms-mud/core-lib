//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Dreamer");
    addSpecification("description", "Imaginative, idealistic, and deeply reflective, the Dreamer is guided "
        "by strong values and a vivid inner world. They are empathetic and open-"
        "minded, often seeking meaning and inspiration in the world around them. "
        "Their creativity and sincerity make them compassionate companions and "
        "thoughtful visionaries.");
    addSpecification("root", "archetype");
}
