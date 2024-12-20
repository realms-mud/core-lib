//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "magically barren");
    addSpecification("description", "Those with arcane knowledge have a natural knack for the magical arts. You, on the other hand, have none.");
    addSpecification("root", "uneducated");
    addSpecification("opposing root", "educated");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -25);
    addSpecification("penalty to spellcraft", 2);
    addSpecification("penalty to evocation", 1);
    addSpecification("penalty to transformation", 1);
    addSpecification("penalty to destruction", 1);
    addSpecification("penalty to manipulation", 1);
    addSpecification("penalty to divination", 1);
    addSpecification("penalty to elemental air", 1);
    addSpecification("penalty to elemental earth", 1);
    addSpecification("penalty to elemental fire", 1);
    addSpecification("penalty to elemental water", 1);
    addSpecification("penalty to magical essence", 1);
    addSpecification("penalty to mind", 1);
    addSpecification("penalty to senses", 1);
    addSpecification("penalty to plant", 1);
    addSpecification("penalty to animal", 1);
    addSpecification("penalty to body", 1);
    addSpecification("penalty to spirit", 1);
    addSpecification("penalty to blood", 1);
    addSpecification("cost", -2);
}
