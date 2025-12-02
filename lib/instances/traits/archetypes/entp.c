//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Visionary");
    addSpecification("description", "Inventive, quick-witted, and intellectually curious, "
        "the Visionary thrives on exploring new ideas and challenging conventions. "
        "They are skilled at seeing possibilities where others see obstacles, "
        "and their enthusiasm for debate and innovation often inspires those around them. "
        "Adaptable and energetic, they enjoy solving complex problems and sparking change.");
    addSpecification("root", "archetype");
}
