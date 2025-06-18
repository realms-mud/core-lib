//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "the Adventurer");
    addSpecification("description", "Gentle, adaptable, and quietly creative, the Adventurer is attuned to "
        "the beauty of the world and values personal freedom. They are sensitive and "
        "open-minded, often expressing themselves through art or action. Their "
        "spontaneity and warmth make them compassionate companions and explorers.");
    addSpecification("root", "archetype");
}
