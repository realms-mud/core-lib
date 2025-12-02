//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Thinker");
    addSpecification("description", "Analytical, inventive, and independent, the Thinker is driven by a "
        "desire to understand complex systems and uncover hidden truths. They are "
        "curious and logical, often approaching problems with creativity and an "
        "open mind. Their objectivity and thirst for knowledge make them skilled "
        "at solving puzzles and generating new ideas.");
    addSpecification("root", "archetype");
}
