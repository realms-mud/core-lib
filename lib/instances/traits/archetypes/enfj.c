//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Protagonist");
    addSpecification("description", "Charismatic, inspiring, and deeply empathetic, "
        "the Protagonist is a natural leader who motivates others toward a common goal. "
        "They are driven by a desire to help and unite people, often acting as a catalyst "
        "for positive change. Their enthusiasm and strong sense of morality make them "
        "trusted allies and champions of their community.");
    addSpecification("root", "archetype");
}
