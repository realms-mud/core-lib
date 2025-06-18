//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Virtuoso");
    addSpecification("description", "Practical, observant, and resourceful, the Virtuoso excels at "
        "understanding how things work and enjoys hands-on problem solving. They "
        "are independent and adaptable, thriving in situations that require quick "
        "thinking and skillful action. Their curiosity and calm under pressure make "
        "them natural troubleshooters and adventurers.");
    addSpecification("root", "archetype");
}
