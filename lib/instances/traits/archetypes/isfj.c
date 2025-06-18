//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Guardian");
    addSpecification("description", "Loyal, nurturing, and meticulous, the Guardian is dedicated to the "
        "well-being of others. They are dependable and attentive, often going out "
        "of their way to provide support and maintain harmony. Their kindness and "
        "sense of responsibility make them pillars of their community.");
    addSpecification("root", "archetype");
}
