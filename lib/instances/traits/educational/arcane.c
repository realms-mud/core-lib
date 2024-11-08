//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "arcane knowledge");
    addSpecification("description", "Those with arcane knowledge have a natural knack for the magical arts.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus evocation", 1);
    addSpecification("bonus transformation", 1);
    addSpecification("bonus destruction", 1);
    addSpecification("bonus manipulation", 1);
    addSpecification("bonus divination", 1);
    addSpecification("bonus elemental air", 1);
    addSpecification("bonus elemental earth", 1);
    addSpecification("bonus elemental fire", 1);
    addSpecification("bonus elemental water", 1);
    addSpecification("bonus magical essence", 1);
    addSpecification("bonus mind", 1);
    addSpecification("bonus senses", 1);
    addSpecification("bonus plant", 1);
    addSpecification("bonus animal", 1);
    addSpecification("bonus body", 1);
    addSpecification("bonus spirit", 1);
    addSpecification("bonus blood", 1);
    addSpecification("bonus reading", 2);
    addSpecification("bonus writing", 2);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus astronomy", 1);
    addSpecification("cost", 2);
}
